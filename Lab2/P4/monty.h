#ifndef __MONTY_H
#define _MONTY_H

class Doors;

class Game {

    public:
        Game();
        ~Game();
        
        int ReportNumDoors();
        void Run(); 

    private:
        

};

class Player {

    public:
        Player(Doors* DName);
        ~Player();

        int ChooseDoor();


    private:
        Doors* pWhichDoors;
        int _ChosenDoor;
};


class Host {

    public:
        Host(Doors* DName);
        ~Host();

        void AskDoorChoice(Player* PName);
        void AskDoorAgain();
        void OpenDoors();


    private:
        Doors* pWhichDoors;
        int _2ndChoiceDoor;
        int _DoorChoice;
};


class Doors {

    public:
        Doors();
        ~Doors();

        int ReportHiddenDoor();
        int ReportNumDoors();

    private:
        int _HiddenNum;
        int _NumDoors;
};


#endif