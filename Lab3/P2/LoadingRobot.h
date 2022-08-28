// LoadingRobot.h
//
// Header file for a robot that can load items onto a conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:

#ifndef _LOADINGROBOT_H
#define _LOADINGROBOT_H

#include "Conveyor.h"


//-------------------------------------------------------------------
// Simulate a loading robot that places items on a conveyor belt.
// Note that Init sets a pointer to the conveyor the robot will load.
// This version simulates an irregular source of parts by adding a
// random number of parts to the conveyor when AddItems() is called.
class LoadingRobot
{
    public:
        void Init( Conveyor* WhichConveyor );
        void AddItems();
    private:
        Conveyor* _Conveyor;
};


#endif
