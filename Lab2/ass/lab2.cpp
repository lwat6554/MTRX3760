// SID: 500490778
// 8/2022
/*This program runs a queueing simulator...


*/

#include <iostream>
#include <cstdlib>              // rand
#include <algorithm>    // std::max

#include "queuesim.h"

int main() {

    

    srand(time(0)); //random number generator same for both strategies, different every run time



    Simulator Computor(1, false);

    //Computor.RunSimulation();
    Computor.StratComparison();

}