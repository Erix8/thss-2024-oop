#include <ctime>
#include <iostream>

#include "Calendar.h"

// Today's date, read from the system clock.
Calendar::Calendar()
{
    std::time_t now = std::time(nullptr);
    std::tm local;
#ifdef _WIN32
    localtime_s(&local, &now);
#else
    local = *std::localtime(&now);
#endif

    year_ = local.tm_year + 1900;   // tm_year is years since 1900
    month_ = local.tm_mon + 1;      // tm_mon is 0..11
    day_ = local.tm_mday;
}

Calendar::Calendar(int year, int month, int day) : year_(2000), month_(1), day_(1)
{
    setDate(year, month, day);
}

bool Calendar::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Calendar::daysInMonth(int year, int month)
{
    static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year))
    {
        return 29;
    }
    return days[month];
}

void Calendar::setYear(int year)
{
    year_ = year;   // any integer is fine
}

void Calendar::setMonth(int month)
{
    if (month >= 1 && month <= 12)
    {
        month_ = month;
    }
    else
    {
        std::cout << "Month must be between 1 and 12. Change ignored." << std::endl;
    }
}

void Calendar::setDay(int day)
{
    int maxDay = daysInMonth(year_, month_);
    if (day >= 1 && day <= maxDay)
    {
        day_ = day;
    }
    else
    {
        std::cout << "Day " << day << " is not valid for " << year_ << "-" << month_
                  << " (max " << maxDay << "). Change ignored." << std::endl;
    }
}

void Calendar::setDate(int year, int month, int day)
{
    year_ = year;
    month_ = 1;             // temporary safe month, then really set below
    day_ = 1;
    setMonth(month);
    setDay(day);
}

int Calendar::getYear()
{
    return year_;
}

int Calendar::getMonth()
{
    return month_;
}

int Calendar::getDay()
{
    return day_;
}

void Calendar::addDays(int n)
{
    if (n == 0)
    {
        return;
    }

    day_ += n;

    if (n > 0)   // carry overflow into later months/years
    {
        while (day_ > daysInMonth(year_, month_))
        {
            day_ -= daysInMonth(year_, month_);
            ++month_;
            if (month_ > 12)
            {
                month_ = 1;
                ++year_;
            }
        }
    }
    else   // borrow from earlier months/years
    {
        while (day_ < 1)
        {
            --month_;
            if (month_ < 1)
            {
                month_ = 12;
                --year_;
            }
            day_ += daysInMonth(year_, month_);
        }
    }
}

void Calendar::print()
{
    std::cout << year_ << "-" << month_ << "-" << day_;
}
