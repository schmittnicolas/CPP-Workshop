#pragma once

class Engine
{
public:
    // Attribute
    int fuel;

    // Constructor
    Engine(int fuel);

    // Methods
    bool start();
    void use(int consumed);
    void stop() const;
    void fill(int fuel);
};