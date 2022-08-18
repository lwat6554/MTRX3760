#include <iostream>     // std::cout
#include <algorithm>    // std::max

#include "monty.h"

int main() {

    srand(time(0));

    
    Game Hall;
    //Hall.Run(); 
    std::cout << "Choose strat (0 change, 1 stay, 2 random)" << std::endl;

    int strat;
    std::cin >> strat;

    Hall.RunSim(strat, 1000, 100); // strat (0 change, 1 stay, 2 random) , cycles




 
    return 0;

}