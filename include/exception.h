#include <exception>
#include <string>

// Исключение для выхода за пределы массива
class OutOfRangeException : public std::exception
{
public:
    OutOfRangeException(const std::string &message) : msg_(message) {}

    virtual const char *what() const noexcept override
    {
        return msg_.c_str();
    }

private:
    std::string msg_;
};

// Исключение для отсутствия свободного места
class NoFreeSlotException : public std::exception
{
public:
    NoFreeSlotException(const std::string &message) : msg_(message) {}

    virtual const char *what() const noexcept override
    {
        return msg_.c_str();
    }

private:
    std::string msg_;
};

// Исключение для отсутствия пассажира
class PassengerNotFoundException : public std::exception
{
public:
    PassengerNotFoundException(const std::string &message) : msg_(message) {}

    virtual const char *what() const noexcept override
    {
        return msg_.c_str();
    }

private:
    std::string msg_;
};