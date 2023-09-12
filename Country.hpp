#ifndef CBPR_PLAYER_STATS_HPP
#define CBPR_PLAYER_STATS_HPP
#include <iostream>

class player_stats {
    public:
        player_stats(); //Setter
        //Maybe vector later?? 2 players for now
        int stat_table[2][5];
        std::string names[2];
        int return_values(int);
        void assign_values();
        void test_output();

    private:
        //More stats to come, I just need to get this functional and clean first
        int territory_count;
        int army_count;
        int money;

        //Tech Levels
        int army_skill_level;
        int passive_income_level;
};
//Setter
player_stats::player_stats(){
    territory_count = 2;
    army_count = 5;
    money = 50'000;
    army_skill_level = 0;
    passive_income_level = 0;    
}

void player_stats::assign_values(){
    int base_stat_table[5] = {territory_count, army_count, money, army_skill_level, passive_income_level};
    
    for (int x = 0; x < 2; x++){
        for (int y = 0; y < 5; y++){
            stat_table[x][y] = base_stat_table[y];
        }
    }    
}

void player_stats::test_output(){

}

#endif //CBPR_PLAYER_STATS_HPP