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

int returnLevel(int player){
    return (player == 1) ? cmdr1.cmdrLVL : cmdr2.cmdrLVL;
}

void cmdrStats(Commander *currentCmdr){
    cout << "[Current Commander Stats]\n";
    cout << "\tHP: "     << currentCmdr->cmdrHP  << "/" << currentCmdr->cmdrMHP  << endl;
    cout << "\tDEF: "    << currentCmdr->cmdrDEF << "/" << currentCmdr->cmdrMDEF << endl;
    cout << "\tATK: "    << currentCmdr->cmdrATK << endl;
    cout << "\tMorale: " << currentCmdr->cmdrMOR << endl;
}

void cmdrResetStats(Commander *currentCmdr){
    currentCmdr->cmdrHP = currentCmdr->cmdrMHP;
    currentCmdr->cmdrDEF = currentCmdr->cmdrMDEF;
}
//One Fight Cycle 
void cmdrFight(Commander *currentCmdr, Commander *opposingCmdr){
    char choice = '0';
    bool loop = true;
    
    if (currentCmdr->cmdrDEF < 0){
        currentCmdr->cmdrDEF = 0;
    }

    while (loop){
        cmdrStats(currentCmdr);
        cmdrChoiceList();
        std::cin >> choice;
    
        switch (choice){
            case '1':
                cout << "This commander takes a swift strike at his opponent!\n";
    
                if (rand()%20 + 1 < 10){
                    cout << "He hits!\n";
                    if (opposingCmdr->cmdrDEF > 0){
                        opposingCmdr->cmdrDEF -= currentCmdr->cmdrATK;
                    }
                    else if (opposingCmdr->cmdrDEF <= 0){
                        opposingCmdr->cmdrHP -= currentCmdr->cmdrATK;
                    }
                    
                }
                else {
                    cout << "He misses!\n";
                }
                loop = false;
            break;
    
            case '2':
                if (currentCmdr->cmdrDEF < currentCmdr->cmdrMDEF){
                    cout << "This commander repairs his armor!\n'";
                    currentCmdr->cmdrDEF += (rand()%3 + 1) * currentCmdr->cmdrLVL;
    
                    if (currentCmdr->cmdrDEF > currentCmdr->cmdrMDEF){
                        currentCmdr->cmdrDEF = currentCmdr->cmdrMDEF;
                    }
                }
                else if (currentCmdr->cmdrDEF >= currentCmdr->cmdrMDEF){
                    cout << "Armor already at max!\n";
                    currentCmdr->cmdrDEF = currentCmdr->cmdrMDEF;
                }
                loop = false;
            break;
    
            case '3':
                cout << "This commander forfeits this skirmish!\n";
                currentCmdr->cmdrHP = 0;
                loop = false;
            break;

            default:
                cout << "Invalid input!\n";
                loop = true;
            break;
        }
    }
}

//Entire Fight Loop
string cmdrBattle(){
    cout << "A fight between both commanders ensues!\n\n";

    cmdrResetStats(&cmdr1);
    cmdrResetStats(&cmdr2);
    
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
