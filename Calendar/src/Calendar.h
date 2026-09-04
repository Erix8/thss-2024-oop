#pragma once

// Homework 04 is about ENCAPSULATION. A Calendar remembers a year, month and
// day, but keeps that data private: the only way to change it is through the
// validated setters below, so month is always 1..12 and day is always a real
// day of the Gregorian calendar (no 31 Feb, no 32 Jan, no 29 Feb unless leap).
class Calendar
{
public:
    Calendar();                          // today's date (from the system clock)
    Calendar(int year, int month, int day);

    void setYear(int year);              // any integer year is allowed
    void setMonth(int month);            // must be 1..12
    void setDay(int day);                // must be valid for the stored month
    void setDate(int year, int month, int day);

    int getYear();
    int getMonth();
    int getDay();

    void addDays(int n);                 // n can be 0, positive or negative
    void print();

private:
    bool isLeapYear(int year);           // Gregorian leap-year rule
    int daysInMonth(int year, int month);

    int year_;
    int month_;
    int day_;
};
