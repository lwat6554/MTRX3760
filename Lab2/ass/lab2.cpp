// SID: 500490778
// 8/2022
/*
This program runs a queueing simulator to compare the average Queue length if new customer allocated
to the shortest Queue vs allocated to a random Q. Read queuesim.h for details of all classes used
*/

#include <iostream>
#include <cstdlib>              // rand
#include <algorithm>            // std::max

#include "queuesim.h"

int main() {

    srand(time(0)); //random number generator same for both strategies, different every run time


    //Runs the simulation 
    Simulator* Output = new Simulator(0, true, 100); //shortest Q strat, printing = true, 100 cycles
    Output->RunSimulation();
    delete Output;

    //Compares random Q strat to shortest Q strat 
    Simulator Compare(0, false);
    Compare.StratComparison();

}