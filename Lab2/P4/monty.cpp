#include <iostream>     // std::cout
#include <algorithm>    // std::max

#include "monty.h"

//-------------Game
Game::Game()
{
    std::cout << "CTOR Game" << std::endl;
};

Game::~Game() {
    std::cout << "DTOR Game" << std::endl;
};

void Game::Run() {
    Doors Wooden;
    Player Chad(&Wooden);
    Host Paul(&Wooden);

    Paul.AskDoorChoice(&Chad);
};


//--------------Doors
Doors::Doors() 
   : _NumDoors(3)
{
    std::cout << "CTOR Doors" << std::endl;

    //create hidden door
    _HiddenNum = rand()% _NumDoors;
    std::cout << "Hidden Number is " << _HiddenNum << std::endl;
};

Doors::~Doors() {
    std::cout << "DTOR Doors" << std::endl;
};

int Doors::ReportHiddenDoor() {
    return _HiddenNum;
};

int Doors::ReportNumDoors() {
    //std::cout << "ReportNumDoors" <<_NumDoors << std::endl;
    return _NumDoors;
};

//------------Host
Host::Host(Doors* DName) 
    :pWhichDoors(DName)
{
    std::cout << "CTOR Host" << std::endl;
};

Host::~Host() {
    std::cout << "DTOR Host" << std::endl;
};

void Host::AskDoorChoice(Player* PName) {
    std::cout << "Pick a door between 0 and " << pWhichDoors->ReportNumDoors() << std::endl;

    PName->ChooseDoor();

}

//------------Player
Player::Player(Doors* DName)
    :pWhichDoors(DName),
    _ChosenDoor(-1)
{
    std::cout << "CTOR Player" << std::endl;
}
Player::~Player(){
    std::cout << "DTOR Player" << std::endl;
}

int Player::ChooseDoor() {
    //std::cout << "ChooseDoor" << _ChosenDoor << pWhichDoors->ReportNumDoors() << std::endl;
    
    while(_ChosenDoor<0 && _ChosenDoor>pWhichDoors->ReportNumDoors()) {
        std::cin >> _ChosenDoor;
        std::cout << "Test 81" << std::endl;
    }

    return _ChosenDoor;
};