#include <iostream>
#include <limits>

#include "DoubleView.h"
#include "DoubleViewTest.h"

int main()
{
    // 1) ask for a double and show its memory representation
    double input = 0.0;
    std::cout << "Enter a double: ";
    std::cin >> input;

    DoubleView(input).show("The double you typed:");
    std::cout << '\n';

    // 2) show the "not-a-number" (NaN) representation
    double nanValue = std::numeric_limits<double>::quiet_NaN();
    DoubleView(nanValue).show("NaN (not a number) in memory:");
    std::cout << '\n';

    // bonus (optional): +infinity and -infinity
    double posInf = std::numeric_limits<double>::infinity();
    DoubleView(posInf).show("+infinity in memory:");
    std::cout << '\n';

    double negInf = -std::numeric_limits<double>::infinity();
    DoubleView(negInf).show("-infinity in memory:");
    std::cout << '\n';

    // 3) functional tests
    int failures = runAllDoubleViewTests();
    return failures == 0 ? 0 : 1;
}
