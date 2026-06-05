#include "Monster.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Monster::Monster(string name, int hp)
    : Character(name, hp) {
}
int Monster::attack() {
    cout << name << " attacks normally!" << endl;
    return 18;
}
int Monster::specialSkill() {
    cout << name << " uses special skill!" << endl;
    return 25;
}
void Monster::healMonster(){
    hp += 10;
    if (hp > maxHP){
        hp = maxHP;
    }
    cout << name << " is recovering!" << endl;
    cout << "Monster HP: " << hp << endl;
}