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

Commander *currentCmdr;

void cmdrLevelUp(Commander *currentCmdr, int player){
    cout << "Player " << player << ", you leveled up your commander!\n";
    currentCmdr->cmdrLVL++;
    currentCmdr->cmdrHP *= 1.2 * currentCmdr->cmdrLVL + 1;
    currentCmdr->cmdrMHP *= 1.2 * currentCmdr->cmdrLVL + 1;
    currentCmdr->cmdrDEF *= 1.2 * currentCmdr->cmdrLVL + 1;
    currentCmdr->cmdrMDEF *= 1.2 * currentCmdr->cmdrLVL + 1;
    currentCmdr->cmdrATK *= 1.1 * currentCmdr->cmdrLVL + 1;
    currentCmdr->cmdrMOR *= 1.05 * currentCmdr->cmdrLVL + 1;
}

void cmdrLVLRedirect(int player){
    (player == 1) ? cmdrLevelUp(&cmdr1, player) : cmdrLevelUp(&cmdr2, player);
}

void cmdrChoiceList(){
    cout << "1. Attack\n";
    cout << "2. Repair Armor\n";
    cout << "3. Forfeit\n";
}

void cmdrStats(Commander *currentCmdr){
    cout << "[Current Commander Stats]\n";
    cout << "\tHP: "     << currentCmdr->cmdrHP  << "/" << currentCmdr->cmdrMHP  << endl;
    cout << "\tDEF: "    << currentCmdr->cmdrDEF << "/" << currentCmdr->cmdrMDEF << endl;
    cout << "\tATK: "    << currentCmdr->cmdrATK << endl;
    cout << "\tMorale: " << currentCmdr->cmdrMOR << endl;
}

//One Fight Cycle 
void cmdrFight(Commander *currentCmdr, Commander *opposingCmdr){
    int choice = 0;

    if (currentCmdr->cmdrDEF < 0){
        currentCmdr->cmdrDEF = 0;
    }
    
    cmdrStats(currentCmdr);
    cmdrChoiceList();
    std::cin >> choice;

    switch (choice){
        case 1:
            cout << "This commander takes a swift strike at his opponent!\n";

            if (rand()%20 + 1 < 20){
                cout << "He hits!\n";
                if (currentCmdr->cmdrDEF > 0){
                    currentCmdr->cmdrDEF -= opposingCmdr->cmdrATK;
                }
                else if (currentCmdr->cmdrDEF <= 0){
                    currentCmdr->cmdrHP -= opposingCmdr->cmdrATK;
                }
                
            }
            else {
                cout << "He misses!\n";
            }
        break;

        case 2:
            if (cmdr1.cmdrDEF < cmdr1.cmdrMDEF){
                cout << "This commander repairs his armor!\n'";
                currentCmdr->cmdrDEF += (rand()%3 + 1) * currentCmdr->cmdrLVL;
            }
            else if (cmdr1.cmdrDEF >= cmdr1.cmdrMDEF){
                cout << "Armor already at max!";
                currentCmdr->cmdrDEF = currentCmdr->cmdrMDEF;
            }
        break;

        case 3:
            cout << "This commander forfeits this skirmish!\n";
            currentCmdr->cmdrHP = 0;
        break;
    }
}

//Entire Fight Loop
string cmdrBattle(){
    cout << "A fight between both commanders ensues!\n\n";
    
    while (cmdr1.cmdrHP > 0 || cmdr2.cmdrHP > 0){    
        cout << "Player 1, it's your move. What do you wish to do?\n";
        cmdrFight(&cmdr1, &cmdr2);

        if (cmdr1.cmdrHP <= 0){
            cout << "Player 1's commander has fallen!\n\n";
            return "p2win";
            break;
        }

        cout << "Player 2, it's your move. What do you wish to do?\n";
        cmdrFight(&cmdr2, &cmdr1);

        if (cmdr2.cmdrHP <= 0){
            cout << "Player 2's commander has fallen!\n\n";
            return "p1win";
            break;
        }
    }
}
