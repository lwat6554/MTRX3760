// SID: 500490778
// 8/2022
/*This file stores classes that are used to rn a shopping line simulator


*/

#ifndef _QUEUESIM_H
#define _QUEUESIM_H

class Teller {

    public:
        Teller(int Num = 2, int AvgCap = 3);  //tellers number in checkout, average capacity per cycle, 
        ~Teller();

        void Process();               // Processes one cycles, will remove _TellerCapacity from queue
        int QueueReport();                  //Returns length of queue
        void AddQueue();                    //adds to teller queue
        
    private:
        int _AvgCapacity;       // how many customers a teller processes in a cycle
        int _QueueLength;          // length of queue
        int _TellerNumber;         // number teller is at checkout
};

class Checkout {

    public:
        Checkout(Teller** ppTeller, int TellersNum = 3, int NewCust = 6);   //pointer to tellers, Number of tellers, Avgerage new customers at checkout
        ~Checkout();

        void FindShortestQueue();            // finds the shortest queue from an array of queue lengths
        void AddNewCustomers();             // adds all new customers to appropriate queues
        void ProcessTellersOneCycle();       // processes all tellers one cycle

    private:
        int _NumTellers;            // number of tellers in the checkout
        int _ShortestQ;              // current shortest queue
        int _AvgNewCustomer;           //average numbers of new customers
        Teller** pTellEmployee;
};

class Simulator {

    public:
        //simulation cycles, number of tellers, average teller process per cycle, average new custmers each cycle
        Simulator(int cyc = 1000, int TellersNum = 2, int TellerCycleAvg = 3, int AvgCustomerPerCycle = 6); 
        ~Simulator();

        void RunSimulation();        //controls the running of the simulation and takes
        //all inputs required for simulation

    private:
        int _SimDurationCycles;     // duration of simulation, in cycles
        int _CurrentCycle;           // current cycle of simulation
};



#endif