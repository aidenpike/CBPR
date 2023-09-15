#include <iostream> 
#include "game_logic.hpp"


int main(){
    game_logic game_logic;
    bool repeater = false;
    
    game_logic.assign_stats();
    game_logic.name_entry();

    //Begin game loop
    while (game_logic.victor_status() == "continue"){
        game_logic.check_non_zeroes();
        game_logic.stat_rundown();
        game_logic.passive_income();

        do {
            switch (game_logic.turn_choice()){
                case 1: 
                    game_logic.expand_territory();
                break;
    
                case 2: 
                    game_logic.upgrade_technology();
                break;
    
                case 3: 
                    game_logic.recruit_army();
                break;
    
                case 4: 
                    game_logic.battle_initiation();
                break;
    
                default:
                    std::cout << "Invalid input! Try again...";
                    repeater = true;
                break;
            }
        } while (repeater);

        game_logic.turn_counter_update();
    }
}