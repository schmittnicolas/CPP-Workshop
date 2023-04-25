#pragma once

#include "vehicle.hh"

class MotorTruck : public Vehicle
{
protected:
    size_t nb_tires_;

public:
    MotorTruck(const std::string& model, int fuel, size_t nb_tires);
    void change_tires() const override;
};