#include <iostream>
#include "Country.h"

using namespace std;

void choiceList(){
    cout << "\t1. Grow Territory ($10000)\n";
    cout << "\t2. Upgrade Technology\n";
    cout << "\t3. Recruit Army ($8000)\n";
    cout << "\t4. Attack\n";
    cout << "\t5. Pass\n\n";
}

int main() {
    //Object Declaration
    Country country;
    
    //Variables
    int input = 0;
    char techChoice;
    bool hasWon = false;
    
    //Title Screen
    cout << "Welcome to Country Battle Plus: Remastered.\n";
    country.getNames();
    cout << endl;
    
    //Game Loop
    while (!hasWon) {
        hasWon = country.hasWon();
        
        //Player 1
        cout << country.returnName(1) << ", you have:\n";
        country.returnStats(1);
        cout << "It is your turn, what do you wish to do " << country.returnName(1) << "?\n";
        choiceList();
        cin >> input;
        country.playerChoice(1, input);

        if (country.hasWon())
            exit(0);
        
        //Player 2
        cout << country.returnName(2) << ", you have:\n";
        country.returnStats(2);
        cout << "It is your turn, what do you wish to do " << country.returnName(2) << "?\n";
        choiceList();
        cin >> input;
        country.playerChoice(2, input); 
    }
}
