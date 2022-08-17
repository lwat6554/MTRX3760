#ifndef __MONTY_H
#define _MONTY_H

class Game {

    public:
        Game();
        ~Game();
        
        int ReportNumDoors();
        void Run(); 

    private:
        int _NumDoors;

};

class Player {

    public:



    private:

};


class Host {

    public:



    private:
};


class Doors {

    public:
        Doors();
        ~Doors();


    private:
        int _HiddenNum;
};


#endif