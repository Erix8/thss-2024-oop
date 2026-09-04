#include <cstdlib>

#include "FuPrinter.h"

int main()
{
    // Build a FuPrinter for our chosen “福” pattern and draw it.
    FuPrinter printer('&');
    printer.drawFu();

#ifdef _WIN32
    system("pause"); // keep the console window open on Windows
#endif
    return 0;
}

