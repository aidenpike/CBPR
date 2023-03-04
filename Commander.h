#include <iostream>

using std::cout;
using std::endl;
using std::string;

struct Commander {
    int cmdrLVL = 1;
    int cmdrATK = 2;
    int cmdrDEF = 5;
    int cmdrMDEF = 5;
    int cmdrHP = 10;
    int cmdrMHP = 10;
    int cmdrMOR = 3;
} cmdr1, cmdr2;

extern string name;
Commander *currentCmdr;

void cmdrChoiceList(){
    cout << "1. Attack\n";
    cout << "2. Repair Armor\n";
    cout << "3. Forfeit\n";
}

void cmdrStats(Commander *currentCmdr){
    cout << "[" << name << "'s Commander]\n";
    cout << "\tHP: "     << currentCmdr->cmdrHP  << "/" << currentCmdr->cmdrMHP  << endl;
    cout << "\tDEF: "    << currentCmdr->cmdrDEF << "/" << currentCmdr->cmdrMDEF << endl;
    cout << "\tATK: "    << currentCmdr->cmdrATK << endl;
    cout << "\tMorale: " << currentCmdr->cmdrMOR << endl;
}

void cmdrBattle(Commander *currentCmdr){
    srand(int(time(0)));

    int choice = 0;
    int coin = rand()%2 + 1;

    while (cmdr1.cmdrHP > 0 || cmdr2.cmdrHP > 0){
        if (coin == 1){
            cout << name << ", it's your move!\n";
            cmdrChoiceList();
            std::cin >> choice;

            switch (choice){
                case 1:
                    cout << "Player 1's commander takes a swift strike at his opponent!\n";

                    if (rand()%20 + 1 < 10){
                        cout << "He hits!\n";
                        (cmdr1.cmdrDEF > 0) ? cmdr2.cmdrDEF -= cmdr1.cmdrATK : cmdr2.cmdrHP -= cmdr1.cmdrATK;
                    }
                    else {
                        cout << "He misses!\n";
                    }
                    break;

                case 2:
                    if (cmdr1.cmdrDEF < cmdr1.cmdrMDEF){
                        cout << "Player 1's commander repairs his armor!\n'";
                        cmdr1.cmdrDEF += (rand()%3 + 1) * cmdr1.cmdrLVL;
                    }
                    else if (cmdr1.cmdrDEF >= cmdr1.cmdrMDEF){
                        cout << "Armor already at max!";
                        cmdr1.cmdrDEF = cmdr1.cmdrMDEF;
                    }
                    break;

                case 3:
                    cout << "Player 1's commander forfeits this skirmish!\n";
                    cmdr1.cmdrHP = 0;
                    break;
            }
        }
        else if (coin == 2){
            cout << "Player 2, it's your move!\n";
            cmdrChoiceList();
            std::cin >> choice;

            switch (choice){
                case 1:
                    cout << "Player 2's commander takes a swift strike at his opponent!\n";

                    if (rand()%20 + 1 < 10){
                        cout << "He hits!\n";
                        (cmdr1.cmdrDEF > 0) ? cmdr1.cmdrDEF -= cmdr2.cmdrATK : cmdr1.cmdrHP -= cmdr2.cmdrATK;
                    }
                    else {
                        cout << "He misses!\n";
                    }
                    break;

                case 2:
                    if (cmdr2.cmdrDEF < cmdr2.cmdrMDEF){
                        cout << "Player 2's commander repairs his armor!\n'";
                        cmdr2.cmdrDEF += (rand()%3 + 1) * cmdr2.cmdrLVL;
                    }
                    else if (cmdr2.cmdrDEF >= cmdr2.cmdrMDEF){
                        cout << "Armor already at max!";
                        cmdr2.cmdrDEF = cmdr2.cmdrMDEF;
                    }
                    break;

                case 3:
                    cout << "Player 2's commander forfeits this skirmish!\n";
                    cmdr2.cmdrHP = 0;
                    break;
            }
        }
    }
}

void cmdrLevelUp(Commander *currentCommander){
    cout << name << ", you leveled up your commander!\n";
    currentCmdr->cmdrLVL++;
    currentCmdr->cmdrHP *= 1.5 * currentCmdr->cmdrLVL + 1;
    currentCmdr->cmdrMHP *= 1.5 * currentCmdr->cmdrLVL + 1;
    currentCmdr->cmdrDEF *= 1.5 * currentCmdr->cmdrLVL + 1;
    currentCmdr->cmdrMDEF *= 1.5 * currentCmdr->cmdrLVL + 1;
    currentCmdr->cmdrATK *= 1.3 * currentCmdr->cmdrLVL + 1;
    currentCmdr->cmdrMOR *= 1.1 * currentCmdr->cmdrLVL + 1;
}