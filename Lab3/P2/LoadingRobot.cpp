// LoadingRobot.cpp
//
// Implementation file for a robot that can load items onto a conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:


#include <cstdlib>      // rand

#include "LoadingRobot.h"
#include "Conveyor.h"


//---------------------------------------------------------------
void LoadingRobot::Init( Conveyor* WhichConveyor )
{
    _Conveyor = WhichConveyor;
}

//---------------------------------------------------------------
void LoadingRobot::AddItems()
{
    _Conveyor->AddItems( rand() % 10 );
}

