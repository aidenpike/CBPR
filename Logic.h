#include <iostream>

#ifndef CBPR_LOGIC_H
#define CBPR_LOGIC_H

class Logic {
    public:
        //Reason for struct: These values are constantly being modified
        struct Player {
            std::string playerName;
            size_t playerTerritories = 2;
            size_t playerArmies = 10;
            size_t playerMoney = 50'000;
            size_t playerArmySkillLevel = 1;
            size_t playerArmyEnduranceLevel = 1;
            size_t playerWeaponComplexityLevel = 1;
            size_t playerPassiveIncomeLevel = 1;
        } playerOne, playerTwo;
        //Logic constructor for distributing values of Player
        Logic(size_t, size_t, size_t);
        //Retrieve names method for putting into Logic constructor
        void retrieveNames(){
            std::string name;

            std::cout << "Player One, enter your name: ";
            std::cin >> name;
            playerOne.playerName = name;

            std::cout << "Player Two, enter your name: ";
            std::cin >> name;
            playerOne.playerName = name;
        }

        //Logic functions. Does all the math n stuff
        void playerTurn(); //Runs all functions and dependency injects into the proper UI functions
        size_t playerChoice(size_t); //Receives choice from UI and returns it for playerTurn()
        size_t hasLost(); //Checks stats everytime its ran and returns the player number who has lost, or -1 by default
        size_t returnDiceRoll(size_t, size_t); //Uses mersenne twister engine, takes amount of sides and amount of dice then returns sum of dice
};

#endif //CBPR_LOGIC_H
