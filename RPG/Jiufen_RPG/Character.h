#pragma once
#include <string>
using namespace std;

// Lớp cha 
class Character {
protected:
    string name;
    int hp;
    int maxHP;

public:
    Character(string characterName, int characterHP);
    // Hàm ảo → đa hình
    virtual int attack() = 0;
    void takeDamage(int damage);
    bool isAlive() const;
    string getName() const;
    int getHP() const;
    int getMaxHP() const;
};