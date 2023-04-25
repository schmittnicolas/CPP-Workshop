#pragma once

#include <iostream>
#include <string>

class Person
{
private:
    std::string name_;
    unsigned int age_;

public:
    Person(const std::string& name, unsigned int age);
    std::string name_get() const;
    void name_set(const std::string& name);
    unsigned int age_get() const;
    void age_set(const unsigned int age);
};
