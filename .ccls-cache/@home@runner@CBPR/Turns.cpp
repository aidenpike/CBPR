#include <iostream> 

class Turns {
    public:
        static void nameGather(std::string plOneName, std::string plTwoName){
            std::cout << "Player one, enter your name: ";
            std::cin >> plOneName;
            std::cout << "Player two, enter your name: ";
            std::cin >> plTwoName;
        }
    private:
};