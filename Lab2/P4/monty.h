#ifndef __MONTY_H
#define _MONTY_H

class Doors;

class Game {

    public:
        Game();
        ~Game();
        
        int ReportNumDoors();
        void Run(); 
        void RunSim(int strat = 0, int cycles = 1000, int doors = 3);

    private:
        int _Total;
};

class Player {

    public:
        Player(Doors* DName, bool sim = false, int strat = 0);
        ~Player();

        int ChooseDoor();
        int ChooseDoorAgain(int stay, int change);
        int ReportDoor();


    private:
        Doors* pWhichDoors;
        int _ChosenDoor;
        bool _Sim;
        int _Strat;
};


class Host {

    public:
        Host(Doors* DName, Player*PName, bool sim = false);
        ~Host();

        void AskDoorChoice();
        void AskDoorAgain();
        void OpenDoors();
        int CheckAnswer();

    private:
        Doors* pWhichDoors;
        Player* pPlayerName;
        int _2ndChoiceDoor;
        int _DoorChoice;
        bool _Sim;
        int _Result;
};


class Doors {

    public:
        Doors(int NumD = 3);
        ~Doors();

        int ReportHiddenDoor();
        int ReportNumDoors();

    private:
        int _HiddenNum;
        int _NumDoors;
};


#endif