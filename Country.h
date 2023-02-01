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
        void returnStats(int);        
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
    upgradeTechnology(0, ' ');
    battleInitiation(0, 0); 
    pass(0);
    
    //Private
        //Player One Stats
        pOneName = "";
        pOneTerritories = 1;
        pOneArmies = 0;
        pOneArmySkill = 0;
        pOneArmyEndurance = 0;
        pOneWeaponComplexity = 0;
        pOnePassiveIncome = 0; 
        pOneMoney = 0;
        //Player One Commander Stats
        pOneCmdrDmg = 5;
        pOneCmdrDef = 1;
        pOneCmdrHP = 10;

        //Player Two Stats
        pTwoName = "";
        pTwoTerritories = 1;
        pTwoArmies = 0;
        pTwoArmySkill = 0;
        pTwoArmyEndurance = 0;
        pTwoWeaponComplexity = 0;
        pTwoPassiveIncome = 0; 
        pTwoMoney = 0;
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
    if (player == 1){
        
    }
}

void Country::upgradeTechnology(int player, char techBranch){
    
}

void Country::battleInitiation(int player, int outcomeChoice){
    
}

void Country::pass(int player){
    
}

string Country::returnName(int player){
    return (player == 1 && player != 2) ? pOneName : pTwoName; 
}

void Country::returnStats(int player){
    if (player == 1){
        cout << "\t      " << pOneTerritories      << " Territories\n";
        cout << "\t      " << pOneArmies           << " Armies\n";
        cout << "\tLevel " << pOneArmySkill        << " Army Skill\n";
        cout << "\tLevel " << pOneArmyEndurance    << " Army Endurance\n";
        cout << "\tLevel " << pOneWeaponComplexity << " Weapon Complexity\n";
        cout << "\t      " << pOnePassiveIncome    << " Dollars in passive income\n";
        cout << "\t      " << pOneMoney            << " Dollars\n\n\n";
    }
    else if (player == 2){
        cout << "\t      " << pTwoTerritories      << " Territories\n";
        cout << "\t      " << pTwoArmies           << " Armies\n";
        cout << "\tLevel " << pTwoArmySkill        << " Army Skill\n";
        cout << "\tLevel " << pTwoArmyEndurance    << " Army Endurance\n";
        cout << "\tLevel " << pTwoWeaponComplexity << " Weapon Complexity\n";
        cout << "\t      " << pTwoPassiveIncome    << " Dollars in passive income\n";
        cout << "\t      " << pTwoMoney            << " Dollars\n\n\n";
    }
}

bool Country::hasWon(){
    //Conquer
    if (pOneTerritories <= 0){
        cout << returnName(2) << " has fully conquered " << returnName(1);
        return true;
    }
    else if (pTwoTerritories <= 0){
        cout << returnName(1) << " has fully conquered " << returnName(2) << std::endl;
        return true;
    }
    else
        return false;

    //Elimination
    if (pOneTerritories <= 0 && pOneArmies <= 0){
        cout << returnName(1) << " has been eliminated.\n";  
        return true;
    }
    else if (pTwoTerritories <= 0 && pTwoArmies <= 0){
        cout << returnName(2) << " has been eliminated.\n";  
        return true;
    }
    else
        return false;

    //Obliteration
    if (pOneTerritories <= 0 && pOneArmies <= 0 && pOneMoney <= 0){
        cout << returnName(1) << " has been obliterated.\n";  
        return true;
    }
    else if (pTwoTerritories <= 0 && pTwoArmies <= 0 && pOneMoney <= 0){
        cout << returnName(2) << " has been obliterated.\n";  
        return true;
    }
    else
        return false;

    //Devastation
    if (pOneTerritories <= 0){
        cout << returnName(2) << " has devastated " << returnName(1);
        return true;
    }
    else if (pTwoTerritories <= 0){
        cout << returnName(1) << " has devastated " << returnName(2) << std::endl;
    }
    else
        return false;
}
