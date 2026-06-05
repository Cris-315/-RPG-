#include "NPC.h"
#include <iostream>
#include <cstdlib>
using namespace std;

NPC::NPC(string npcName)
{
    name = npcName;

    question.push_back("What is OOP?");
    a.push_back("Only One Program");
    b.push_back("Object Oriented Programming");
    c.push_back("Open Output Process");
    d.push_back("Other Option");
    answer.push_back(2);

    question.push_back("What is inheritance?");
    a.push_back("Reuse class");
    b.push_back("Delete class");
    c.push_back("Run program");
    d.push_back("Stop program");
    answer.push_back(1);

    question.push_back("What is vector?");
    a.push_back("Class only");
    b.push_back("Loop");
    c.push_back("Function");
    d.push_back("Array list");
    answer.push_back(4);
}

void NPC::askQuestion(Hero& hero, Monster& boss){
    int idx = rand() % question.size();
    int choice;

    cout << endl;
    cout << "[" << name << "] appears!" << endl;
    cout << question[idx] << endl;

    cout << "1. " << a[idx] << endl;
    cout << "2. " << b[idx] << endl;
    cout << "3. " << c[idx] << endl;
    cout << "4. " << d[idx] << endl;

    cout << "Your answer: ";
    cin >> choice;

    if (choice == answer[idx]) {
        cout << "Correct! Hero Heal HP" << endl;
        hero.heal();
    }
    else {
        cout << "Wrong!Monster recovers HP" << endl;
        boss.healMonster();
    }
}