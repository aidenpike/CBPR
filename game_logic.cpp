#ifndef CBPR_GAME_LOGIC_CPP
#define CBPR_GAME_LOGIC_CPP
#include <iostream>
#include <random>
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
extern int turn_counter = 0;


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

//Dice Roll (looking to find a better PRNG later)
int will_of_tyche(){
    int die_100 = 10 + rand() % (100 + 10 - 1);

    return die_100;
}


/*
-----CHOICES-----  
*/
void game_logic::expand_territory(){
    player_stats player_stats;
    
    std::cout << pseudo_names[turn_counter] << " expands their territory! [-10,000]\n"; 
    player_stats_malleable[turn_counter][0] += 1;
    player_stats_malleable[turn_counter][2] -= 10'000;
}

/*
---TECHNOLOGY---
*/
void tech_list(){
    std::string tech_list[2] = {"Army Skill", "Passive Income Level"};
    
    for (int x = 0; x < 2; x++){
        std::cout << "[" << x + 1 << "] ";
        std::cout << tech_list[x]  << "\n";
    }
}
void game_logic::upgrade_technology(){
    int technology_index;
    
    std::cout << pseudo_names[turn_counter] << ", what technology would you like to upgrade?\n";
    tech_list();
    std::cin >> technology_index;

    player_stats_malleable[turn_counter][technology_index + 2] += 1;
    player_stats_malleable[turn_counter][2] -= 8'000 * (.5 * player_stats_malleable[turn_counter][technology_index + 2]);
}

void game_logic::recruit_army(){
    player_stats player_stats;

    if (player_stats_malleable[turn_counter][1] == player_stats_malleable[turn_counter][0]){
        std::cout << pseudo_names[turn_counter] << " recruits another army! [-8,000]\n"; 
        player_stats_malleable[turn_counter][1] += 1;
        player_stats_malleable[turn_counter][2] -= 8'000;
    }
    else if (player_stats_malleable[turn_counter][2] < 8'000){
        std::cout << "Not enough money!\n";
    }
    else {
        std::cout << "Territories must be as much or higher than armies!\n";
    }
}

void game_logic::battle_initiation(){
    player_stats player_stats;
    int player_one_boosts = .3 * player_stats_malleable[0][1] * player_stats_malleable[0][3];
    int player_two_boosts = .3 * player_stats_malleable[1][1] * player_stats_malleable[1][3];
    srand( time(NULL) );
    int player_one_roll = will_of_tyche();
    int player_two_roll = will_of_tyche();
    
    std::cout << "A skirmish commences!\n\n";

    player_one_roll = will_of_tyche();
    player_two_roll = will_of_tyche();
    
    //This will probably be the only time hard numbers for the player index will be used
    if (player_one_roll + player_one_boosts > player_two_roll + player_two_boosts){
        std::cout << player_one_roll << " > " << player_two_roll << "\n"; 
        std::cout << pseudo_names[0] << " wins!\n";
        player_stats_malleable[0][2] += 1'000;
        player_stats_malleable[1][2] -= 1'000;
    } 
    else if (player_one_roll + player_one_boosts < player_two_roll + player_two_boosts){
        std::cout << player_one_roll << " < " << player_two_roll << "\n"; 
        std::cout << pseudo_names[1] << " wins!\n";
        player_stats_malleable[0][2] -= 1'000;
        player_stats_malleable[1][2] += 1'000;
    }
    else if (player_one_roll + player_one_boosts == player_two_roll + player_two_boosts){
        //Might make a recalculation method when it ties
        std::cout << "Tie!\n";
    }

}

#endif //CBPR_GAME_LOGIC_CPP
