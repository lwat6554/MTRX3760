// SID: 500490778
// 8/2022
/*This program runs a queueing simulator...


*/

#include <iostream>
#include <cstdlib>              // rand
#include <algorithm>    // std::max

#include "queuesim.h"

int main() {

    

    srand(time(0));

    Teller Employee[2];

    Checkout Coles(&Employee);
    Coles.FindShortestQueue();


    return 0;
}