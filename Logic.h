#include <iostream>
#include "player_stats.hpp"

#ifndef CBPR_GAME_LOGIC_HPP
#define CBPR_GAME_LOGIC_HPP

class game_logic {
    public:
        void name_entry();
        void stat_rundown();
};

//Gets all player names
void game_logic::name_entry() {
    player_stats player_stats;
    size_t player_count = 0;
    std::string player_input = "";

    std::cout << "Enter amount of players: ";
    std::cin >> player_count;
    
    for (int x = 0; x < player_count; x++){
        std::cout << "Player " << x + 1 << ", enter your name: ";
        std::cin >> player_input;
        
        player_stats.names[x] = player_input;
    }
}

//Debug: Lists all stats
void game_logic::stat_rundown(){
    player_stats player_stats;
    std::string stat_type[5] = {"Territories: ", "Armies: ", "Money: $", "Army Skill Level: ", "Passive Income Level: "};
    
    player_stats.assign_values();
    
    for (int x = 0; x < 2; x++){
        std::cout << "Player " << x + 1 << "'s stats\n";
        for (int y = 0; y < 5; y++){
            std::cout << stat_type[y];
            std::cout << player_stats.stat_table[x][y] << "\n";
        }
        std::cout << "\n";
    }
}

#endif //CBPR_GAME_LOGIC_CPP