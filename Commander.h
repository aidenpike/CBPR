#include <iostream>
#include <cmath>
#include "Country.h"

using std::cout;

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
        int pOneCmdrHP; //Health 
        int pOneCmdrMHP; //Max Health
        int pOneCmdrMOR; //Morale (Boosts battle chances)

        //Player Two Commander Stats
        int pTwoCmdrLVL;
        int pTwoCmdrATK;
        int pTwoCmdrDEF;
        int pTwoCmdrHP;
        int pTwoCmdrMHP; 
        int pTwoCmdrMOR;
};

Country country;

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
    pOneCmdrHP = 10;
    pOneCmdrMHP = 10;
    pOneCmdrMOR = 3;

    //Player Two Commander Stats
    pTwoCmdrLVL = 1; 
    pTwoCmdrATK = 2;
    pTwoCmdrDEF = 5;
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
        }
    }
}

void Commander::cmdrBattle(){
    
}

void Commander::cmdrStats(int player){
    if (player == 1){
        cout << "[Player One Commander]\n";
        cout << "\tCommander HP: "     << pOneCmdrHP  << "/" << pOneCmdrMHP; 
        cout << "\tCommander DEF: "    << pOneCmdrDEF << std::endl;
        cout << "\tCommander ATK: "    << pOneCmdrATK << std::endl;
        cout << "\tCommander Morale: " << pOneCmdrMOR << std::endl;
    }
    else if (player == 2){
        cout << "[Player Two Commander]\n";
        cout << "\tCommander HP: "     << pTwoCmdrHP  << "/" << pTwoCmdrMHP; 
        cout << "\tCommander DEF: "    << pTwoCmdrDEF << std::endl;
        cout << "\tCommander ATK: "    << pTwoCmdrATK << std::endl;
        cout << "\tCommander Morale: " << pTwoCmdrMOR << std::endl;
    }
}

void Commander::cmdrLevelUp(int player){
    if (player == 1){ 
        cout << country.returnName(player) << ", you leveled up your commander!\n"; 
        pOneCmdrLVL++;    
    }
    else if (player == 2){
        cout << country.returnName(player) << ", you leveled up your commander!\n";
        pTwoCmdrLVL++;
    }
}
