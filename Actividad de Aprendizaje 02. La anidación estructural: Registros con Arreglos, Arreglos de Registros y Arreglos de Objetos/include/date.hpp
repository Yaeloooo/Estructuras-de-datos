#ifndef __DATE_H__
#define __DATE_H__
#include <iostream>
#include <string>

class Date
{
private:

    int day;
    int month;
    int year;

public:
    Date(/* args */);
    Date(int day, int month, int year);
    Date(const Date &other);
    Date &operator = (const Date &other);

    void setDay(const int&);
    void setMonth(const int&);
    void setYear(const int&);

    std::string toString() const;

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    friend std::ostream &operator << (std::ostream &, const Date &);
    friend std::istream &operator >> (std::istream &, const Date &);   
};

#endif // __DATE_H__