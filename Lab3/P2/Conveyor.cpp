// Conveyor.cpp
//
// Implementation file for a simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:

#include <iostream>     // std::cout
#include <algorithm>    // std::max

#include "Conveyor.h"

//---------------------------------------------------------------
void Conveyor::Init()
{
    _NumItemsOnConveyor = 0;
}

//---------------------------------------------------------------
void Conveyor::AddItems( int n )
{
    _NumItemsOnConveyor += n;
}

//---------------------------------------------------------------
void Conveyor::RemoveItems( int n )
{
    // Note that we cannot have a negative number of items on belt
    _NumItemsOnConveyor = std::max(0, _NumItemsOnConveyor-n);
}

//---------------------------------------------------------------
void Conveyor::Report()
{
    std::cout << "Items on conveyor: " << _NumItemsOnConveyor << std::endl;
}



