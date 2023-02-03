#include <iostream> 
#include <ctime>

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
        bool hasWon();

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
        //Player One Commander Stats
        int pOneCmdrDmg;
        int pOneCmdrDef;
        int pOneCmdrHP;

        //Player Two Stats
        string pTwoName;
        int pTwoTerritories;
        int pTwoArmies;
        int pTwoArmySkill;
        int pTwoArmyEndurance;
        int pTwoWeaponComplexity;
        int pTwoPassiveIncome;
        int pTwoMoney;
        //Player Two Commander Stats
        int pTwoCmdrDmg;
        int pTwoCmdrDef;
        int pTwoCmdrHP;
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
    
    //Private
        //Player One Stats
        pOneName = "";
        pOneTerritories = 1;
        pOneArmies = 10;
        pOneArmySkill = 1;
        pOneArmyEndurance = 1;
        pOneWeaponComplexity = 1;
        pOnePassiveIncome = 1; 
        pOneMoney = 50000;
        //Player One Commander Stats
        pOneCmdrDmg = 5;
        pOneCmdrDef = 1;
        pOneCmdrHP = 10;

        //Player Two Stats
        pTwoName = "";
        pTwoTerritories = 1;
        pTwoArmies = 10;
        pTwoArmySkill = 1;
        pTwoArmyEndurance = 1;
        pTwoWeaponComplexity = 1;
        pTwoPassiveIncome = 1; 
        pTwoMoney = 50000;
        //Player Two Commander Stats
        pTwoCmdrDmg = 5;
        pTwoCmdrDef = 1;
        pTwoCmdrHP = 10;
}

int outcomeChoice = 0;

void Country::getNames(){
    cout << "Player one, enter your name: ";
    getline(cin, pOneName);
    cout << "Player two, enter your name: ";
    getline(cin, pTwoName);
}

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
                pOneMoney -= techPrice;
            break;

            //Army Endurance
            case 'B':
                cout << "Your armies train hard, focusing more towards their endurance. Their endurance gains one level!\n\n";
                pOneArmyEndurance++;
                pOneMoney -= techPrice;
            break;

            //Weapon Complexity
            case 'C': 
                cout << "Using your ingenius military scientists, you manage to develop a newer, more complex weapon. Your weapon complexity level increases!\n\n";
                pOneWeaponComplexity++;
                pOneMoney -= techPrice;
            break;

            //Commander Purchase. Will work on this later
            case 'D':
                cout << "In the works.\n\n";
            break; 

            case 'H':
                if (pOnePassiveIncome <= pOneTerritories){
                    cout << "You add more mines to your territories.\n\n";
                    pOnePassiveIncome++;
                    pOneMoney -= techPrice;
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
                pTwoMoney -= techPrice;
            break;

            //Army Endurance
            case 'B':
                cout << "Your armies train hard, focusing more towards their endurance. Their endurance gains one level!\n\n";
                pTwoArmyEndurance++;
                pTwoMoney -= techPrice;
            break;

            //Weapon Complexity
            case 'C': 
                cout << "Using your ingenius military scientists, you manage to develop a newer, more complex weapon. Your weapon complexity level increases!\n\n";
                pTwoWeaponComplexity++;
                pTwoMoney -= techPrice;
            break;

            //Commander Purchase. Will work on this later
            case 'D':
                cout << "In the works.\n\n";
            break; 

            case 'H':
                if (pTwoPassiveIncome <= pTwoTerritories){
                    cout << "You add more mines to your territories.\n\n";
                    pTwoPassiveIncome++;
                    pTwoMoney -= techPrice;
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

//Initiate attack
void Country::battleInitiation(int player){
    srand(int(time(0)));
    
    int totals;

    if (player == 1){
        switch (outcomeChoice){
            //Devastate
            case 1: 
                //I am so sorry for this formatting
                if (battleRoll(8)  + battleRoll(8) + (pOneArmySkill * 2) + (pOneWeaponComplexity * 3)/*+ pOneCmdrMorale*/>= battleRoll(8) + battleRoll(8) + (pTwoArmySkill * 2) + (pTwoWeaponComplexity * 3)/*+ pTwoCmdrMorale || weaponFailure(2)*/){
                   cout << returnName(player) << " has devastated this territory.\n\n";
                   pTwoTerritories--;
                   pTwoMoney -= rand()%750 + 500;
                }
                else
                   cout << returnName(player) << " failed to devastate " << returnName(2) << "!\n\n";
                    
            break;
            //Conquer
            case 2:
                if (battleRoll(8)  + battleRoll(8) + (pOneArmySkill * 2) + (pOneWeaponComplexity * 3)/*+ pOneCmdrMorale*/>= battleRoll(8) + battleRoll(8) + (pTwoArmySkill * 2) + (pTwoWeaponComplexity * 3)/*+ pTwoCmdrMorale || weaponFailure(2)*/){
                    cout << returnName(player) << " has conquered this territory.\n\n";
                    
                    int x = rand()%500 + 250;
                    
                    pOneTerritories++;
                    pTwoTerritories--;
                    pOneMoney += x;
                    pTwoMoney -= x;
                }
                else
                    cout << returnName(player) << " failed to conquer " << returnName(2) << "!\n\n";
            break;
        }
    }
    else if (player == 2){
        switch (outcomeChoice){
            //Devastate
            case 1: 
                //I am so sorry for this formatting
                if (battleRoll(8)  + battleRoll(8) + (pOneArmySkill * 2) + (pOneWeaponComplexity * 3)/*+ pOneCmdrMorale*/<= battleRoll(8) + battleRoll(8) + (pTwoArmySkill * 2) + (pTwoWeaponComplexity * 3)/*+ pTwoCmdrMorale || weaponFailure(2)*/){
                   cout << returnName(player) << " has devastated this territory.\n\n";
                   pOneTerritories--;
                   pOneMoney -= rand()%750 + 500;
                }
                else
                   cout << returnName(player) << " failed to devastate " << returnName(1) << "!\n\n";
                    
            break;
            //Conquer
            case 2:
                if (battleRoll(8)  + battleRoll(8) + (pOneArmySkill * 2) + (pOneWeaponComplexity * 3)/*+ pOneCmdrMorale*/<= battleRoll(8) + battleRoll(8) + (pTwoArmySkill * 2) + (pTwoWeaponComplexity * 3)/*+ pTwoCmdrMorale || weaponFailure(2)*/){
                    cout << returnName(player) << " has conquered this territory.\n\n";
                    
                    int x = rand()%500 + 250;
                    
                    pOneTerritories--;
                    pTwoTerritories++;
                    pOneMoney -= x;
                    pTwoMoney += x;
                }
                else
                    cout << returnName(player) << " failed to conquer " << returnName(1) << "!\n\n";
            break;
        }
    }
}

string Country::returnName(int player){
    return (player == 1 && player != 2) ? pOneName : pTwoName; 
}

void Country::returnStats(int player){
    if (player == 1){
        cout << "\t      " << pOneTerritories         << " Territories\n";
        cout << "\t      " << pOneArmies              << " Armies\n";
        cout << "\tLevel " << pOneArmySkill           << " Army Skill\n";
        cout << "\tLevel " << pOneArmyEndurance       << " Army Endurance\n";
        cout << "\tLevel " << pOneWeaponComplexity    << " Weapon Complexity\n";
        cout << "\t      " << pOnePassiveIncome * 100 << " Dollars in passive income\n";
        cout << "\t      " << pOneMoney               << " Dollars\n\n\n";
    }
    else if (player == 2){
        cout << "\t      " << pTwoTerritories         << " Territories\n";
        cout << "\t      " << pTwoArmies              << " Armies\n";
        cout << "\tLevel " << pTwoArmySkill           << " Army Skill\n";
        cout << "\tLevel " << pTwoArmyEndurance       << " Army Endurance\n";
        cout << "\tLevel " << pTwoWeaponComplexity    << " Weapon Complexity\n";
        cout << "\t      " << pTwoPassiveIncome * 100 << " Dollars in passive income\n";
        cout << "\t      " << pTwoMoney               << " Dollars\n\n\n";
    }
}

bool Country::hasWon(){
    bool check = false;
    
    //Conquer
    if (pOneTerritories <= 0){
        cout << returnName(2) << " has fully conquered " << returnName(1) << "." << std::endl;
        return true;
    }
    else if (pTwoTerritories <= 0){
        cout << returnName(1) << " has fully conquered " << returnName(2) << "." << std::endl;
        check = true;
    }
    else 
        check = false;
    
    //Elimination
    if (pOneTerritories <= 0 && pOneArmies <= 0){
        cout << returnName(1) << " has been eliminated.\n";  
        check = true;
    }
    else if (pTwoTerritories <= 0 && pTwoArmies <= 0){
        cout << returnName(2) << " has been eliminated.\n";  
        check = true;
    }
    else 
        check = false;

    //Obliteration
    if (pOneTerritories <= 0 && pOneArmies <= 0 && pOneMoney <= 0){
        cout << returnName(1) << " has been obliterated.\n";  
        check = true;
    }
    else if (pTwoTerritories <= 0 && pTwoArmies <= 0 && pOneMoney <= 0){
        cout << returnName(2) << " has been obliterated.\n";  
        check = true;
    }
    else
        check = false;
    //Devastation
    if (pOneMoney == 0){
        cout << returnName(2) << " has fully devastated " << returnName(1) << std::endl;
        check = true;
    }
    else if (pTwoMoney <= 0){
        cout << returnName(1) << " has fully devastated " << returnName(2) << std::endl;
        check = true;
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
