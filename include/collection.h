#include <iostream>
#include "exception.h"

using namespace std;

// Шаблон класса коллекции произвольного типа
template <typename T>
class Collection
{
    T **list;
    size_t size;
    int back = 0;

public:
    T *operator[](size_t index)
    {
        if (index >= size)
            throw OutOfRangeException("Out of range of passengers");
        else if (index >= back)
            throw PassengerNotFoundException("Passsenger does not exist");
        return list[index];
    }
    Collection(size_t _size) : size(_size)
    {
        list = new T *[size];
        for (size_t i = 0; i < size; i++)
        {
            list[i] = nullptr;
        }
    }

    ~Collection()
    {
        for (size_t i = 0; i < back; i++)
        {
            delete list[i];
        }
        delete[] list;
    }

    size_t get_size()
    {
        return size;
    }

    void pushback(T *element)
    {
        if (back == size)
        {
            throw NoFreeSlotException("Has no free slot!");
        }
        else
        {
            list[back] = element;
            back++;
        }
    }

    void emplace(size_t index, T *p)
    {
        if (back == size)
        {
            throw "Has no free slot!";
        }
        if (index < 0 || index > back)
        {
            throw OutOfRangeException("Index out of range");
        }
        for (int i = back; i > index; i--)
        {
            list[i] = list[i - 1];
        }
        list[index] = p;
        back++;
    }

    void erase(size_t index)
    {
        if (list[index] == nullptr)
        {
            throw PassengerNotFoundException("Passenger does not exist");
        }
        else
        {
            for (int i = index; i < back; i++)
            {
                list[i] = list[i + 1];
            }
            list[back - 1] = nullptr;
            back--;
        }
    }

    int get_back()
    {
        return back;
    }
};