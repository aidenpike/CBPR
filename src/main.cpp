#include <iostream> 
#include "../include/Country.hpp"

std::string get_name();


int main(){
    //Default Values
    int default_money = 50'000;
    int default_territories = 5;
    int default_armies = 2;
    int default_tech_level = 1;
    
    cbpr::Country o_player_one(get_name(), default_money, default_territories, default_armies);
    cbpr::Technology o_player_one_tech(default_tech_level, default_tech_level);
    cbpr::Country o_player_two(get_name(), default_money, default_territories, default_armies);
    cbpr::Technology o_player_two_tech(default_tech_level, default_tech_level);
    
    std::make_pair(o_player_one, o_player_two);
    std::make_pair(o_player_one_tech, o_player_two_tech);

    std::cout << "fard";
    return 0;    
}

std::string get_name(){
    std::string name;
    
    std::cout << "Enter your name: ";
    std::cin >> name;

    return name;
}