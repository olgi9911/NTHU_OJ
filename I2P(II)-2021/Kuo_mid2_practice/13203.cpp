#include <cstring>
#include <iostream>
#include <sstream>
//#include "function.h"
#include "13203.h"
using namespace std;
//
Human::Human(string n, int m, int ski) {
    name = n;
    money = m;
    skill = ski;
    kicked = false;
    cards = 0;
    bets = 0;
}
int Human::get_money() {
    return money;
}
Human::~Human() {}

Banker::Banker(int ski) : Human("Banker", 0, ski) {
    this->skill = ski;
}
int pay = 0;
void Banker::Pay(Human *human) {
    if (human->name == "Guard") {
        human->money += 100;
        this->money -= 100;
    } else {  // Pays player
        int bonus = 0;
        if (human->skill < this->skill) {
            bonus = 10 * human->cards;
        }
        if (human->cards == 21) {
            pay = 2 * (human->bets + bonus);
        } else {
            pay = human->bets + bonus;
        }

        this->money -= pay;
        human->money += pay;
    }
}
int Banker::Win(Human *human) {
    if (human->cards > 21 && this->cards > 21) {
        return 2;
    } else if (human->cards <= 21 && (human->cards > this->cards || this->cards > 21)) {
        return 0;  // Player wins
    } else {
        return 1;  // Player loses
    }
}
void Banker::Draw() {
    this->cards = 0;
    string card_string;
    getline(cin, card_string);
    istringstream input_stream;
    input_stream.str(card_string);
    int card = 0;
    while (input_stream >> card) {
        cards += card;
    }
}
//Banker::~Banker() {}

Guard::Guard(int ski) : Human("Guard", 0, ski) {
    this->skill = ski;
}
void Guard::Pay(Human *human) {
    int pay = human->skill - this->skill;
    this->money -= pay;
    human->money += pay;
}
void Guard::Kick(Human *human, int flag) {
    if (flag && human->skill > this->skill) {  // player cheated
        this->Pay(human);
    }
    human->kicked = true;
}

Player::Player(string name, int m, int ski) : Human(name, m, ski) {
    this->name = name;
    this->money = money;
    this->skill = skill;
}
void Player::Pay(Human *human) {
    if (bets >= money) {
        human->money += money;
        money = 0;
    } else {
        human->money += bets;
        money -= bets;
    }
}
void Player::Bet() {
    cin >> name >> bets;
}
void Player::Draw() {
    this->cards = 0;
    int card;
    string card_string;
    cin.ignore();  // '\n' from previous line
    getline(cin, card_string);
    istringstream input_stream;  // for reading string with spaces e.g. "5 10 4"
    input_stream.str(card_string);
    while (input_stream >> card) {
        cards += card;
    }
}
bool Player::Kicked() {
    return kicked;
}
bool Player::Bankrupt() {
    return (money <= 0 ? true : false);
}
bool Player::Cheat(Human *human) {
    return (2 * skill < pay ? true : false);
}
//Player::~Player() {}
//
signed main() {
    int guard_skill, banker_skill;
    cin >> guard_skill >> banker_skill;
    Human *guard = new Guard(guard_skill);
    Human *banker = new Banker(banker_skill);

    Human *player[1009];
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string name;
        int player_money, player_skill;
        cin >> name >> player_money >> player_skill;
        player[i] = new Player(name, player_money, player_skill);
    }

    int k;
    cin >> k;
    while (k--) {
        for (int i = 1; i <= n; ++i) {
            player[i]->Bet();
            player[i]->Draw();
        }
        banker->Draw();

        for (int i = 1; i <= n; ++i) {
            if (player[i]->Kicked())
                continue;

            if (banker->Win(player[i]) == 1) {
                player[i]->Pay(banker);
                if (player[i]->Bankrupt()) {
                    banker->Pay(guard);
                    guard->Kick(player[i], 0);
                }
            } else if (banker->Win(player[i]) == 0) {
                banker->Pay(player[i]);
                if (player[i]->Cheat(banker)) {
                    banker->Pay(guard);
                    guard->Kick(player[i], 1);
                }
            }  // otherwise draw
        }
    }

    cout << guard->get_money() << " " << banker->get_money() << endl;
    for (int i = 1; i <= n; ++i)
        cout << player[i]->name << " " << player[i]->get_money() << endl;
}
