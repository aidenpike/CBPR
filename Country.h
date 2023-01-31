#include <iostream> 

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
        void battleInitiation(int, int); //Second int is for battle outcome choice
        void pass(int); //Pass your turn
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
    expandTerritory(0);
    upgradeTechnology(0, ' ');
    battleInitiation(0, 0); 
    pass(0);
    
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

void Country::getNames(){
    cout << "Player one, enter your name: ";
    getline(cin, pOneName);
    cout << "Player two, enter your name: ";
    getline(cin, pTwoName);
}

void Country::expandTerritory(int player){

}

void Country::upgradeTechnology(int player, char techBranch){
    
}

void Country::battleInitiation(int player, int outcomeChoice){
    
}

void Country::pass(int player){
    
}
