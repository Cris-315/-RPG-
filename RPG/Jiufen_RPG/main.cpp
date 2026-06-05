#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Hero.h"
#include "Monster.h"
#include "NPC.h"
using namespace std;

void showStatus(Hero& hero, Monster& boss) {
    cout << "STATUS UPDATE" << endl;

    cout << "Hero HP     : " << hero.getHP() << "/"<< hero.getMaxHP()<< endl;
    cout << "Hero MP     : " << hero.getMP() << endl;
    cout << "Potions     : " << hero.getPotion() << endl;
    cout << "Monster HP  : " << boss.getHP() << "/" << boss.getMaxHP() << endl;
}

int main() {
    srand(time(0));

    Hero hero("Hero", 100, 30);
    Monster boss("Monster", 80);
    NPC npc("Teacher");

    int round = 1;
    int noAttackCount = 0;
    // INTRO 
    cout << "=====================================" << endl;
    cout << "        RPG GAME" << endl;
    cout << "=====================================" << endl;
    cout << "INITIAL STATUS" << endl;

    showStatus(hero, boss);
    cout << "-------------------------------------" << endl;

    while (hero.isAlive() && boss.isAlive()) {
        cout << "=====================================" << endl;
        cout << "ROUND " << round << endl;
        cout << "=====================================" << endl;

        // NPC 
        int chance = rand() % 100;
        if (hero.getHP() < hero.getMaxHP() / 2 && round % 2 == 0 && chance < 30){
            cout << "*** TEACHER APPEARS ***" << endl;
            npc.askQuestion(hero, boss);
            cout << endl;
            cout << "AFTER TEACHER EVENT" << endl;
            showStatus(hero, boss);
        }

        // HERO 
        int choice;
        int dmg = 0;
        cout << "HERO TURN" << endl;
        cout << "1.Attack 2.Heal 3.Potion" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1){
            dmg = hero.attack();
            noAttackCount = 0;
        }
        else if (choice == 2){
            hero.heal();
            noAttackCount++;
            showStatus(hero, boss);
        }
        else if (choice == 3){
            hero.drinkPotion();
            noAttackCount++;
            showStatus(hero, boss);
        }
        else{
            cout << "Wrong choice! You lose your turn!" << endl;
            noAttackCount++;
        }
        if (noAttackCount >= 2){
            cout << endl;
            cout << "Two turns without attacking!" << endl;
            boss.healMonster();
            noAttackCount = 0;
        }
        if (dmg > 0) {
            boss.takeDamage(dmg);
        }

        if (!boss.isAlive()){
            cout << boss.getName() << " has been defeated!" << endl;
            break;
        }

        // MONSTER
        cout << "MONSTER TURN" << endl;

        int bossDmg;
        if (rand() % 100 < 40) {
            bossDmg = boss.specialSkill();
        }
        else {
            bossDmg = boss.attack();
        }
        hero.takeDamage(bossDmg);

        // STATUS
        showStatus(hero, boss);
        round++;
    }

    cout << "=====================================" << endl;
    cout << "GAME OVER" << endl;

    if (hero.isAlive()) {
        cout << "YOU WIN" << endl;
    }
    else {
        cout << "YOU LOSE" << endl;
    }
    return 0;
}