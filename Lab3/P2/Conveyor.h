// Conveyor.h
//
// Header file for a simulated conveyor belt
// Initial revision: Donald G Dansereau, 2019
// Completed by:

#ifndef _CONVEYOR_H
#define _CONVEYOR_H

//---------------------------------------------------------------
// Simulate a conveyor belt. This version just counts how many
// objects are on the belt, and accepts requests to add and remove
// objects.
class Conveyor
{
    public:
        void Init();
        void AddItems( int n );
        void RemoveItems( int n );
        void Report();

    private:
        int _NumItemsOnConveyor;
};

class Item{
    public:
        Item(int ID);
        ~Item();
        
        static int _Time;
        static int _ItemsProcessed;
        static double _TotalProcessingTime;

        static int FindShortestItem();

    private:
        int _ID;
        double _InitTime;
        

};

#endif
