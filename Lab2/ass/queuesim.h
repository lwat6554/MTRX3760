// SID: 500490778
// 8/2022
/*
This file stores classes that are used to run a shopping line simulator.
The Simulator class will create an instance of the checkout class, and then
the checkout class will create an multple instances of the teller class. The simulator
class will run the simulation for the inputed number of cycles
Checkout class will is capable of controlling the teller class and will simulate adding new 
customers and allocating which line
Teller runs the most basic methods that simulate the its own line
*/

#ifndef _QUEUESIM_H
#define _QUEUESIM_H

//Simulates a queue at a teller
class Teller {

    public:
        //tellers number in checkout, average capacity per cycle, 
        Teller(int Num=0, int AvgCap = 3, bool Print = false);  
        ~Teller();

        void Process();               // Processes one cycles, will remove _TellerCapacity from queue
        int QueueReport();                  //Returns length of queue
        void AddQueue();                    //adds to teller queue
        
    private:
        int _AvgCapacity;       // how many customers a teller processes in a cycle
        int _QueueLength;          // length of queue
        int _TellerNumber;         // number teller is at checkout
        bool _Print;               //determines if methods print to terminal
};

//simulates a checkout, runs multiple teller queues
class Checkout {

    public:
        //defualt strat shortest queue, two tellers, default avg 6 new customers, default not print, teller process average 3/cycle
        Checkout(int Strat = 0, int TellersNum = 2, int NewCust = 6, bool Print = false, int TellerAvgCap = 3);  
        ~Checkout();

        void FindShortestQueue();            // finds the shortest queue from an array of queue lengths
        void AddNewCustomers();             // adds all new customers to appropriate queues
        void ProcessTellersOneCycle();       // processes all tellers one cycle
        double ReportAvgQLength();          // returns average length of all teller queues

    private:
        int _NumTellers;            // number of tellers in the checkout
        int _ShortestQ;              // current shortest queue
        int _AvgNewCustomer;         //average numbers of new customers added each cycle
        Teller* pTellEmployee;      // pointer to an array of tellers
        int _QStrat;                // 0 for shortest Q strat, 1 for random Q, determines how AddNewCustomers() behaves
        bool _Print;                // determines if class prints to terminal
};

//Runs simulation of checkout multiple cycles
class Simulator {

    public:
        //simulation cycles, number of tellers, average teller process per cycle, average new custmers each cycle
        Simulator(int Strat = 0, bool print = true, int cyc = 1000); 
        ~Simulator();

        //controls the running of the simulation and takes all inputs required for simulation
        void RunSimulation(int TellersNum = 3, int TellerCycleAvg = 3, int AvgCustomerPerCycle = 6);  
        
        //Runs RunSimulation() for both strategies, prints average queue length of each
        void StratComparison(); 

    private:
        int _TotalCycles;           // duration of simulation, in cycles
        int _CurrentCycle;          // current cycle of simulation
        int _QStrat;                // 0 for shortest Q strat, 1 for random Q
        bool _Print;                // if function prints to terminal or not
        double _TotalQLength;       // Total Queue Length in simulation (adds all queues to length every cycles)
};



#endif