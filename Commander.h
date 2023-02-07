#include <iostream>

//All Commander stats and functions
//Declaration Section
class Commander {
    public:
        Commander();        
        void cmdrBattle();
        int returnCmdrStats(int);
    private:
        //Player One Commander Stats
        int pOneCmdrLVL; //Level
        int pOneCmdrATK; //Attack
        int pOneCmdrDEF; //Defense (Damage taken before health)
        int pOneCmdrHP; //Health 
        int pOneCmdrMOR; //Morale (Boosts battle chances)

        //Player Two Commander Stats
        int pTwoCmdrLVL;
        int pTwoCmdrATK;
        int pTwoCmdrDEF;
        int pTwoCmdrHP;
        int pTwoCmdrMOR;
};

//Implementation Section
Commander::Commander(){
    //Public
    int returnCmdrStats(0);
    
    //Private
    //Player One Commander Stats
    int pOneCmdrLVL = 0; 
    int pOneCmdrATK = 0;
    int pOneCmdrDEF = 0;
    int pOneCmdrHP = 0;
    int pOneCmdrMOR = 0;

    //Player Two Commander Stats
    int pTwoCmdrLVL = 0; 
    int pTwoCmdrATK = 0;
    int pTwoCmdrDEF = 0;
    int pTwoCmdrHP = 0;
    int pTwoCmdrMOR = 0;
}
