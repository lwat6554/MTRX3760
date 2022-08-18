#include <iostream>     // std::cout
#include <algorithm>    // std::max
#include <cstdlib>

#include "queuesim.h"

//-----------Teller Methods---------------


Teller::Teller(int Num, int AvgCap)
    :_AvgCapacity(AvgCap),
    _TellerNumber(Num),
    _QueueLength(0)
{
    std::cout << "CTOR Teller" << std::endl;
}

//Dtor deletes alllll
Teller::~Teller() {
    std::cout << "DTOR Teller" << std::endl;
}

//processes customers one cycle from the queue
void Teller::Process() {
    std::cout << "Teller " << _TellerNumber << " processing with queue length " << _QueueLength;
    
    //uniformly distrubuted number averaging avg_capcity taken away from queue length, equals 0 if queue negative
    _QueueLength = std::max(0, _QueueLength - rand()%(_AvgCapacity*2 + 1));


    std::cout << ", reduced after processing to " <<  _QueueLength << std::endl;
};

//returns queue length
int Teller::QueueReport() {
    return _QueueLength;
}

//adds to queue
void Teller::AddQueue() {
    _QueueLength++;

    //Joining message
    std::cout << "Joining a new customer to queue " << _TellerNumber << std::endl;
};


//---------------------Customer Methods-------------------------

Checkout::Checkout(int TellersNum, int NewCust) 
    :_NumTellers(TellersNum),
    _AvgNewCustomer(NewCust),
    _ShortestQ(-1)
{
        Teller aTellEmployee[_NumTellers];
        std::cout << "CTOR Customer" << std::endl;
};

Checkout::~Checkout() {
    std::cout << "DTOR Customer" << std::endl;
};

void Checkout::FindShortestQueue() {

    
    _ShortestQ = 0;
    int Length = aTellEmployee[0].QueueReport(); //find length of queue 0

    //loop through all tellers to find shortest queue, if tie lowest number teller is allocated
    for(int i=1; i<_NumTellers; i++) {
        //find if current queue (i) is shorter than shortest queue
        if(Length > aTellEmployee[i].QueueReport()) {
            //assign new shortest queue
            _ShortestQ = i;
            Length = aTellEmployee[i].QueueReport();
        }
    }
};