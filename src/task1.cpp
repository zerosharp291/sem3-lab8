#include <iostream>
#include <typeinfo>
#include <set>
#include "passenger.h"
#include "collection.h"

using namespace std;

void get_spacebar()
{
    for (int i = 0; i < 3; i++)
        cout << endl;
}
template <typename T>
void get_passenger_info(Collection<T> &col)
{
    for (int i = 0; i < col.get_back(); i++)
    {
        col[i]->get_info();
    }
}

template <typename T>
void get_conductor_revenue(T &list)
{
    set<string> types;
    double sum = 0;
    for (int i = 0; i < list.get_back(); i++)
    {
        Passenger *curr_passenger = list[i];
        string curr_info = typeid(*curr_passenger).name();
        types.emplace(curr_info);
        sum += curr_passenger->get_ticket_price();
    }

    cout << "Different types of passengers: " << types.size() << endl;
    cout << "Revenue of conductor: " << sum << endl;
}

int main()
{

    Passenger *p1 = new TicketPassenger(make_pair("John", "Snow"), 33, "today", 20.12);
    Passenger *p2 = new TicketPassenger(make_pair("James", "Bond"), 47, "1953", 33.33);
    Passenger *p3 = new PreferencialPassenger(make_pair("Jury", "Bury"), 12, "school", "schooltime", 9.99);
    Passenger *p4 = new PreferencialPassenger(make_pair("Alex", "Samoylov"), 12, "pensioner", "everytime", 9.99);
    Passenger *p5 = new MembershipPassenger(make_pair("Nura", "Nurina"), 58, 100, "unlimited");
    Passenger *p6 = new MembershipPassenger(make_pair("Semyon", "Pechkin"), 60, 70, "limited 65");
    Passenger *p7 = new FareDodgerPassenger(make_pair("Andrew", "Zaytsev"), 21, false);
    Passenger *p8 = new FareDodgerPassenger(make_pair("Michael", "Zaytsev"), 18, true);

    Collection<Passenger> l1(8);
    try
    {
        l1.pushback(p1);
        l1.pushback(p2);
        l1.pushback(p3);
        l1.pushback(p4);
        l1.pushback(p5);
        l1.pushback(p6);
        l1.pushback(p7);
        l1.pushback(p8);

        get_passenger_info(l1);

        l1.erase(0);
        get_spacebar();
        get_passenger_info(l1);

        Passenger *p9 = new TicketPassenger(make_pair("Harvey", "Branson"), 41, "now", 20.12);

        l1.emplace(0, p9);
        /*         l1.emplace(12, new TicketPassenger(make_pair("Jo", "Jo"), 77, "always", 99.99)); */
        /*         l1.pushback(new TicketPassenger(make_pair("Jo", "Jo"), 77, "always", 99.99));
                l1.pushback(new TicketPassenger(make_pair("Jo", "Jo"), 77, "always", 99.99));
                l1.pushback(new TicketPassenger(make_pair("Jo", "Jo"), 77, "always", 99.99));
                l1.pushback(new TicketPassenger(make_pair("Jo", "Jo"), 77, "always", 99.99)); */
    }
    catch (const std::exception &e)
    {
        cout << "Error: " << e.what() << endl; // Выводим сообщение об ошибке
    }
    get_spacebar();
    get_passenger_info(l1);

    get_conductor_revenue(l1);

    Collection<int> l2(4);
    l2.pushback(new int(8));
    l2.pushback(new int(9));
    l2.emplace(2, new int(3));
    l2.erase(2);
    l2.pushback(new int(11));
    l2.pushback(new int{12});

    cout << "-----------------\nCollection type is int:\n";
    for (int i = 0; i < l2.get_back(); i++)
    {
        cout << *l2[i] << " ";
    }
    cout << endl;

    return 0;
}