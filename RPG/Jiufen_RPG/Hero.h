#pragma once
#include "Character.h"

class Hero : public Character {
private:
    int mp;
    int potion;

public:
    Hero(string name, int hp, int mp);
    int attack() override;
    void heal();
    void drinkPotion();
    int getMP() const;
    int getPotion() const;
};