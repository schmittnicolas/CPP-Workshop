#pragma once
#include <memory>
#include <string>

template <typename T>
class Singleton
{
protected:
    Singleton() = default;
    ~Singleton() = default;

public:
    Singleton(const Singleton<T>&) = delete;
    Singleton<T>& operator=(const Singleton<T>&) = delete;
};

class Logger
{
private:
    Logger(){};

public:
    static Logger* instance()
    {
        static Logger* instance_;
        return instance_;
    }

    void open_log_file(const std::string& file);
    void write_to_log_file();
    void close_log_file();

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};