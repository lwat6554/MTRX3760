// main.cpp
//
// Main file for simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:

#include <iostream>
#include <cstdlib>      // rand
#include <algorithm>    // std::max

#include "Conveyor.h"
#include "LoadingRobot.h"
#include "ProcessingRobot.h"


int main()
{
    srand(time(0));


    Conveyor myConveyor;
    LoadingRobot myLoader;
    ProcessingRobot myProcessor;

    myConveyor.Init();
    myLoader.Init( &myConveyor );
    myProcessor.Init( &myConveyor );

    Item::_Time=0;
    Item::_ItemsProcessed=0;
    Item::_TotalProcessingTime=0;

    while( 1 )
    {
        myLoader.AddItems();
        myConveyor.Report();
        myProcessor.ProcessItemsTimed();
        myConveyor.Report();
        std::cout << myProcessor.ReportUtilisation() << "%" << std::endl;
    }

    
    
}


