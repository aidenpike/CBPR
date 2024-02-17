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
        m_money += value;
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
        o_country.alter_money(m_passive_income);
    }

    int Technology::get_army_skill(){
        return m_army_skill;
    }
    int Technology::get_passive_income(){
        return m_passive_income;
    }

}; //namespace cbpr