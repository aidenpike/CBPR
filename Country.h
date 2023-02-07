#include <iostream> 
#include <ctime>
#include "Commander.h"

using std::cout;
using std::string;
using std::cin;

//All of the stats and functions excluding commander are here
//Declaration Section
class Country {
    public:  
        Country();
        void getNames();
        //First int = Player number
        void expandTerritory(int); //+1 Territory, -10,000 dollars
        void upgradeTechnology(int, char); //Opens up a list of tech branches
        void recruitArmy(int);
        void battleInitiation(int); 
        void returnStats(int); 
        void playerChoice(int, int);
        string returnName(int);
        string battleOutcome(int, bool);
        bool hasWon();
        void passiveIncome(int);
        void weaponFailure();
    
    private:
        //Player One Stats
        string pOneName;
        int pOneTerritories;
        int pOneArmies;
        int pOneArmySkill;
        int pOneArmyEndurance;
        int pOneWeaponComplexity;
        int pOnePassiveIncome;
        int pOneMoney;
        bool pOneWeaponFailure;
        bool pOneCmdrExists;

        //Player Two Stats
        string pTwoName;
        int pTwoTerritories;
        int pTwoArmies;
        int pTwoArmySkill;
        int pTwoArmyEndurance;
        int pTwoWeaponComplexity;
        int pTwoPassiveIncome;
        int pTwoMoney;
        bool pTwoWeaponFailure;
        bool pTwoCmdrExists;
};

//Implementation Section
Country::Country(){ 
    //Public
    returnName(0);
    returnStats(0);
    expandTerritory(0);
    playerChoice(0,0);
    upgradeTechnology(0, ' ');
    recruitArmy(0);
    battleInitiation(0);
    passiveIncome(0);
    
    //Private
        //Player One Stats
        pOneName = "";
        pOneTerritories = 1;
        pOneArmies = 10;
        pOneArmySkill = 0;
        pOneArmyEndurance = 0;
        pOneWeaponComplexity = 0;
        pOnePassiveIncome = 0; 
        pOneMoney = 50000;
        pOneWeaponFailure = false;
        pOneCmdrExists = false;

        //Player Two Stats
        pTwoName = "";
        pTwoTerritories = 1;
        pTwoArmies = 10;
        pTwoArmySkill = 0;
        pTwoArmyEndurance = 0;
        pTwoWeaponComplexity = 0;
        pTwoPassiveIncome = 0; 
        pTwoMoney = 50000;
        pTwoWeaponFailure = false;
        pTwoCmdrExists = false;
}

int outcomeChoice = 0;

void Country::getNames(){
    cout << "Player one, enter your name: ";
    getline(cin, pOneName);
    cout << "Player two, enter your name: ";
    getline(cin, pTwoName);
}


//Rolls, chances, and lists
//Dice Roll
int battleRoll(int dice){
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
}

//Weapon failure chance
void Country::weaponFailure(){
    //Player One
    if (battleRoll(20) <= 5 + 1 * (pOneWeaponComplexity) - .5 * pOneArmySkill){
        cout << returnName(1) << ", your weapons failed during battle!\n";
        switch (rand()%3+1){
            case 1: 
                cout << returnName(1) << " loses this battle, and flees!\n";
                pOneArmies--;
                pOneMoney -=  rand()%1000 + 500;
                pOneWeaponFailure = true;
            break;

            case 2: 
                cout << returnName(1) << ", you escape by a thread!\n";
                pOneMoney -= rand()%1000 + 500;
                pOneWeaponFailure = true;
            break;

            case 3:
                cout << returnName(1) << ", the battle was immensely devastating.\n";
                pOneMoney -= rand()%2000 + 1300;
                pOneArmies -= 2;
                pOneWeaponComplexity--;
                pOneWeaponFailure = true;
        }
    }
    //Player Two
    if (battleRoll(20) <= 5 + 1.5 * (pTwoWeaponComplexity) - .5 * pTwoArmySkill){
        cout << returnName(2) << ", your weapons failed during battle!\n";
        switch (rand()%3+1){
            case 1: 
                cout << returnName(2) << " loses this battle, and flees!\n";
                pTwoArmies--;
                pTwoMoney -=  rand()%1000 + 500;
                pTwoWeaponFailure = true;
            break;

            case 2: 
                cout << returnName(2) << ", you escape by a thread!\n";
                pTwoMoney -= rand()%1000 + 500;
                pTwoWeaponFailure = true;
            break;

            case 3:
                cout << returnName(2) << ", the battle was immensely devastating.\n";
                pTwoMoney -= rand()%2000 + 1300;
                pTwoArmies -= 2;
                pTwoWeaponComplexity--;
                pTwoWeaponFailure = true;
        }
    }
}

//Random battle outcomes (non-player)
string Country::battleOutcome(int player, bool win){
    if (player == 1 && win){
        if (battleRoll(20) + .5 * pOneArmyEndurance < 10){
            cout << returnName(1) << ", despite your win, you lose an army!\n";
            pOneArmies--;
        }
        else if (battleRoll(20) /*+ .5 * commander.pOneCmdrMOR()*/> 15){
            cout << returnName(1) << ", with you wits and strategy, you gain an army from the other side!\n";
            pOneArmies++;
            pTwoArmies--;
        }
        else
            cout << "Normal win\n";
    }
    
}

//List out all of the technologies you can upgrade
void techList(){
    cout << "[A] Army Skill\n";
    cout << "[B] Army Endurance\n";
    cout << "[C] Weapon Upgrade\n";
    cout << "[D] Buy Commander\n";
    cout << "\t[E] Commander Health\n";
    cout << "\t[F] Commander Armor\n";
    cout << "\t[G] Commander Damage\n";
    cout << "[H] Passive Income\n";
}


//Choices 
//Expand your territories 
void Country::expandTerritory(int player){
    int territoryPrice = 10000;
    
    if (player == 1){
        if (pOneMoney >= territoryPrice){
            pOneMoney -= territoryPrice;
            pOneTerritories++;
        }
        else if (pOneMoney < territoryPrice){
            cout << "You don't have enough money!\n\n";
        }
    }
    else if (player == 2) {
        if (pTwoMoney >= territoryPrice){
            pTwoMoney -= territoryPrice;
            pTwoTerritories++;
        }
        else if (pTwoMoney < territoryPrice){
            cout << "You don't have enough money!\n\n";
        }
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
                cout << "In the works.\n\n";
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

            //Commander Purchase. Will work on this later
            case 'D':
                cout << "In the works.\n\n";
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
    srand(int(time(0)));
    
    int totals;

    if (player == 1){
        switch (outcomeChoice){
            //Devastate
            case 1: 
                weaponFailure();
                //I am so sorry for this formatting
                if (battleRoll(8)  + battleRoll(8) + (pOneArmySkill * 2) + (pOneWeaponComplexity * 3) + pOneArmies/*+ pOneCmdrMorale*/<= battleRoll(8) + battleRoll(8) + (pTwoArmySkill * 2) + (pTwoWeaponComplexity * 3) + .5 * pTwoArmies/*+ pTwoCmdrMorale */|| pTwoWeaponFailure){
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
                if (battleRoll(8)  + battleRoll(8) + (pOneArmySkill * 2) + (pOneWeaponComplexity * 3) + pOneArmies/*+ pOneCmdrMorale*/>= battleRoll(8) + battleRoll(8) + (pTwoArmySkill * 2) + (pTwoWeaponComplexity * 3) + .5 * pTwoArmies/*+ pTwoCmdrMorale */|| pTwoWeaponFailure){
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
                if (battleRoll(8)  + battleRoll(8) + (pOneArmySkill * 2) + (pOneWeaponComplexity * 3) + pOneArmies/*+ pOneCmdrMorale*/<= battleRoll(8) + battleRoll(8) + (pTwoArmySkill * 2) + (pTwoWeaponComplexity * 3) + .5 * pTwoArmies/*+ pTwoCmdrMorale */|| pOneWeaponFailure){
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
                if (battleRoll(8)  + battleRoll(8) + (pOneArmySkill * 2) + (pOneWeaponComplexity * 3) + pOneArmies/*+ pOneCmdrMorale*/>= battleRoll(8) + battleRoll(8) + (pTwoArmySkill * 2) + (pTwoWeaponComplexity * 3) + .5 * pTwoArmies/*+ pTwoCmdrMorale */|| pOneWeaponFailure){
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
