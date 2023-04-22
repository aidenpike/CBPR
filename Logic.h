#ifndef CBPR_LOGIC_H
#define CBPR_LOGIC_H


class Logic {
    public:
        class Player {
        public:
            Player();
            static void retrieveNames(std::string, std::string);

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
};


#endif //CBPR_LOGIC_H
