#pragma once

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

// Input format we define: first an integer "n", then n integers.
template <typename T>
void ReadNumbers(std::vector<T>& numbers)
{
    int count = 0;
    std::cout << "How many integers? ";
    std::cin >> count;

    std::cout << "Enter " << count << " integers: ";
    T value;
    for (int i = 0; i < count; ++i)
    {
        std::cin >> value;
        numbers.push_back(value);
    }
}

// Print the contents of a std::vector.
template <typename T>
void PrintNumbers(const std::vector<T>& numbers)
{
    for (std::size_t i = 0; i < numbers.size(); ++i)
    {
        std::cout << "[" << i << "] " << numbers[i] << "  ";
    }
    std::cout << "\n";
}

// Print the contents of a std::set.
template <typename T>
void PrintNumbers(const std::set<T>& numbers)
{
    std::size_t i = 0;
    for (typename std::set<T>::const_iterator it = numbers.begin(); it != numbers.end(); ++it, ++i)
    {
        std::cout << "[" << i << "] " << *it << "  ";
    }
    std::cout << "\n";
}
