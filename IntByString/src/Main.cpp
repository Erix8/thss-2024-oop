#include "IntByStringTest.h"

int main()
{
    int failures = runAllIntByStringTests();
    return failures == 0 ? 0 : 1;
}
