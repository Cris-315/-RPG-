#include "Character.h"
#include <iostream>
using namespace std;

Character::Character(string characterName, int characterHP) {
    name = characterName;
    hp = characterHP;
    maxHP = characterHP;
}
void Character::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
    cout << name << " takes " << damage << " damage" << endl;
}
bool Character::isAlive() const {
    return hp > 0;
}
string Character::getName() const {
    return name;
}
int Character::getHP() const {
    return hp;
}
int Character::getMaxHP() const {
    return maxHP;
}