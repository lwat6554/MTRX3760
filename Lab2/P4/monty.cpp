#include <iostream>     // std::cout
#include <algorithm>    // std::max

#include "monty.h"

//-------------Game
Game::Game()
    : _NumDoors(3)
{
    std::cout << "CTOR Game" << std::endl;
};

Game::~Game() {
    std::cout << "DTOR Game" << std::endl;
};

int Game::ReportNumDoors() {
    return _NumDoors;
};

void Game::Run() {
    Doors Wooden();

};


//--------------Doors
Doors::Doors() 
{
    _HiddenNum = rand()% 3;

    std::cout << "Hidden Number is " << _HiddenNum << std::endl;
};

Doors::~Doors() {
    std::cout << "DTOR Doors" << std::endl;
}