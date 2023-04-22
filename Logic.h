#include <iostream>

#ifndef CBPR_LOGIC_H
#define CBPR_LOGIC_H

class Logic {
    public:
        class Player {
        public:
            Player();

            class PlayerTech {
                PlayerTech();

                size_t playerArmySkillLevel;
                size_t playerArmyEnduranceLevel;
                size_t playerWeaponComplexityLevel;
                size_t playerPassiveIncomeLevel;
            };
        private:
            std::string playerName;
            size_t playerTerritories;
            size_t playerArmies;
            size_t playerMoney;
        };
        //Logic constructor for distributing values of Player
        Logic(std::string, size_t, size_t, size_t);
        static void retrieveNames(std::string, std::string);

        Player playerOne, playerTwo;

        //Logic constructor for distributing values of PlayerTech
        Logic(size_t, size_t, size_t, size_t);

        //Logic functions. Does all the math n stuff
        void playerTurn(); //Runs all functions and dependency injects into the proper UI functions
        size_t playerChoice(size_t); //Receives choice from UI and returns it for playerTurn()
        size_t hasLost(); //Checks stats everytime its ran and returns the player number who has lost, or -1 by default
        size_t returnDiceRoll(size_t, size_t); //Uses mersenne twister engine, takes amount of sides and amount of dice then returns sum of dice
};


#endif //CBPR_LOGIC_H
