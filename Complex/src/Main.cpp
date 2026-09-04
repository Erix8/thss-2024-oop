#include "ComplexTest.h"

int main()
{
    int failures = runAllComplexTests();
    return failures == 0 ? 0 : 1;
}
