#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

#include "NumberSort.h"

int main()
{
    // 1) Read a list of integers (our defined input format).
    std::vector<int> original;
    ReadNumbers(original);

    std::cout << "\nOriginal order:\n";
    PrintNumbers(original);

    // 2) Sort with algorithm::sort - duplicates are kept.
    std::vector<int> withDuplicates = original;
    std::sort(withDuplicates.begin(), withDuplicates.end());
    std::cout << "Sorted with sort() (duplicates kept):\n";
    PrintNumbers(withDuplicates);

    // 3) Sort with std::set - duplicates are removed automatically.
    std::set<int> withoutDuplicates;
    withoutDuplicates.insert(original.begin(), original.end());
    std::cout << "Sorted with set (duplicates removed):\n";
    PrintNumbers(withoutDuplicates);

    return 0;
}
