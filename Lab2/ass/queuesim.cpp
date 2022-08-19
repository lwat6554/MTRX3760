#include <iostream>     // std::cout
#include <algorithm>    // std::max
#include <cstdlib>

#include "queuesim.h"

//-----------Teller Methods---------------
Teller::Teller(int Num, int AvgCap, bool Print)
    :_AvgCapacity(AvgCap),
    _TellerNumber(Num),
    _QueueLength(0),
    _Print(Print)
{
    if(_Print) {
        std::cout << "CTOR Teller, ID: " << _TellerNumber << std::endl;
    }
    
}

//Dtor deletes alllll 
Teller::~Teller() {
    if(_Print) {
        std::cout << "DTOR Teller, ID: " << _TellerNumber << std::endl;
    }
}


//processes customers one cycle from the queue
void Teller::Process() {

    if(_Print){
        std::cout << "Teller " << _TellerNumber << " processing with queue length " << _QueueLength;
    }

    //uniformly distrubuted number averaging avg_capcity taken away from queue length, equals 0 if queue negative
    _QueueLength = std::max(0, _QueueLength - rand()%(_AvgCapacity*2 + 1));

    if(_Print){
        std::cout << ", reduced after processing to " <<  _QueueLength << std::endl;
    }
};

//returns queue length
int Teller::QueueReport() {
    return _QueueLength;
}

//adds to queue
void Teller::AddQueue() {
    _QueueLength++;

    //Joining message
    if(_Print) {
        std::cout << "Joining a new customer to queue " << _TellerNumber << std::endl;
    }
};


//---------------------Customer Methods-------------------------

Checkout::Checkout(int Strat, int TellersNum, int NewCust, bool Print) 
    :_NumTellers(TellersNum),
    _AvgNewCustomer(NewCust),
    _ShortestQ(-1),
    _QStrat(Strat),
    _Print(Print)
{
    if(_Print) {
        std::cout << "CTOR Customer" << std::endl;
    }

    
    pTellEmployee = new Teller[_NumTellers];

    for(int i=0; i<_NumTellers; i++) {

        pTellEmployee[i] = Teller(i, NewCust, Print);

        //std::cout << i << std::endl;
    }
};

Checkout::~Checkout() {
    delete [] pTellEmployee;

    if(_Print) {
        std::cout << "DTOR Customer" << std::endl;
    }
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
    if(_Print) {
        std::cout << "Allocating " << NewCust << " new customers" << std::endl;
    }
    

    //find shortest queue and add customer to said queue
    for(int i=0; i<NewCust; i++) {
        
        //queue strategy
        if(_QStrat == 0) { //allocate customer to the shortest queue
            FindShortestQueue();
            pTellEmployee[_ShortestQ].AddQueue();
        } else if (_QStrat == 1) {
            pTellEmployee[rand() % _NumTellers].AddQueue(); //allocates customer to random queue
        }
        
    }


};

//tells all tellers to process customers
void Checkout::ProcessTellersOneCycle() {

    //loops through all tellers to process cycles
    for(int i=0; i<_NumTellers; i++) {
        pTellEmployee[i].Process();
    }
};

double Checkout::ReportAvgQLength() {

    double Total = 0;

    //loops through all tellers
    for(int i=0; i<_NumTellers; i++) {
        Total += (double)pTellEmployee[i].QueueReport();
    }

    return Total / (double)_NumTellers;
};

//---------------------Simulation Methdos--------------
Simulator::Simulator(int strat, bool print, int cyc) 
    :_TotalCycles(cyc),
    _CurrentCycle(0),
    _QStrat(strat),
    _Print(print),
    _TotalQLength(0)
{
    if(_Print) {
        std::cout << "CTOR Simulator" << std::endl;
    }
    
};

Simulator::~Simulator() {
    if(_Print) {
        std::cout << "DTOR Simulator" << std::endl;
    }
    
};

void Simulator::RunSimulation(int TellersNum, int TellerCycleAvg, int AvgCustomerPerCycle) {

    Checkout Coles(_QStrat, TellersNum, AvgCustomerPerCycle, _Print);

    //loop through each cycle, adding new customers and then processing them
    for(_CurrentCycle=0; _CurrentCycle< _TotalCycles; _CurrentCycle++) {
        
        if(_Print){
            std::cout << "[RunSimulation] simulation cycle " << _CurrentCycle << std::endl;     //prints simulation cycle number
        }
        //adds 0-MaxCustomers to queue
        Coles.AddNewCustomers();
        
        //Process Customers from teller queues
        Coles.ProcessTellersOneCycle();

        //Find Q length
        _TotalQLength += Coles.ReportAvgQLength();
    }
};

void Simulator::StratComparison() {

    //Run simulation with shortest Q strat
    _QStrat = 0;
    _TotalQLength = 0;
    _CurrentCycle = 0;
    RunSimulation(0, false);

    std::cout << "Shortest Queue Strat Average Queue: " << _TotalQLength / (double)(_CurrentCycle+1) << std::endl;

    _TotalQLength = 0;
    _CurrentCycle = 0;
    _QStrat = 1;

    RunSimulation(1, false);
    std::cout << "Random Queue Strat Average Queue: " << _TotalQLength / (double)(_CurrentCycle+1) << std::endl;



};