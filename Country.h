#include <iostream>
#include <algorithm>
#include <string>
#include "Commander.h"

using std::cout;
using std::string;
using std::cin;
using std::endl;

struct Player {
    string name = " ";
    int territories = 2;
    int armies = 10;
    int armySkill = 0;
    int armyEndurance = 0;
    int weaponComplexity = 0;
    int passiveIncome = 0; 
    int money = 49900;
    bool weaponFailure = false;
    int player = 0;
} p1, p2;

Player *currentPlayer;

//Rolls, chances, and lists
//Dice Roll
int battleRoll(int dice){
    srand(int(time(0)));
    
    return rand()%dice + 1;
}

void getNames(Player *currentPlayer){
    cout << "Player, enter your name: ";
    getline(cin, currentPlayer->name);

    if (currentPlayer->name == "Oasis"){
        cout << "Welcome back, old friend.\n";
        currentPlayer->armySkill += 100;
        currentPlayer->weaponComplexity += 10;
        currentPlayer->passiveIncome += 1000;
        currentPlayer->armies += 100;
    }
}

//Comma Seperation Math (100% not stolen)
string commaSeperate(int num){
    auto src = std::to_string(num);
    auto dest = std::string();
    auto count = 3;
    
    for(auto i = src.crbegin() ; i != src.crend() ; ++i) {
        if (count == 0)
        {
            dest.push_back(',');
            count = 3;
        }
        if (count--) {
            dest.push_back(*i);
        }
    }
    reverse(dest.begin(), dest.end());

    return dest;   
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
    string passiveIncome = commaSeperate(currentPlayer->passiveIncome * 50 + 100);
    string money = commaSeperate(currentPlayer->money);
    
    cout << "It is currently " << currentPlayer->name << "'s turn. Here are their stats:\n";
    cout << "\t      "         << currentPlayer->territories              << " Territories\n";
    cout << "\t      "         << currentPlayer->armies                   << " Armies\n";
    cout << "\tLevel "         << currentPlayer->armySkill                << " Army Skill\n";
    cout << "\tLevel "         << currentPlayer->armyEndurance            << " Army Endurance\n";
    cout << "\tLevel "         << currentPlayer->weaponComplexity         << " Weapon Complexity\n";
    cout << "\t     $"         << passiveIncome                           << " Dollars in passive income\n";
    cout << "\t     $"         << money                                   << " Dollars\n\n\n";
}

//Weapon Failure
void weaponFailure(Player *currentPlayer){
    int weaponFail =  battleRoll(20) + 1 * currentPlayer->weaponComplexity;
    if ((weaponFail - currentPlayer->armySkill) <= 5){
        cout << currentPlayer->name << ", your weapons failed during battle!\n";
        switch (rand()%3 + 1){
            case 1: 
                cout << currentPlayer->name << " loses this battle, and flees!\n";
                
                (battleRoll(10) + currentPlayer->armyEndurance <= 5) ? currentPlayer->armies-- : currentPlayer->armies = currentPlayer->armies;
                
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

                (battleRoll(10) + currentPlayer->armyEndurance <= 10) ? currentPlayer->armies -= 2 : currentPlayer->armies = currentPlayer->armies;
                
                currentPlayer->weaponComplexity--;
                currentPlayer->weaponFailure = true;
        }
    }
}

//Expand territory
void expandTerritory(Player *currentPlayer){
    int territoryPrice = 10000;

    if (currentPlayer->money >= territoryPrice){
            cout << currentPlayer->name << " expanded their territory!\n";
            currentPlayer->money -= territoryPrice;
            currentPlayer->territories++;
        }
    else {
        cout << "You don't have enough money!\n\n";
    }
}

//Actual function for tech choices
void upgradeTechnology(Player *currentPlayer){
    p1.player = 1;
    p2.player = 2;
    
    int techPrice = 8000;
    char techBranch = ' ';
    
    cout << "Which technology would you like to upgrade?\n";
    techList();
    cin >> techBranch;

    techBranch = toupper(techBranch);

    switch (techBranch){
        //Army Skill
        case 'A':
            if (techPrice + (800 * currentPlayer->armySkill) > currentPlayer->money){
                cout << "You don't have enough money!\n\n";
            }
            else {
                cout << "After a long day, your armies' training is done. It pays off an they gain one skill level!\n\n";
                currentPlayer->armySkill++; 
                currentPlayer->money -= techPrice + (800 * currentPlayer->armySkill);
            }
        break;

        case 'B':
            if (techPrice + (1000 * currentPlayer->armyEndurance > currentPlayer->money)){
                cout << "Not enough money!\n\n";
            }
            else {
                cout << "Your armies train hard, focusing more towards their endurance. Their endurance gains on level!\n\n";
                currentPlayer->armyEndurance++;
                currentPlayer->money -= techPrice + (1000 * currentPlayer->armyEndurance);
            }
        break;

        case 'C':
            if (2000 + techPrice + (1000 * currentPlayer->weaponComplexity > currentPlayer->money)){
                cout << "Not enough money!\n\n";
            }
            else {
                cout << "Using your ingenious military scientists, you manage to develop a newer, more complex weapon. Your weapon complexity level increases!\n\n";
                currentPlayer->weaponComplexity++;
                currentPlayer->money -= 2000 + techPrice + (1000 * currentPlayer->weaponComplexity);
            }
        break;

        case 'D':
            if (techPrice + (500 * currentPlayer->returnLevel(currentPlayer->player)) > currentPlayer->money){
                cout << "Not enough money!\n\n";
            }
            else {
                cmdrLVLRedirect(currentPlayer->player);
                currentPlayer->money -= techPrice + (500 * currentPlayer->returnLevel(currentPlayer->player));
            }
        break;

        case 'H':
            if (techPrice + (800 * currentPlayer->passiveIncome) > currentPlayer->money){
                cout << "Not enough money!\n\n";
            }
            else if (currentPlayer->passiveIncome <= currentPlayer->territories){
                cout << "You add more mines to your territories.\n\n";
                currentPlayer->passiveIncome++;
                currentPlayer->money -= techPrice + (800 * currentPlayer->passiveIncome);
            }
            else {
                cout << "Not enough territories to add mines to!\n\n";
                currentPlayer->passiveIncome = currentPlayer->territories;
            }
        }
}

//Recruit an army
void recruitArmy(Player *currentPlayer){
    int armyPrice = 8000;

    if (currentPlayer->money >= armyPrice){
        cout << "A new army is hired.\n\n";
        currentPlayer->armies++;
        currentPlayer->money -= armyPrice;
    }
    else {
        cout << "Not enough money to recruit another army!\n\n";
    }
}

void battleInitiation(){
    int outcomeChoice = 0;
    int pOneATKRoll = battleRoll(8) + battleRoll(8) + p1.armySkill * 2 + p1.weaponComplexity * 3 + p1.armies + cmdr1.cmdrMOR;
    int pTwoATKRoll = battleRoll(8) + battleRoll(8) + p2.armySkill * 2 + p2.weaponComplexity * 3 + p2.armies + cmdr2.cmdrMOR;
    bool cmdrFight = false;


    cout << "What is your goal for battle?\n";
    cout << "1. Devastate\n";
    cout << "2. Conquer\n";
    cin >> outcomeChoice;

    (rand()%2 + 1 == 2) ? cmdrFight = true : cmdrFight = false;

    p1.weaponFailure = false;
    p2.weaponFailure = false;
    
    weaponFailure(&p1);
    weaponFailure(&p2);
    
    switch (outcomeChoice){
        case 1:
            if (p1.weaponFailure && p2.weaponFailure){
                cout << "It's a tie!\n\n";
            
                p1.money -= 5;
                p2.money -= 5;    
                p1.weaponFailure = false;
                p2.weaponFailure = false;
                cmdrFight = false;
            }
            else if (cmdrFight){
                if (cmdrBattle() == "p1win"){
                   cout << p1.name << " has devastated this territory.\n\n";
                    
                    p2.territories--;
                    p2.money -= rand()%750 + 500;
                }
                else {
                    cout << p2.name << " has devastated this territory.\n\n";
                    
                    p1.territories--;
                    p1.money -= rand()%750 + 500;
                }
            }
            else if (pOneATKRoll > pTwoATKRoll || p2.weaponFailure){
                cout << p1.name << " has devastated this territory.\n\n";
                
                p2.territories--;
                p2.money -= rand()%750 + 500;
            }
            else if (pOneATKRoll == pTwoATKRoll){
                cout << "It's a tie!\n\n";
                
                p1.money -= 5;
                p2.money -= 5;
            }
            else if (pOneATKRoll < pTwoATKRoll || p1.weaponFailure){
                cout << p2.name << " has devastated this territory.\n\n";
                
                p1.territories--;
                p1.money -= rand()%750 + 500;
            }
        break;

        case 2:
            if (p1.weaponFailure && p2.weaponFailure){
                cout << "It's a tie!\n\n";
                
                p1.money -= 5;
                p2.money -= 5;
            }
            else if (cmdrFight){
                if (cmdrBattle() == "p1win"){
                    cout << p1.name << " has conquered this territory.\n\n";
                    
                    p1.territories++;
                    p2.territories--;
                    p1.money += rand()%500 + 250;
                    p2.money -= rand()%500 + 250;
                }
                else {
                    
                    cout << p2.name << " has conquered this territory.\n\n";
                   
                    p2.territories++;
                    p1.territories--;
                    p2.money += rand()%500 + 250;
                    p1.money -= rand()%500 + 250;
                }
            }
            else if (pOneATKRoll > pTwoATKRoll || p2.weaponFailure){
                cout << p1.name << " has conquered this territory.\n\n";
                
                p1.territories++;
                p2.territories--;
                p1.money += rand()%500 + 250;
                p2.money -= rand()%500 + 250;
            }
            else if (pOneATKRoll == pTwoATKRoll || (p1.weaponFailure && p2.weaponFailure)){
                cout << "It's a tie!\n\n";
                p1.money -= 5;
                p2.money -= 5;
            }
            else if (pOneATKRoll < pTwoATKRoll || p1.weaponFailure){
                cout << p2.name << " has conquered this territory.\n\n";
               
                p2.territories++;
                p1.territories--;
                p2.money += rand()%500 + 250;
                p1.money -= rand()%500 + 250;
            }
    }

    p1.weaponFailure = false;
    p2.weaponFailure = false;
}

//Lose Check
void hasLost(){
    if (p1.territories <= 0 && p2.territories <= 0){
        cout << "Both empires go down in flames. The war is a tie.\n\n";
        exit(0);
    }
    
    if (p1.money <= 0 && p2.money <= 0){
        cout << "Both empires go down in flames. The war is a tie.\n\n";
        exit(0);
    }

    if (p1.money <= 0){
        cout << p1.name << " has been devastated by " << p2.name << "!\n\n";
        exit(0);
    }
    else if (p1.territories <= 0){
        cout << p1.name << " has been conquered by " << p2.name << "!\n\n";
        exit(0);
    }
    
    if (p2.money <= 0){
        cout << p2.name << " has been devastated by " << p1.name << "!\n\n";
        exit(0);
    }
    else if (p2.territories <= 0){
        cout << p2.name << " has been conquered by " << p1.name << "!\n\n";
        exit(0);
    }
}

void playerTurn(Player *currentPlayer){
    hasLost();
    
    //Passive Income
    currentPlayer->money += 100 + (50 * currentPlayer->passiveIncome);
    //List stats for current player
    listStats(currentPlayer);
    int choice = 0;
    
    cout << "What do you wish to do?" << endl;
    cout << "\t1. Grow Territory ($10000)\n";
    cout << "\t2. Upgrade Technology\n";
    cout << "\t3. Recruit Army ($8000)\n";
    cout << "\t4. Attack\n";
    cout << "\t5. Pass\n\n";

    cin >> choice;
    
    switch (choice){
        case 1:
            expandTerritory(currentPlayer);
        break;
            
        case 2:
            upgradeTechnology(currentPlayer); 
        break;

        case 3:
            recruitArmy(currentPlayer);
        break;

        case 4:            
            battleInitiation();
        break;  
    }
} 
