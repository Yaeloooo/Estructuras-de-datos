#include "date.hpp"

using namespace std;

Date::Date() : day(1), month(1), year(2005)
{
}

Date::Date(int d, int m, int a) : day(d), month(m), year(a)
{
}

Date::Date(const Date &other) : day(other.day), month(other.month), year(other.year) {}

Date &Date::operator=(const Date &other)
{
    if (this != &other)
    {
        this->day = other.day;
        this->month = other.month;
        this->year = other.year;
    }

    return *this;
}

void Date::setDay(const int &d)
{
    this->day = d;
}

void Date::setMonth(const int &m)
{
    this->month = m;
}

void Date::setYear(const int &y)
{
    this->year = y;
}

std::string Date::toString() const
{
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

int Date::getDay() const
{
    return this->day;
}

int Date::getMonth() const
{
    return this->month;
}

int Date::getYear() const
{
    return this->year;
}

// std::istream& operator >> (std::istream &is, const Date &d)
// {

// }

// std::ostream& operator << (std::ostream &, const Date &)
// {

// }
