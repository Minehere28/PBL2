#include <iostream>
#include <ctime>
#include <exception>
using namespace std;

#ifndef DATE_H
#define DATE_H

class Date
{
protected:
    int d, m, y;

public:
    Date(int = 1, int = 1, int = 2000);
    ~Date();
    Date operator++(int);
    Date &operator++();
    Date &operator--();
    Date operator--(int);
    friend ostream &operator<<(ostream &, const Date &);
    friend istream &operator>>(istream &, Date &);
    void check();
    int get_weekday();
    int get_month() const;
    int get_day() const;
    int get_year() const;
    Date today();
    bool isValidDate(int day, int month, int year);

    bool operator<(const Date& other) const;

    
    string toString() const;

    int days_in_month(int thang) ;
    Date createDueDate(int monthsToAdd, const Date ngayMuon);
    void adjustToValidDate();

    tm toTm() const;

};

#endif
