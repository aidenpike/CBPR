#ifndef COUNTRY_HPP
#define COUNTRY_HPP
#include <iostream>

namespace cbpr {
    class Country {
        public:  
            //Constructor, Behaviors
            Country(); //Default Constructor
            Country(std::string, int, int, int); //Name, Money, Territories, Armies

            void alter_money(int); //Adds or subtracts the int value from m_money
            bool check_if_enough(int); //Compares m_money to int value and compares if m_money > int value or not
            void increment_territories(); //Increments m_territories
            void increment_armies(); //Increments m_armies
            int return_random_int(int, int); //Produces a random number between 2 provided ranges inclusive
            void initiate_attack(); //Not sure yet

            //Getters
            int get_money(); //Returns m_money of given object
            int get_territories(); //Returns m_territories of given object
            int get_armies(); //Returns m_armies of given object
        private:
            std::string m_name; 
            int m_money;
            int m_territories;
            int m_armies;
    };
    class Technology : public Country {
        public:
            //Constructor, Behaviors
            Technology(int, int); //Army Skill, Passive Income
            
            void increment_army_skill(Country &); //Increments m_army_skill
            void increment_passive_income(Country &); //Increments m_passive_income
            void apply_passive_income(Country &); //Adds money based on 10x the level of m_passive_income when called

            //Getters
            int get_army_skill(); //Returns m_army_skill of given object
            int get_passive_income(); //Returns m_passive_income of given object
        private:
            //Attributes
            int m_army_skill;
            int m_passive_income;
    };
    class Commander : public Country {
        public:
            //Constructor, Behaviors
            Commander(int, int, int); //Health, Defense, Attack

            void initiate_commander_attack(); //Not sure yet
            void alter_health(int); //Adds or subtracts the int value from m_commander_health
        private:
            int m_commander_health;
            int m_commander_defense;
            int m_commander_attack;
    };
    class Interface : public Country {
        public:
            void list_stats(Country &, Technology &); //Lists all stats based on the given objects
            void list_choices(); //Lists all game choices
            char get_choice(); //Gets and returns the current player's choice
            void interpret_choice(char, Country &, Technology &); //Runs the proper function based on get_choice()
    };
}; //namespace cbpr
#endif //COUNTRY_HPP