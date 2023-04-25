#include "player.hh"

Player::Player(const std::string& name, unsigned int age)
{
    if (name == "")
        throw InvalidArgumentException("Name can't be empty.");

    if (age > 150)
        throw InvalidArgumentException("Sorry gramp, too old to play.");
    name_ = name;
    age_ = age;
}