#include <iostream> 

using std::cout;
using std::string;

//All of the stats and functions excluding commander are here
//Declaration Section
class Country {
    public:  
        Country();
        void getNames();
        //First int = Player number
        void expandTerritory(int);
        void upgradeTechnology(int, char);
        void battleInitiation(int, int); //Second int is for battle outcome choice
        void pass(int);
    private:
        //Player One Stats
        string pOneName;
        int pOneTerritories;
        int pOneArmies;
        int pOneArmySkill;
        int pOneArmyEndurance;
        int pOneWeaponComplexity;
        int pOnePassiveIncome;
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
        //Player Two Commander Stats
        int pTwoCmdrDmg;
        int pTwoCmdrDef;
        int pTwoCmdrHP;
};

//Implementation Section
Country::Country(){ 
    //Public
    //Private
        //Player One Stats
        pOneName = "";
        pOneTerritories = 0;
        pOneArmies = 0;
        pOneArmySkill = 0;
        pOneArmyEndurance = 0;
        pOneWeaponComplexity = 0;
        pOnePassiveIncome = 0; 
        //Player One Commander Stats
        pOneCmdrDmg = 5;
        pOneCmdrDef = 1;
        pOneCmdrHP = 10;

        //Player Two Stats
        pTwoName = "";
        pTwoTerritories = 0;
        pTwoArmies = 0;
        pTwoArmySkill = 0;
        pTwoArmyEndurance = 0;
        pTwoWeaponComplexity = 0;
        pTwoPassiveIncome = 0; 
        //Player Two Commander Stats
        pTwoCmdrDmg = 5;
        pTwoCmdrDef = 1;
        pTwoCmdrHP = 10;
}

void expandTerritory(int player){

}

void upgradeTechnology(int player, char techBranch){
    
}

void battleInitiation(int player){
    
}

void pass(int player){
    
}
