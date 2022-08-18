#include <iostream>     // std::cout
#include <algorithm>    // std::max
#include <cstdlib>

#include "monty.h"

//-------------Game
Game::Game()
    :_Total(0)
{
    //std::cout << "CTOR Game" << std::endl;
};

Game::~Game() {
    //std::cout << "DTOR Game" << std::endl;
};

void Game::Run() {
    Doors Wooden;
    Player Chad(&Wooden);
    Host Paul(&Wooden, &Chad);


    Paul.AskDoorChoice();
    Paul.OpenDoors();
    Paul.AskDoorAgain();
    Paul.CheckAnswer();
};

void Game::RunSim(int strat, int cycles, int doors) {

    Doors Hatch(doors);
    Player Robot(&Hatch, true, strat);
    Host Rodney(&Hatch, &Robot, true);



    for(int i = 0; i<cycles; i++) {
        Rodney.AskDoorChoice();
        Rodney.OpenDoors();
        Rodney.AskDoorAgain();
        _Total += Rodney.CheckAnswer();
    }

    std::cout << "Strategy: " << strat << "  cycles: " << cycles << "   Wins: " << _Total << "  Percentage Success: " << double(_Total) / double(cycles) << std::endl;
}

//--------------Doors
Doors::Doors(int NumD) 
   : _NumDoors(NumD)
{
    //std::cout << "CTOR Doors" << std::endl;
    //create hidden door
    _HiddenNum = rand() % 3;
    //std::cout << "Hidden Number is " << _HiddenNum << std::endl;
};


Doors::~Doors() {
    //std::cout << "DTOR Doors" << std::endl;
};

int Doors::ReportHiddenDoor() {
    return _HiddenNum;
};

int Doors::ReportNumDoors() {
    //std::cout << "ReportNumDoors" <<_NumDoors << std::endl;
    return _NumDoors;
};

//------------Host
Host::Host(Doors* DName, Player* PName, bool sim) 
    :pWhichDoors(DName),
    _2ndChoiceDoor(-1),
    _DoorChoice(-1),
    pPlayerName(PName),
    _Sim(sim)
{
    //std::cout << "CTOR Host" << std::endl;
};

Host::~Host() {
    //std::cout << "DTOR Host" << std::endl;
};

void Host::AskDoorChoice() {
    if(_Sim == false) {
        std::cout << "Pick a door between 0 and " << pWhichDoors->ReportNumDoors()-1 << std::endl;
    } 
    _DoorChoice = pPlayerName->ChooseDoor();

};

void Host::OpenDoors() {
    
    _2ndChoiceDoor = rand() % pWhichDoors->ReportNumDoors();

    if(_DoorChoice==pWhichDoors->ReportHiddenDoor()) {
        while(_2ndChoiceDoor == _DoorChoice) {
         _2ndChoiceDoor = rand() % pWhichDoors->ReportNumDoors();
        }
    } else {
        _2ndChoiceDoor = pWhichDoors->ReportHiddenDoor();
    }
    

    //std::cout << "OpenDoors: " << _2ndChoiceDoor << std::endl;
};

void Host::AskDoorAgain() {
    if(_Sim == false) {
        std::cout << "Would you like to stay with door " << _DoorChoice << " or would you like to pick door "<< _2ndChoiceDoor << "?"<<std::endl;
    }

    _DoorChoice = pPlayerName->ChooseDoorAgain(_DoorChoice, _2ndChoiceDoor);
};

int Host::CheckAnswer() {
    
    if(_DoorChoice == pWhichDoors->ReportHiddenDoor()) {
        if(_Sim == false) {
            std::cout << "Congrats, you WIN a car" << std::endl;
        }
        _Result = 1;
    } else {
        if(_Sim == false) {
            std::cout << "Bad Luck, you get a goat" << std::endl;
        }
        _Result = 0;
     }
    
    return _Result;
};

//------------Player
Player::Player(Doors* DName, bool sim, int strat)
    :pWhichDoors(DName),
    _ChosenDoor(-1),
    _Sim(sim),
    _Strat(strat)
{
    //std::cout << "CTOR Player" << std::endl;
}
Player::~Player(){
    //std::cout << "DTOR Player" << std::endl;
}

int Player::ChooseDoor() {

    if(_Sim == false) {
         while(_ChosenDoor<0 || _ChosenDoor>pWhichDoors->ReportNumDoors()) {
            std::cin >> _ChosenDoor;
        
        }
    } else {
        _ChosenDoor = rand() % pWhichDoors->ReportNumDoors();
    }

    return _ChosenDoor;
};

int Player::ChooseDoorAgain(int stay, int change) {

    _ChosenDoor = -1;

    if(_Sim == false) {
        while(_ChosenDoor != stay && _ChosenDoor != change) {
            std::cin >> _ChosenDoor;
        }
    } else if(_Strat == 0) {
        _ChosenDoor = change;
    } else if(_Strat == 1) {
        _ChosenDoor = stay;
    } else { //random choice
        if(rand()%2 == 1){
            _ChosenDoor = change;
        } else {
            _ChosenDoor = stay;
        }
    }
    
    
    
    

    return _ChosenDoor;

}