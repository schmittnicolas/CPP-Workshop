#include "engine.hh"

#include <iostream>

Engine::Engine(int fuel)
{
    this->fuel = fuel;
}

bool Engine::start()
{
    if (fuel > 0)
    {
        fuel--;
        std::cout << "Engine starts with " << fuel << " units of fuel\n";
        return true;
    }
    else
    {
        return false;
    }
}

void Engine::use(int consumed)
{
    if (consumed > fuel)
    {
        std::cout << "Engine uses " << fuel << " fuel units\n";
        fuel = 0;
    }
    else
    {
        std::cout << "Engine uses " << consumed << " fuel units\n";
        fuel -= consumed;
    }
}

void Engine::stop() const
{
    std::cout << "Stop Engine\n";
}

void Engine::fill(int fuel)
{
    this->fuel += fuel;
    std::cout << "Engine now has " << this->fuel << " fuel units\n";
}