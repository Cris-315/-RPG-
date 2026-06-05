#include "Hero.h"
#include <iostream>
using namespace std;

Hero::Hero(string name, int hp, int mp)
    : Character(name, hp), mp(mp), potion(3) {
}
int Hero::attack() {
    if (mp >= 10) {
        mp -= 10;
        cout << name << " uses strong attack!" << endl;
        return 20;
    }
    cout << name << " uses weak attack!" << endl;
    return 6;
}
void Hero::heal(){
    hp += 15;
    if (hp > maxHP){
        hp = maxHP;
    }
    mp += 5;
    if (mp > 30){
        mp = 30;
    }
    cout << name << " heals HP and restores MP" << endl;
}
void Hero::drinkPotion() {
    if (potion > 0) {
        hp += 25;
        if (hp > maxHP) {
            hp = maxHP;
        }
        potion--;
        cout << name << " drinks potion" << endl;
        cout << "Potions left: " << potion << endl;
    }
    else {
        cout << "No potions left!" << endl;
    }
}
int Hero::getMP() const {
    return mp;
}
int Hero::getPotion() const {
    return potion;
}