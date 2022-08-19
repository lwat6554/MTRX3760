// SID: 500490778
// 8/2022
/*This file stores classes that are used to rn a shopping line simulator


*/

#ifndef _QUEUESIM_H
#define _QUEUESIM_H

class Teller {

    public:
        //Teller();
        Teller(int Num=0, int AvgCap = 3, bool Print = false);  //tellers number in checkout, average capacity per cycle, 
        ~Teller();

        void Process();               // Processes one cycles, will remove _TellerCapacity from queue
        int QueueReport();                  //Returns length of queue
        void AddQueue();                    //adds to teller queue
        
    private:
        int _AvgCapacity;       // how many customers a teller processes in a cycle
        int _QueueLength;          // length of queue
        int _TellerNumber;         // number teller is at checkout
        bool _Print;
};

class Checkout {

    public:
        Checkout(int Strat = 0, int TellersNum = 2, int NewCust = 6, bool Print = false);   //pointer to tellers, Number of tellers, Avgerage new customers at checkout
        ~Checkout();

        void FindShortestQueue();            // finds the shortest queue from an array of queue lengths
        void AddNewCustomers();             // adds all new customers to appropriate queues
        void ProcessTellersOneCycle();       // processes all tellers one cycle
        double ReportAvgQLength();

    private:
        int _NumTellers;            // number of tellers in the checkout
        int _ShortestQ;              // current shortest queue
        int _AvgNewCustomer;           //average numbers of new customers
        Teller* pTellEmployee;      // pointer to an array of tellers
        int _QStrat;                // 0 for shortest Q strat, 1 for random Q
        bool _Print;
};

class Simulator {

    public:
        //simulation cycles, number of tellers, average teller process per cycle, average new custmers each cycle
        Simulator(int Strat = 0, bool print = true, int cyc = 1000); 
        ~Simulator();

        //controls the running of the simulation and takes all inputs required for simulation
        void RunSimulation(int TellersNum = 3, int TellerCycleAvg = 3, int AvgCustomerPerCycle = 6);  
        
        void StratComparison(); 

    private:
        int _TotalCycles;     // duration of simulation, in cycles
        int _CurrentCycle;           // current cycle of simulation
        int _QStrat;            // 0 for shortest Q strat, 1 for random Q
        bool _Print;            //if function prints to terminal or not
        double _TotalQLength;
};

#endif