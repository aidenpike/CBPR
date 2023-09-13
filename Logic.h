#ifndef CBPR_GAME_LOGIC_CPP
#define CBPR_GAME_LOGIC_CPP
#include <iostream>
#include "player_stats.hpp"

class game_logic {
    public:
        void assign_stats();
        void name_entry();
        void stat_rundown();
        void expand_territory();
        void upgrade_technology();
        void recruit_army();
        void battle_initiation();

    private:
        std::string pseudo_names[2]; //Not a regularly manipulated stat so I put it here
        int player_stats_malleable[2][5];
};

//I promise this will be the only global variable
extern int turn_counter = 1;


/*
-----PREPROCESSED-----
*/
void game_logic::assign_stats(){
    player_stats player_stats; 
    
    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 5; y++){
            player_stats_malleable[x][y] = player_stats.return_values(x, y);
        }
    }
}


/*
-----MISC-----  
*/
//Gets all player names
void game_logic::name_entry() {
    player_stats player_stats;
    size_t player_count = 0;
    std::string player_input = "";

    std::cout << "Enter amount of players: ";
    std::cin >> player_count;

	std::cin.ignore();
    for (int x = 0; x < player_count; x++){
        std::cout << "Player " << x + 1 << ", enter your name: ";
        std::getline(std::cin, pseudo_names[x]);
    }
}

//Lists all stats
void game_logic::stat_rundown(){
    player_stats player_stats;
    std::string stat_type[5] = {"Territories: ", "Armies: ", "Money: $", "Army Skill Level: ", "Passive Income Level: "};
    
    for (int x = 0; x < 2; x++){
        std::cout << "[" << pseudo_names[x] << "'s stats]\n";
        for (int y = 0; y < 5; y++){
            std::cout << stat_type[y];
            std::cout << player_stats_malleable[x][y] << "\n";
        }
        std::cout << "\n";
    }
}


/*
-----CHOICES-----  
*/
void game_logic::expand_territory(){
    player_stats player_stats;
    
    std::cout << pseudo_names[turn_counter] << " expands their territory! [-10,000]\n"; 
    player_stats_malleable[turn_counter][0] += 1;
}


#endif //CBPR_GAME_LOGIC_CPP