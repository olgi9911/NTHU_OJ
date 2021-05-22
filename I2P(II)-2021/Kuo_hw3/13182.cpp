#include <iostream>
#include <string>
#include "13182.h"
//#include "function.h"
using namespace std;

Guest::Guest(){
	name = "";
	money = 0;
	skill = 0;
}
Guest::Guest(string s, int m, int ski){
	name = s;
	money = m;
	skill = ski;
}
Guest::~Guest() = default;

string Guest::get_name(){
	return name;
}
int Guest::get_money(){
	return money;
}
int Guest::get_skill(){
	return skill;
}
void Guest::Win(int m){
	money += m;
}

Casino::Casino(){
	this -> fee = 0;
	this -> guest_num = 0;
	this -> income = 0;
	this -> list_num = 0;
}
Casino::~Casino() = default;

void Casino::Enterance(int f){
	fee = f;
}
void Casino::GuestEnter(string s, int m, int ski){
	for(int i = 0; i < list_num; i++) { //Check blacklist
		if(s == blacklist[i]) return;
	}
	for(int i = 0; i < guest_num; i++){ //Check existence
		if(s == guest[i] -> get_name()) return;
	}
	if(m <= fee){ //Check bankrupt
		income += m;
		blacklist[list_num] = s;
		list_num ++;
	}
	else{
		guest[guest_num] = new Guest(s, m - fee, ski);
		guest_num ++;
		income += fee;
	}
}
void Casino::Win(string s, int m){
	int idx;
	for(int i = 0; i < list_num; i++){
		if(s == blacklist[i]) return;
	}
	for(idx = 0; idx < guest_num; idx++){
		if(s == guest[idx] -> get_name()) break;
	}
	if(idx < guest_num){
		int guest_money = guest[idx] -> get_money();
		if(guest_money + m > 0){
			if(m > guest[idx] -> get_skill() * 2){
				blacklist[list_num] = guest[idx] -> get_name();
				list_num ++;
			}
			else{
				guest[idx] -> Win(m);
			}
			income -= m;
		}
		else{
			blacklist[list_num] = guest[idx] -> get_name();
			income += guest_money;
			list_num ++;
		}
	}
}
void Casino::EndDay(){
	guest_num = 0;
}
void Casino::Result(){
	cout << income << endl;
	for(int i = 0; i < list_num; i++){
		cout << blacklist[i] << endl;
	}
}
//Partial Judge ends
int n;
//Casino casino = {};
Casino casino;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++ i) {
		string op;
		int q, fee;
		
		cin >> op >> q >> fee;
		casino.Enterance(fee);
		for (int j = 0; j < q; ++ j) {
			cin >> op;
			if (op == "Guest") {
				string name; 
				int money, skill;
				cin >> name >> money >> skill;
				casino.GuestEnter(name, money, skill);
			} 
			else if (op == "Win") {
				string name;
				int money;
				cin >> name >> money;
				casino.Win(name, money);
			}
		}
		casino.EndDay();
	}
	casino.Result();
}
