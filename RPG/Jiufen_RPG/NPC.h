#pragma once
#include <vector>
#include <string>
#include "Hero.h"
#include "Monster.h"

using namespace std;
class NPC {
private:
    string name;
    vector<string> question;
    vector<string> a, b, c, d;
    vector<int> answer;

public:
    NPC(string name);
    void askQuestion(Hero& hero, Monster& boss);
};