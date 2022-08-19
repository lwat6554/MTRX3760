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
    std::cout << "CTOR Teller, ID: " << _TellerNumber << std::endl;
}

//Dtor deletes alllll 
Teller::~Teller() {
    std::cout << "DTOR Teller, ID: " << _TellerNumber << std::endl;
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
    std::cout << "CTOR Customer" << std::endl;

    
    pTellEmployee = new Teller[_NumTellers];

    for(int i=0; i<_NumTellers; i++) {

        pTellEmployee[i] = Teller(i);

        //std::cout << i << std::endl;
    }
};

Checkout::~Checkout() {
    delete [] pTellEmployee;

    std::cout << "DTOR Customer" << std::endl;
};

void Checkout::FindShortestQueue() {

    //std::cout << "Checkout::FindShortestQueue" << std::endl;    

    _ShortestQ = 0;
    int Length = pTellEmployee[0].QueueReport(); //find length of queue 0

   
    //loop through all tellers to find shortest queue, if tie lowest number teller is allocated
    for(int i=1; i<_NumTellers; i++) {
        //find if current queue (i) is shorter than shortest queue
        if(Length > pTellEmployee[i].QueueReport()) {
            //assign new shortest queue
            _ShortestQ = i;
            Length = pTellEmployee[i].QueueReport();  
        }
    }
};

//adds new customer to existing queues, uses find shortest queue to efficiently disperse new customers
void Checkout::AddNewCustomers() {
    
    int NewCust = rand() % (_AvgNewCustomer*2 + 1);


    //display allocation customer message
    std::cout << "Allocating " << NewCust << " new customers" << std::endl;
    

    //find shortest queue and add customer to said queue
    for(int i=0; i<NewCust; i++) {
        FindShortestQueue();
        pTellEmployee[_ShortestQ].AddQueue();
    }


};

//tells all tellers to process customers
void Checkout::ProcessTellersOneCycle() {

    //loops through all tellers to process cycles
    for(int i=0; i<_NumTellers; i++) {
        pTellEmployee[i].Process();
    }
};


//---------------------Simulation Methdos--------------
Simulator::Simulator(int cyc) 
    :_TotalCycles(cyc),
    _CurrentCycle(0)
{
    std::cout << "CTOR Simulator" << std::endl;
}

Simulator::~Simulator() {
    std::cout << "DTOR Simulator" << std::endl;
}

void Simulator::RunSimulation(int TellersNum, int TellerCycleAvg, int AvgCustomerPerCycle) {

    Checkout Coles;

    //loop through each cycle, adding new customers and then processing them
    for(_CurrentCycle=0; _CurrentCycle< _TotalCycles; _CurrentCycle++) {
        
        std::cout << "[RunSimulation] simulation cycle " << _CurrentCycle << std::endl;     //prints simulation cycle number

        //adds 0-MaxCustomers to queue
        Coles.AddNewCustomers();
        
        //Process Customers from teller queues
        Coles.ProcessTellersOneCycle();
    }
}