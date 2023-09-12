#include <iostream> 
#include "game_logic.hpp"

int main(){
    game_logic game_logic;
    player_stats player_stats;

    player_stats.assign_values();
    game_logic.stat_rundown();
    
}