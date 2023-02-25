#include <iostream> 
#include <ctime>
#include "Commander.h"

using std::cout;
using std::string;
using std::cin;
using std::endl;

struct Player {
    string name = "";
    int territories = 1;
    int armies = 10;
    int armySkill = 0;
    int armyEndurance = 0;
    int weaponComplexity = 0;
    int passiveIncome = 0; 
    int money = 50000;
    bool weaponFailure = false;
} p1, p2;

Player *currentPlayer;

//Rolls, chances, and lists
//Dice Roll
int battleRoll(int dice){
    srand(int(time(0)));
    
    switch (dice){
        case 4:
            return rand()%4 + 1;
        break;

        case 6:
            return rand()%6 + 1;
        break;

        case 8:
            return rand()%8 + 1;
        break;

        case 10:
            return rand()%10 + 1;
        break;

        case 12:
            return rand()%12 + 1;
        break;

        case 20:
            return rand()%20 + 1;
        break;
    }
    return 0;
}

void getNames(Player *currentPlayer){
    cout << "Player, enter your name: ";
    getline(cin, currentPlayer->name);
}

//Tech List
void techList(){
    cout << "[A] Army Skill\n";
    cout << "[B] Army Endurance\n";
    cout << "[C] Weapon Upgrade\n";
    cout << "[D] Level Up Commander\n";
    cout << "[H] Passive Income\n";
}

//Stat List
void listStats(Player *currentPlayer){
    cout << "It is currently " << currentPlayer->name << "'s turn. Here are their stats:\n";
    cout << "\t      "         << currentPlayer->territories              << " Territories\n";
    cout << "\t      "         << currentPlayer->armies                   << " Armies\n";
    cout << "\tLevel "         << currentPlayer->armySkill                << " Army Skill\n";
    cout << "\tLevel "         << currentPlayer->armyEndurance            << " Army Endurance\n";
    cout << "\tLevel "         << currentPlayer->weaponComplexity         << " Weapon Complexity\n";
    cout << "\t      "         << currentPlayer->passiveIncome * 50 + 100 << " Dollars in passive income\n";
    cout << "\t      "         << currentPlayer->money                    << " Dollars\n\n\n";
}

void weaponFailure(Player *currentPlayer){
    if (battleRoll(20) <= 5 + 1 * currentPlayer->weaponComplexity - .5 * currentPlayer->armySkill){
        cout << currentPlayer->name << ", your weapons failed during battle!\n";
        switch (rand()%3+1){
            case 1: 
                cout << currentPlayer->name << " loses this battle, and flees!\n";
                currentPlayer->armies--;
                currentPlayer->money -=  rand()%1000 + 500;
                currentPlayer->weaponFailure = true;
            break;

            case 2: 
                cout << currentPlayer->name << ", you escape by a thread!\n";
                currentPlayer->money -= rand()%1000 + 500;
                currentPlayer->weaponFailure = true;
            break;

            case 3:
                cout << currentPlayer->name << ", the battle was immensely devastating.\n";
                currentPlayer->money -= rand()%2000 + 1300;
                currentPlayer->armies -= 2;
                currentPlayer->weaponComplexity--;
                currentPlayer->weaponFailure = true;
        }
    }
}

void expandTerritory(Player * currentPlayer){
    int territoryPrice = 10000;

    if (currentPlayer->money >= territoryPrice){
            currentPlayer->money -= territoryPrice;
            currentPlayer->territories++;
        }
        else {
            cout << "You don't have enough money!\n\n";
        }
}

//Actual function for tech choices
void Country::upgradeTechnology(int player, char techBranch){
    int techPrice = 8000;
    
    if (player == 1 && pOneMoney >= techPrice){
        cout << "Which technology would you like to upgrade?\n";
        techList();
        cin >> techBranch;
    
        techBranch = toupper(techBranch);
        
        switch (techBranch){
            //Army Skill
            case 'A':
                cout << "After a long day, your armies' training is done. It pays off and their skill gains one level!\n\n";
                pOneArmySkill++;
                pOneMoney -= techPrice + (800 * pOneArmySkill);
            break;

            //Army Endurance
            case 'B':
                cout << "Your armies train hard, focusing more towards their endurance. Their endurance gains one level!\n\n";
                pOneArmyEndurance++;
                pOneMoney -= techPrice + (1000 * pOneArmyEndurance);
            break;

            //Weapon Complexity
            case 'C': 
                cout << "Using your ingenius military scientists, you manage to develop a newer, more complex weapon. Your weapon complexity level increases!\n\n";
                pOneWeaponComplexity++;
                pOneMoney -= 2000 + techPrice + (1000 * pOneWeaponComplexity);
            break;

            //Commander Purchase. Will work on this later
            case 'D':
                if (pOneMoney >= cmdr.returnCmdrStats(player, 7)){
                    cmdr.cmdrLevelUp(player);
                    pOneMoney -= cmdr.returnCmdrStats(player, 7);
                }
                else if (pOneMoney < cmdr.returnCmdrStats(player, 7)){
                    cout << "Not enough money to level up your commander!\n";
                }  
            break; 

            case 'H':
                if (pOnePassiveIncome <= pOneTerritories){
                    cout << "You add more mines to your territories.\n\n";
                    pOnePassiveIncome++;
                    pOneMoney -= techPrice + (800 * pOnePassiveIncome);
                }
                else if (pOnePassiveIncome > pOneTerritories){
                    cout << "Not enough territories to add mines to!\n\n";
                    pOnePassiveIncome = pOneTerritories;
                }
        }
    }
    else if (player == 1 && pOneMoney < 8000)
        cout << "Not enough money to upgrade a technology!\n";
    else if (player == 2 && pTwoMoney >= techPrice){
        cout << "Which technology would you like to upgrade?\n";
        techList();
        cin >> techBranch;
    
        techBranch = toupper(techBranch);
        
        switch (techBranch){
            //Army Skill
            case 'A':
                cout << "After a long day, your armies' training is done. It pays off and their skill gains one level!\n\n";
                pTwoArmySkill++;
                pTwoMoney -= techPrice + (800 * pTwoArmySkill);;
            break;

            //Army Endurance
            case 'B':
                cout << "Your armies train hard, focusing more towards their endurance. Their endurance gains one level!\n\n";
                pTwoArmyEndurance++;
                pTwoMoney -= techPrice + (1000 * pTwoArmyEndurance);
            break;

            //Weapon Complexity
            case 'C': 
                cout << "Using your ingenius military scientists, you manage to develop a newer, more complex weapon. Your weapon complexity level increases!\n\n";
                pTwoWeaponComplexity++;
                pTwoMoney -= 2000 + techPrice + (1000 * pTwoWeaponComplexity);
            break;

            //Commander Purchase/Level Up
            case 'D':
                if (pTwoMoney >= cmdr.returnCmdrStats(player, 7)){
                    cmdr.cmdrLevelUp(player);
                    pTwoMoney -= cmdr.returnCmdrStats(player, 7);
                }
                else if (pTwoMoney < cmdr.returnCmdrStats(player, 7)){
                    cout << "Not enough money to level up your commander!\n";
                }
            break; 

            case 'H':
                if (pTwoPassiveIncome <= pTwoTerritories){
                    cout << "You add more mines to your territories.\n\n";
                    pTwoPassiveIncome++;
                    pTwoMoney -= techPrice + (800 * pTwoPassiveIncome);
                }
                else if (pTwoPassiveIncome > pTwoTerritories){
                    cout << "Not enough territories to add mines to!\n\n";
                    pTwoPassiveIncome = pTwoTerritories;
                }
        }
    }
    else if (player == 2 && pTwoMoney < 8000)
        cout << "Not enough money to upgrade a technology!\n";
}

//Recruit one army
void Country::recruitArmy(int player){
    int armyPrice = 8000;

    if (player == 1 && pOneMoney >= 8000){
        cout << "A new army is hired.\n";
        pOneArmies++;
        pOneMoney -= armyPrice;
    } 
    else if (player == 1 && pOneMoney < 8000)
        cout << "Not enough money to recruit another army!\n";
    
    if (player == 2 && pTwoMoney >= 8000){
        cout << "A new army is hired.\n";
        pTwoArmies++;
        pTwoMoney -= armyPrice;
    } 
    else if (player == 1 && pTwoMoney < 8000)
        cout << "Not enough money to recruit another army!\n";
}

//Initiate attack
void Country::battleInitiation(int player){
    int totals;

    if (player == 1){
        switch (outcomeChoice){
            //Devastate
            case 1: 
                weaponFailure();
                //I am so sorry for this formatting
                if (battleRoll(8)  + battleRoll(8) + (pOneArmySkill * 2) + (pOneWeaponComplexity * 3) + pOneArmies + cmdr.returnCmdrStats(1, 6) >= battleRoll(8) + battleRoll(8) + (pTwoArmySkill * 2) + (pTwoWeaponComplexity * 3) + .5 * pTwoArmies + cmdr.returnCmdrStats(2, 6) || pTwoWeaponFailure){
                    if ((cmdr.returnCmdrStats(1, 1) > 0 && cmdr.returnCmdrStats(2, 1) > 0) && battleRoll(20) >= 0){
                        while (cmdr.returnCmdrStats(1,4) > 0 || cmdr.returnCmdrStats(2, 4) > 0){
                            cmdr.cmdrBattle();   
                        }                        
                    }
                    if (pOneWeaponFailure){
                        cout << returnName(player) << " failed to devastate " << returnName(2) << "!\n\n";
                    }
                    else {
                        cout << returnName(player) << " has devastated this territory.\n\n";
                        pTwoTerritories--;
                        pTwoMoney -= rand()%750 + 500;
                    }
                }
                else
                   cout << returnName(player) << " failed to devastate " << returnName(2) << "!\n\n";
                    
            break;
            //Conquer
            case 2:
                weaponFailure();
                if (battleRoll(8)  + battleRoll(8) + (pOneArmySkill * 2) + (pOneWeaponComplexity * 3) + pOneArmies + cmdr.returnCmdrStats(1, 6) >= battleRoll(8) + battleRoll(8) + (pTwoArmySkill * 2) + (pTwoWeaponComplexity * 3) + .5 * pTwoArmies + cmdr.returnCmdrStats(2, 6) || pTwoWeaponFailure){
                    if ((cmdr.returnCmdrStats(1, 1) > 0 && cmdr.returnCmdrStats(2, 1) > 0) && battleRoll(20) >= 10){
                            cmdr.cmdrBattle();                        
                    }
                    if (pOneWeaponFailure){
                        cout << returnName(player) << " failed to conquer " << returnName(2) << "!\n\n";
                    }
                    else {
                        cout << returnName(player) << " has conquered this territory.\n\n";
                        int x = rand()%500 + 250;
                    
                        pOneTerritories++;
                        pTwoTerritories--;
                        pOneMoney += x;
                        pTwoMoney -= x;
                    }
                }
                else {
                    cout << returnName(player) << " failed to conquer " << returnName(2) << "!\n\n";
                }
            break;
        }
    }
    else if (player == 2){
        switch (outcomeChoice){
            //Devastate
            case 1: 
                weaponFailure();
                if (battleRoll(8)  + battleRoll(8) + (pOneArmySkill * 2) + (pOneWeaponComplexity * 3) + pOneArmies + cmdr.returnCmdrStats(1, 6) <= battleRoll(8) + battleRoll(8) + (pTwoArmySkill * 2) + (pTwoWeaponComplexity * 3) + .5 * pTwoArmies + cmdr.returnCmdrStats(2, 6) || pOneWeaponFailure){
                        if ((cmdr.returnCmdrStats(1, 1) > 0 && cmdr.returnCmdrStats(2, 1) > 0) && battleRoll(20) >= 10){
                            cout << "A duel between both players' commanders ensues!\n\n";
                            
                            do {
                                cmdr.cmdrBattle();   
                            } while (cmdr.returnCmdrStats(1,4) > 0 || cmdr.returnCmdrStats(2, 4) > 0);
                        }
                        if (pTwoWeaponFailure){
                            cout << returnName(player) << " failed to devastate " << returnName(1) << "!\n\n";
                        }
                        else {
                            cout << returnName(player) << " has devastated this territory.\n\n";
                            pOneTerritories--;
                            pOneMoney -= rand()%750 + 500;
                        }
                }
                else {
                   cout << returnName(player) << " failed to devastate " << returnName(2) << "!\n\n";
                }    
            break;
            //Conquer
            case 2:
                weaponFailure();
                if (battleRoll(8)  + battleRoll(8) + (pOneArmySkill * 2) + (pOneWeaponComplexity * 3) + pOneArmies + cmdr.returnCmdrStats(1, 6) <= battleRoll(8) + battleRoll(8) + (pTwoArmySkill * 2) + (pTwoWeaponComplexity * 3) + .5 * pTwoArmies + cmdr.returnCmdrStats(2, 6) || pOneWeaponFailure){
                    if ((cmdr.returnCmdrStats(1, 1) > 0 && cmdr.returnCmdrStats(2, 1) > 0) && battleRoll(20) >= 10){
                            cmdr.cmdrBattle();                        
                    }
                    if (pTwoWeaponFailure){
                        cout << returnName(player) << " failed to conquer " << returnName(2) << "!\n\n";
                    }
                    else {
                        cout << returnName(player) << " has conquered this territory.\n\n";
                        int x = rand()%500 + 250;
                    
                        pTwoTerritories++;
                        pOneTerritories--;
                        pTwoMoney += x;
                        pOneMoney -= x;
                    }
                }
                else
                    cout << returnName(player) << " failed to conquer " << returnName(1) << "!\n\n";
            break;
        }
    }
}

//Check if someone won
bool Country::hasWon(){
    bool check = false;
    
    //Conquer
    if (pOneTerritories <= 0){
        cout << returnName(2) << " has fully conquered " << returnName(1) << "." << std::endl;
        check = true;
        exit(0);
    }
    else if (pTwoTerritories <= 0){
        cout << returnName(1) << " has fully conquered " << returnName(2) << "." << std::endl;
        check = true;
        exit(0);
    }
    else 
        check = false;
    
    //Elimination
    if (pOneTerritories <= 0 && pOneArmies <= 0){
        cout << returnName(1) << " has been eliminated.\n";  
        check = true;
        exit(0);
    }
    else if (pTwoTerritories <= 0 && pTwoArmies <= 0){
        cout << returnName(2) << " has been eliminated.\n";  
        check = true;
        exit(0);
    }
    else 
        check = false;

    //Obliteration
    if (pOneTerritories <= 0 && pOneArmies <= 0 && pOneMoney <= 0){
        cout << returnName(1) << " has been obliterated.\n";  
        check = true;
        exit(0);
    }
    else if (pTwoTerritories <= 0 && pTwoArmies <= 0 && pTwoMoney <= 0){
        cout << returnName(2) << " has been obliterated.\n";  
        check = true;
        exit(0);
    }
    else
        check = false;
    //Devastation
    if (pOneMoney <= 0){
        cout << returnName(2) << " has fully devastated " << returnName(1) << std::endl;
        check = true;
        exit(0);
    }
    else if (pTwoMoney <= 0){
        cout << returnName(1) << " has fully devastated " << returnName(2) << std::endl;
        check = true;
        exit(0);
    }
    else
        check = false;
    

    if (check)
        return true;
    else if (!check)
        return false;
}

void Country::playerChoice(int player, int choice){
    switch (choice){
        case 1:
            expandTerritory(player);
        break;
            
        case 2:
            upgradeTechnology(player, ' '); 
        break;

        case 3:
            recruitArmy(player);
        break;

        case 4:
            cout << "What is your goal for battle?\n";
            cout << "1. Devastate\n";
            cout << "2. Conquer\n";
            cin >> outcomeChoice;
            battleInitiation(player);
        break;  
    }
}

string Country::returnName(int player){
    return (player == 1 && player != 2) ? pOneName : pTwoName; 
}

void Country::returnStats(int player){
    if (player == 1){
        cout << "\t      " << pOneTerritories              << " Territories\n";
        cout << "\t      " << pOneArmies                   << " Armies\n";
        cout << "\tLevel " << pOneArmySkill                << " Army Skill\n";
        cout << "\tLevel " << pOneArmyEndurance            << " Army Endurance\n";
        cout << "\tLevel " << pOneWeaponComplexity         << " Weapon Complexity\n";
        cout << "\t      " << pOnePassiveIncome * 50 + 100 << " Dollars in passive income\n";
        cout << "\t      " << pOneMoney                    << " Dollars\n\n\n";
    }
    else if (player == 2){
        cout << "\t      " << pTwoTerritories              << " Territories\n";
        cout << "\t      " << pTwoArmies                   << " Armies\n";
        cout << "\tLevel " << pTwoArmySkill                << " Army Skill\n";
        cout << "\tLevel " << pTwoArmyEndurance            << " Army Endurance\n";
        cout << "\tLevel " << pTwoWeaponComplexity         << " Weapon Complexity\n";
        cout << "\t      " << pTwoPassiveIncome * 50 + 100 << " Dollars in passive income\n";
        cout << "\t      " << pTwoMoney                    << " Dollars\n\n\n";
    }
}

void Country::passiveIncome(int player){
    if (player == 1 && pOnePassiveIncome <= pOneTerritories){
        pOneMoney += 100 + 50 * pOnePassiveIncome;
    }
    else if (player == 2 && pTwoPassiveIncome <= pOneTerritories){
        pTwoMoney += 100 + 50 * pTwoPassiveIncome;
    }
}
