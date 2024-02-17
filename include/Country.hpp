#ifndef COUNTRY_HPP
#define COUNTRY_HPP
#include <iostream>

namespace cbpr {
    class Country {
        public:  
            //Constructor, Behaviors
            Country(); //Default Constructor
            Country(std::string, int, int, int); //Name, Money, Territories, Armies

            void alter_money(int);
            void increment_territories();
            void increment_armies();
            int return_random_int(int, int);
            void initiate_attack();
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
            
            void increment_army_skill();
            void increment_passive_income();
            void apply_passive_income();
        private:
            //Attributes
            int m_army_skill;
            int m_passive_income;
    };
    class Commander : public Country {
        public:
            //Constructor, Behaviors
            Commander(int, int, int); //Health, Defense, Attack

            //Need to figure out how to compare 2 attacks. Will likely compare 2 rolls from return_random_number().
            void alter_health(int);
    };
    
}; //namespace cbpr
#endif //COUNTRY_HPP