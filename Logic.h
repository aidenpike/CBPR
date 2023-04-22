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

        //Logic Functions
        //Player
        Logic(std::string, size_t, size_t, size_t);
        static void retrieveNames(std::string, std::string);

        Player playerOne, playerTwo;

        //PlayerTech
        Logic(size_t, size_t, size_t, size_t);

};


#endif //CBPR_LOGIC_H
