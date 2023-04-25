#include "builder.hh"

Car Builder::get_car() const
{
    Car car;
    car.wheels_.at(0) = get_wheel();
    car.wheels_.at(1) = get_wheel();
    car.wheels_.at(2) = get_wheel();
    car.wheels_.at(3) = get_wheel();
    car.body_ = this->get_body();
    car.engine_ = this->get_engine();
    return car;
}

std::unique_ptr<Wheel> JeepBuilder::get_wheel() const
{
    Wheel wheel(22);
    return std::make_unique<Wheel>(wheel);
}
std::unique_ptr<Engine> JeepBuilder::get_engine() const
{
    Engine engine(400);
    return std::make_unique<Engine>(engine);
}

std::unique_ptr<Body> JeepBuilder::get_body() const
{
    Body body("SUV");
    return std::make_unique<Body>(body);
}

std::unique_ptr<Wheel> NissanBuilder::get_wheel() const
{
    Wheel wheel(16);
    return std::make_unique<Wheel>(wheel);
}
std::unique_ptr<Engine> NissanBuilder::get_engine() const
{
    Engine engine(85);
    return std::make_unique<Engine>(engine);
}

std::unique_ptr<Body> NissanBuilder::get_body() const
{
    Body body("hatchback");
    return std::make_unique<Body>(body);
}