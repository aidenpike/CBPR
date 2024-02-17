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
    
    std::pair<cbpr::Country, cbpr::Country> players = std::make_pair(o_player_one, o_player_two);
    std::pair<cbpr::Technology, cbpr::Technology> technologies = std::make_pair(o_player_one_tech, o_player_two_tech);

    for (int i = 0; i < 10; i++){
         technologies.first.increment_army_skill(players.first);
    }

    std::cout << technologies.first.get_army_skill() << "\n";
    std::cout << players.first.get_money();
    return 0;    
}

std::string get_name(){
    std::string name;
    
    std::cout << "Enter your name: ";
    std::cin >> name;

    return name;
}