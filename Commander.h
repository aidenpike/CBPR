#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

//All Commander stats and functions
//Declaration Section
class Commander {
    public:
        Commander();        
        void cmdrBattle();
        void cmdrLevelUp(int);
        int returnCmdrStats(int,int);
        void cmdrStats(int);
    private:
        //Player One Commander Stats
        int pOneCmdrLVL; //Level
        int pOneCmdrATK; //Attack
        int pOneCmdrDEF; //Defense (Damage taken before health)
        int pOneCmdrMDEF; //Max Defense
        int pOneCmdrHP; //Health 
        int pOneCmdrMHP; //Max Health
        int pOneCmdrMOR; //Morale (Boosts battle chances)

        //Player Two Commander Stats
        int pTwoCmdrLVL;
        int pTwoCmdrATK;
        int pTwoCmdrDEF;
        int pTwoCmdrMDEF;
        int pTwoCmdrHP;
        int pTwoCmdrMHP; 
        int pTwoCmdrMOR;
};

//Implementation Section
Commander::Commander(){
    //Public
    returnCmdrStats(0, 0);
    cmdrLevelUp(0);
    
    //Private
    //Player One Commander Stats
    pOneCmdrLVL = 1; 
    pOneCmdrATK = 2;
    pOneCmdrDEF = 5;
    pOneCmdrMDEF = 5;
    pOneCmdrHP = 10;
    pOneCmdrMHP = 10;
    pOneCmdrMOR = 3;

    //Player Two Commander Stats
    pTwoCmdrLVL = 1; 
    pTwoCmdrATK = 2;
    pTwoCmdrDEF = 5;
    pTwoCmdrMDEF = 5;
    pTwoCmdrHP = 10;
    pTwoCmdrMHP = 10;
    pTwoCmdrMOR = 3;
}

int Commander::returnCmdrStats(int player, int stat){
    /*
    1: Level
    2: Attack
    3: Defense
    4: HP
    5: Max HP
    6: Morale
    7: Level Cost
    8: Max Defense
    */

    if (player == 1){
        switch (stat){
            case 1: 
                return pOneCmdrLVL;
            break;

            case 2: 
                return pOneCmdrATK;
            break;

            case 3: 
                return pOneCmdrDEF;
            break;

            case 4:
                return pOneCmdrHP;
            break;

            case 5:
                return pOneCmdrMHP;
            break;

            case 6:
                return pOneCmdrMOR;
            break;
    
            case 7:
                return 4 * pow(pOneCmdrLVL,3)/5;
            break;

            case 8:
                return pOneCmdrMDEF;
            break;
        } 
    }
    else if (player == 2){
        switch (stat){
            case 1: 
                return pTwoCmdrLVL;
            break;

            case 2: 
                return pTwoCmdrATK;
            break;

            case 3: 
                return pTwoCmdrDEF;
            break;

            case 4:
                return pTwoCmdrHP;
            break;

            case 5:
                return pTwoCmdrMHP;
            break;

            case 6:
                return pTwoCmdrMOR;
            break;
    
            case 7:
                return 4 * pow(pTwoCmdrLVL,3)/5;
            break;

            case 8:
                return pTwoCmdrMDEF;
            break;
        }
    }
}

void cmdrChoiceList(){
    cout << "1. Attack\n";
    cout << "2. Repair Armor\n";
    cout << "3. Forfeit\n";
}

void Commander::cmdrBattle(){
    srand(int(time(0)));
    
    int choice = 0;
    int coin = rand()%2 + 1;
    
    cout << "A duel between both players' commanders ensues!\n\n";

    while (pOneCmdrHP > 0 || pTwoCmdrHP > 0){
        if (coin == 1){
            cout << "Player 1, it's your move!\n";
            cmdrChoiceList();
            std::cin >> choice;

            switch (choice){
                case 1: 
                    cout << "Player 1's commander takes a swift strike at his opponent!\n";
    
                    if (rand()%20 + 1 < 10){
                        cout << "He hits!\n";
                        (pTwoCmdrDEF > 0) ? pTwoCmdrDEF -= pOneCmdrATK : pTwoCmdrHP -= pOneCmdrATK;
                    }
                    else {
                        cout << "He misses!\n";
                    }
                break;
    
                case 2: 
                    if (pOneCmdrDEF < pOneCmdrMDEF){
cout << "Player 1's commander repairs his armor!\n'"; 
                        pOneCmdrDEF += (rand()%3 + 1) * pOneCmdrLVL;
                    }
                    else if (pOneCmdrDEF >= pOneCmdrMDEF){
                        cout << "Armor already at max!";
                        pOneCmdrDEF = pOneCmdrMDEF;
                    }
                break;
    
                case 3: 
                    cout << "Player 1's commander forfeits this skirmish!\n";
                    pOneCmdrHP = 0;
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
                        (pOneCmdrDEF > 0) ? pOneCmdrDEF -= pTwoCmdrATK : pOneCmdrHP -= pTwoCmdrATK;
                    }
                    else {
                        cout << "He misses!\n";
                    }
                break;
    
                case 2: 
                    if (pTwoCmdrDEF < pTwoCmdrMDEF){
cout << "Player 2's commander repairs his armor!\n'"; 
                        pTwoCmdrDEF += (rand()%3 + 1) * pTwoCmdrLVL;
                    }
                    else if (pTwoCmdrDEF >= pTwoCmdrMDEF){
                        cout << "Armor already at max!";
                        pTwoCmdrDEF = pTwoCmdrMDEF;
                    }
                break;
    
                case 3: 
                    cout << "Player 2's commander forfeits this skirmish!\n";
                    pTwoCmdrHP = 0;
                break;
            }  
        }
    }
}

void Commander::cmdrStats(int player){
    if (player == 1){
        cout << "[Player One Commander]\n";
        cout << "\tCommander HP: "     << pOneCmdrHP  << "/" << pOneCmdrMHP << endl; 
        cout << "\tCommander DEF: "    << pOneCmdrDEF << "/" << pOneCmdrMDEF     << endl;
        cout << "\tCommander ATK: "    << pOneCmdrATK << endl;
        cout << "\tCommander Morale: " << pOneCmdrMOR << endl;
    }
    else if (player == 2){
        cout << "[Player Two Commander]\n";
        cout << "\tCommander HP: "     << pTwoCmdrHP  << "/" << pTwoCmdrMHP << endl; 
        cout << "\tCommander DEF: "    << pTwoCmdrDEF << "/" << pTwoCmdrMDEF << endl;
        cout << "\tCommander ATK: "    << pTwoCmdrATK << endl;
        cout << "\tCommander Morale: " << pTwoCmdrMOR << endl;
    }
}

void Commander::cmdrLevelUp(int player){
    if (player == 1){ 
        cout << "Player 1, you leveled up your commander!\n"; 
        pOneCmdrLVL++; 
        pOneCmdrHP *= 1.5 * pOneCmdrLVL;
        pOneCmdrMHP *= 1.5 * pOneCmdrLVL;
        pOneCmdrDEF *= 1.5 * pOneCmdrLVL;
        pOneCmdrMDEF *= 1.5 * pOneCmdrLVL;
        pOneCmdrATK *= 1.3 * pOneCmdrLVL;
        pOneCmdrMOR *= 1.1 * pOneCmdrLVL;
    }
    else if (player == 2){
        cout << "Player 2, you leveled up your commander!\n";
        pTwoCmdrLVL++;
        pTwoCmdrHP *= 1.5 * pTwoCmdrLVL;
        pTwoCmdrMHP *= 1.5 * pTwoCmdrLVL;
        pTwoCmdrDEF *= 1.5 * pTwoCmdrLVL;
        pTwoCmdrMDEF *= 1.5 * pTwoCmdrLVL;
        pTwoCmdrATK *= 1.3 * pTwoCmdrLVL;
        pTwoCmdrMOR *= 1.1 * pTwoCmdrLVL;
    }
}
