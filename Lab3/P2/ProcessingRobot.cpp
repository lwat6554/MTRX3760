// ProcessingRobot.cpp
//
// Implementation file for a robot that processes items off a conveyor belt
// Initial revision: Donald G Dansereau
// Completed by:

#include <iostream>
#include <cstdlib>      // rand
#include <algorithm>    // std::max

#include "ProcessingRobot.h"

//---------------------------------------------------------------
void ProcessingRobot::Init( Conveyor* WhichConveyor )
{
    _Conveyor = WhichConveyor;
    _TotalTime = 0;
    _UtilisedTime = 0;
}

//---------------------------------------------------------------
void ProcessingRobot::ProcessItems()
{
    _Conveyor->RemoveItems( 5 );
};


void ProcessingRobot::ProcessItemsTimed() {

    int Time = 0;
    int NumItemsProcessed=0;
    int UTime =0;

    while(Time<16.1) {
        
        Time += 1 + (rand()%42/10.0);

        if(Time<16.1) {
            NumItemsProcessed++;
            UTime = Time;   
        }

    }
    _UtilisedTime += UTime;
    _TotalTime += 16.1;

    _Conveyor->RemoveItems(NumItemsProcessed);
    
};

double ProcessingRobot::ReportUtilisation() {
    return (_UtilisedTime/_TotalTime)*100;
}