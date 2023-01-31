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
        string pOneName;
        string pTwoName;
        //int = Player Number
        int territoryCount(int);
        int armyCount(int);
        int returnMoney(int);
        //char = Tech Tree
        int pOneTechLevel(char);
        int pTwoTechLevel(char);
};

//Implementation Section
Country::Country(){ 
    //Public
    expandTerritory(0);
    upgradeTechnology(0, ' ');
    battleInitiation(0, 0);
    pass(0);
    
    //Private
    pOneName = "";
    pTwoName = "";
    territoryCount(0);
    armyCount(0);
    pOneTechLevel(0);
    pTwoTechLevel(0);
    returnMoney(0);
}