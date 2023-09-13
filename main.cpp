#include <iostream> 
#include "game_logic.hpp"

int main(){
    //Maybe have game loop here and run turn counter through parameters
    game_logic game_logic;
    player_stats player_stats;

    game_logic.name_entry();
    game_logic.stat_rundown();
    game_logic.expand_territory();
    game_logic.stat_rundown();
}