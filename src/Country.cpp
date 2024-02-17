#include "../include/Country.hpp"
#include <iostream>
#include <random>

namespace cbpr {
    Country::Country(){}
    Country::Country(std::string name, int money, int territories, int armies){
        m_name = name;
        m_money = money;
        m_territories = territories;
        m_armies = armies;
    }
    void Country::alter_money(int value){
        m_money -= value;
    }
    void Country::increment_territories(){
        m_territories++;
        alter_money(10'000);
    }
    void Country::increment_armies(){
        m_armies++;
        alter_money(8'000);
    }
    int Country::return_random_int(int minimum, int maximum){
        std::random_device seed;  
        std::mt19937 generation(seed()); //This is the only one I know about 
        std::uniform_int_distribution<> random_int(minimum, maximum);

        return random_int(generation);
    }
    Technology::Technology(int army_skill, int passive_income){
        m_army_skill = army_skill;
        m_passive_income = passive_income;
    }
}; //namespace cbpr