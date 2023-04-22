#include <iostream>
#include "Country.h"

using namespace std;

int main(){
    Player *currentPlayer;

    getNames(&p1);
    getNames(&p2);

    while (true) {
        //Player One Turn
        playerTurn(&p1);

        //Player Two Turn
        playerTurn(&p2);
    }
}