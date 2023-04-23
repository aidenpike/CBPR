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
        Logic(size_t, size_t, size_t);
        //Retrieve names method for putting into Logic constructor
        static std::string retrieveNames(){
            std::string name;

            std::cout << "Player, enter your name: ";
            std::cin >> name;

            return name;
        }

        Player playerOne, playerTwo;

        //Logic constructor for distributing values of PlayerTech
        Logic(size_t, size_t, size_t, size_t);

        //Logic copies of player vars
        std::string name;
        size_t territories;
        size_t armies;
        size_t money;

        //Logic functions. Does all the math n stuff
        void playerTurn(); //Runs all functions and dependency injects into the proper UI functions
        size_t playerChoice(size_t); //Receives choice from UI and returns it for playerTurn()
        size_t hasLost(); //Checks stats everytime its ran and returns the player number who has lost, or -1 by default
        size_t returnDiceRoll(size_t, size_t); //Uses mersenne twister engine, takes amount of sides and amount of dice then returns sum of dice
};

Logic::Player::Player(){
    this->playerName = retrieveNames() + retrieveNames();
    this->playerTerritories = 2;
    this->playerArmies = 10;
    this->playerMoney = 50'000;

    Logic(playerTerritories, playerArmies, playerMoney);
}

Logic::Player::PlayerTech::PlayerTech(){
    this->playerArmyEnduranceLevel = 1;
    this->playerArmySkillLevel = 1;
    this->playerPassiveIncomeLevel = 1;
    this->playerWeaponComplexityLevel = 1;
}
Logic::Logic(size_t territories, size_t armies, size_t money){
    this->territories = 2;
    this->armies = 10;
    this->money = 50'000;
}
#endif //CBPR_LOGIC_H
