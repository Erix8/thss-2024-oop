#include <iostream>

#include "Calendar.h"

int main()
{
    // Build an instance whose date is today, then move it n days.
    Calendar today;
    std::cout << "Today is ";
    today.print();
    std::cout << std::endl;

    std::cout << "Enter n (days to move; any integer, e.g. negative goes back): ";
    int n = 0;
    std::cin >> n;

    today.addDays(n);

    std::cout << "After " << n << " days it is ";
    today.print();
    std::cout << std::endl;

    return 0;
}
