#include "person.hh"

Person::Person(const std::string& name, unsigned int age)
    : name_(name)
    , age_(age)
{}

std::string Person::name_get() const
{
    return name_;
}

unsigned int Person::age_get() const
{
    return age_;
}

void Person::name_set(const std::string& name)
{
    name_ = name;
}

void Person::age_set(const unsigned int age)
{
    age_ = age;
}
