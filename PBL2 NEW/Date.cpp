#include <iostream>
#include <ctime>
#include <exception>
#include <sstream> 
#include "Date.h"
using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Date ::days_in_month(int thang)
{
    this->check();
    return days[thang];
}
int Date::get_weekday()
{
    struct tm Datetime;
    time_t timestamp;

    Datetime.tm_year = y - 1900;
    Datetime.tm_mon = m - 1;
    Datetime.tm_mday = d;
    Datetime.tm_hour = 12;
    Datetime.tm_min = 30;
    Datetime.tm_sec = 1;
    Datetime.tm_isdst = -1;

    timestamp = mktime(&Datetime);

    return Datetime.tm_wday;
}

Date Date::today()
{
    time_t now = time(0); 

    tm *ltm = localtime(&now); // Chuyển đổi sang dạng struct tm

    Date today(ltm->tm_mday, 1 + ltm->tm_mon, 1900 + ltm->tm_year);
    *this = today;
    return *this;
}

int Date::get_month() const
{
    return m;
}

int Date::get_day()const
{
    return d;
}

int Date ::get_year()const
{
    return y;
}

void Date::check()
{
    if (y % 4 == 0)
    {
        days[2] = 29;
    }
    else
    {
        days[2] = 28;
    }
}

bool Date::isValidDate(int day, int month, int year) {
    if (year <= 0){
        cout << "Invalid year";
        return false;
    } 

    if (month < 1 || month > 12){
        cout << "Invalid month";
        return false;
    } 
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        daysInMonth[2] = 29;
    }

    if (day < 1 || day > daysInMonth[month]){
        cout << "Invalid day";
        return false;
    } 

    return true;
}


Date::Date(int day, int month, int year) {
    const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month < 1 || month > 12 || year <= 0) {
        cerr << "Invalid date in data: day=" << day << ", month=" << month << ", year=" << year << endl;
        throw runtime_error("Invalid date (month=" + to_string(month) + ", year=" + to_string(year) + ") to create!");
    }

    int daysInCurrentMonth = daysInMonth[month];
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        daysInCurrentMonth = 29;
    }

    if (day < 1 || day > daysInCurrentMonth) {
        throw runtime_error("Invalid date(day) to create!");
    }

    if (!isValidDate(day, month, year)) {
        cerr << "Invalid date: day=" << day << ", month=" << month << ", year=" << year << endl;
        throw runtime_error("Invalid date to create!");
    }


    d = day;
    m = month;
    y = year;
}


Date::~Date() {}

Date &Date::operator++()
{
    this->check();
    d += 1;
    if (d > days[m])
    {
        d = 1;
        m += 1;
        if (m > 12)
        {
            m = 1;
            y += 1;
        }
    }
    return *this;
}

Date Date::operator++(int)
{
    this->check();
    Date tmp = Date(d, m, y);
    this->operator++();
    return tmp;
}

Date &Date::operator--()
{
    this->check();
    d -= 1;
    if (d == 0)
    {
        m -= 1;
        if (m == 0)
        {
            y -= 1;
            m = 12;
            d = 31;
        }
        else
        {
            d = days[m];
        }
    }
    return *this;
}

Date Date::operator--(int)
{
    this->check();
    Date tmp = Date(d, m, y);
    this->operator--();
    return tmp;
}

ostream &operator<<(ostream &out, const Date &x)
{
    out << "Day: " << x.d << ", Month: " << x.m << ", Year: " << x.y << endl;
    return out;
}

istream &operator>>(istream &in, Date &x)
{
    cout << "Day: ";
    in >> x.d;
    cout << "Month: ";
    in >> x.m;
    cout << "Year: ";
    in >> x.y;
    Date check(x.d, x.m, x.y);
    return in;
}
string Date::toString() const{
	ostringstream oss;
    oss << d << " " << m << " " << y;
    return oss.str();
}

#include "Date.h"

// Giả sử Date có các thuộc tính: year, month, day
bool Date::operator<(const Date& other) const {
    if (y != other.y)
        return y < other.y;
    if (m != other.m)
        return m < other.m;
    return d < other.d;
}

Date Date::createDueDate(int monthsToAdd, const Date ngayMuon) {
    int newMonth = ngayMuon.m + monthsToAdd;
    int newYear = ngayMuon.y + (newMonth - 1) / 12;
    newMonth = (newMonth - 1) % 12 + 1;

    // Xử lý số ngày tối đa của tháng mới
    int daysInNewMonth = days_in_month(newMonth);
    int newDay = ngayMuon.d;

    if (newDay > daysInNewMonth) {
        newDay = daysInNewMonth;
    }

    return Date(newDay, newMonth, newYear);
}

void Date::adjustToValidDate() {
    check(); 
    if (d > days[m]) { 
        d -= days[m]; 
        m += 1;
        if (m > 12) { 
            m = 1;  
            y += 1;
        }
        check(); 
        adjustToValidDate(); 
    }
}

tm Date::toTm() const {
        tm tm_date = {};
        tm_date.tm_mday = d;
        tm_date.tm_mon = m - 1;  // Tháng bắt đầu từ 0
        tm_date.tm_year = y - 1900;  // Năm tính từ 1900
        return tm_date;
    }
