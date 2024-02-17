#include "../include/Country.hpp"
#include <iostream>
#include <random>

namespace cbpr {
    /*
    -----COUNTRY-----
    */
    Country::Country(){}
    Country::Country(std::string name, int money, int territories, int armies){
        m_name = name;
        m_money = money;
        m_territories = territories;
        m_armies = armies;
    }

    void Country::alter_money(int value){
        m_money += value;
    }
    bool Country::check_if_enough(int){
        if
    }
    void Country::increment_territories(){
        m_territories++;
        alter_money(-10'000);
    }
    void Country::increment_armies(){
        m_armies++;
        alter_money(-8'000);
    }
    int Country::return_random_int(int minimum, int maximum){
        std::random_device seed;  
        std::mt19937 generation(seed()); //This is the only one I know about 
        std::uniform_int_distribution<> random_int(minimum, maximum);

        return random_int(generation);
    }
    void Country::initiate_attack(){

    }   

    int Country::get_money(){
        return m_money;
    }
    int Country::get_territories(){
        return m_territories;
    } 
    int Country::get_armies(){
        return m_armies;
    }

    /*
    -----TECHNOLOGY-----
    */
    Technology::Technology(int army_skill, int passive_income){
        m_army_skill = army_skill;
        m_passive_income = passive_income;
    }

    void Technology::increment_army_skill(Country &o_country){
        m_army_skill++;
        o_country.alter_money(-1'000 - (10 * m_army_skill));
    }
    void Technology::increment_passive_income(Country &o_country){
        m_passive_income++;
        o_country.alter_money(-3'000 - (10 * m_passive_income));
    }
    void Technology::apply_passive_income(Country &o_country){
        o_country.alter_money(10 * m_passive_income);
    }

    int Technology::get_army_skill(){
        return m_army_skill;
    }
    int Technology::get_passive_income(){
        return m_passive_income;
    }

    /*
    -----COMMANDER-----
    */
    //Commander stuff...

    /*
    -----INTERFACE-----
    */
    void Interface::list_stats(Country &o_country, Technology &o_technology){
        std::cout << "$" << o_country.get_money() << "\n";
        std::cout << o_country.get_territories() << "Territories\n";
        std::cout << o_country.get_armies() << " Armies\n";
        std::cout << "----------\n";
        std::cout << "Level " << o_technology.get_army_skill() << " Army Skill\n";
        std::cout << "Level " << o_technology.get_passive_income() << "Passive Income (+$" << 10 * o_technology.get_passive_income() << ") per turn"; 
    }
    void Interface::list_choices(){
        std::cout << "[A] Expand\n";
        std::cout << "[B] Upgrade Tech\n";
        std::cout << "[C] Recruit\n";
        std::cout << "[D] Attack\n";
    }
    char Interface::get_choice(){
        char choice;

        std::cin >> choice;

        return choice;
    }
}; //namespace cbpr