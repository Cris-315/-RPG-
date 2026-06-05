#pragma once
#include "Character.h"

class Monster : public Character {
public:
    Monster(string name, int hp);
    int attack() override;
    int specialSkill();
    void healMonster();
};