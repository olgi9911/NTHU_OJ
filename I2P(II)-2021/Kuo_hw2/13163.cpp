#include <iostream>
#include <string>
//#include "function.h"
#include "13163.h"
using namespace std;

int tanoshiCount, median;

KuoYangPresent::KuoYangPresent(int k){
	this -> sz = 0;
	this -> k = k;
	this -> head = this -> mid = this -> tail = nullptr;
}

void KuoYangPresent::Push(int x){
	Node *node = new Node;
	node -> val = x;
	node -> tag = tanoshiCount;
	node -> next = node -> prev = nullptr;
	if(sz == 0){
		tail = NULL;
		head = tail = node;
	}
	else{
		node -> prev = tail;
		tail -> next = node;
		tail = tail -> next;
	}
	sz++;
}

void KuoYangPresent::Pop(){
	if(sz == 0) return;
	int newMid = (sz + 1) / 2;
	if(mid == NULL) {
		mid = head;
		for(int i = 1; i < newMid; i++)
			mid = mid -> next;
	}
	else{
		for(int i = median; i < newMid; i++)
			mid = mid -> next;
	}
	median = newMid;
	Node *curr = mid;
	if(sz % 2){
		mid = mid -> prev;
		median--;
	}else{
		mid = mid -> next;
	}
	if(curr -> prev != NULL) curr -> prev -> next = curr -> next;
	if(curr -> next != NULL) curr -> next -> prev = curr -> prev;
	delete(curr);
	sz--;
}

void KuoYangPresent::ProgrammingTanoshi(){
	tanoshiCount ++;
}

void KuoYangPresent::KuoYangTeTe(){
	Node *tmp = head;
	while(tmp != NULL){
		if(tmp -> tag < tanoshiCount)
			(tmp -> val) %= k;
		tmp = tmp -> next;
	}
}

void KuoYangPresent::PrintList(){
	Node *tmp = head;
	while(tmp != NULL){
		cout << tmp -> val << " ";
		tmp = tmp -> next;
	}
	cout << endl;
}

int n, k, q;

int main() {
	cin >> n >> k >> q;
	KuoYangPresent present = KuoYangPresent(k);
	for (int i = 1; i <= n; ++ i) {
		int x;
		cin >> x;
		present.Push(x);
	}
	while (q--) {
		string op;
		cin >> op;
		if (op == "push") {
			int x;
			cin >> x;
			present.Push(x);
		}
		else if (op == "pop") {
			present.Pop();
		}
		else {
			cin >> op;
			present.ProgrammingTanoshi();
		}
	}
	present.KuoYangTeTe();
	present.PrintList();
}
