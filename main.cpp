#include <iostream>
#include "Country.h"

using namespace std;

int main() {
    //Object Declaration
    Country country;

    //Variables
    int input;
    char techChoice;
    
    //Title Screen
    cout << "Welcome to Country Battle Plus: Remastered.\n";
    country.getNames();

    //Game
    cout << country.returnName(1) << ", you have: ";
    cout << country.returnName(2) << ", you have: ";
}
