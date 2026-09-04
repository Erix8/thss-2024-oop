#include <iostream>

#include "Shape.h"
#include "Triangle.h"
#include "Square.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include "Circle.h"

int main()
{
    int count = 0;               // how many shapes have been drawn
    double totalPerimeter = 0.0; // running total of perimeters
    double totalArea = 0.0;      // running total of areas

    while (true)
    {
        std::cout << "\nChoose a shape to add:\n"
                  << "  1 Triangle\n"
                  << "  2 Square\n"
                  << "  3 Pentagon\n"
                  << "  4 Hexagon\n"
                  << "  5 Circle\n"
                  << "  0 Finish and show totals\n"
                  << "> ";

        int command = 0;
        std::cin >> command;

        if (command == 0)
        {
            break;
        }
        if (command < 1 || command > 5)
        {
            std::cout << "Unknown command. Try again." << std::endl;
            continue;
        }

        std::cout << (command == 5 ? "Enter radius: " : "Enter side length: ");
        double size = 0.0;
        std::cin >> size;

        if (size <= 0.0)
        {
            std::cout << "Invalid size." << std::endl;
            continue;
        }

        ++count;

        // Build the matching concrete shape and use it (inheritance at work:
        // each derived class remembers its size and knows its own math).
        switch (command)
        {
        case 1:
        {
            Triangle shape(size);
            totalPerimeter += shape.perimeter();
            totalArea += shape.area();
            std::cout << "Triangle: perimeter = " << shape.perimeter()
                      << ", area = " << shape.area() << '\n';
            break;
        }
        case 2:
        {
            Square shape(size);
            totalPerimeter += shape.perimeter();
            totalArea += shape.area();
            std::cout << "Square: perimeter = " << shape.perimeter()
                      << ", area = " << shape.area() << '\n';
            break;
        }
        case 3:
        {
            Pentagon shape(size);
            totalPerimeter += shape.perimeter();
            totalArea += shape.area();
            std::cout << "Pentagon: perimeter = " << shape.perimeter()
                      << ", area = " << shape.area() << '\n';
            break;
        }
        case 4:
        {
            Hexagon shape(size);
            totalPerimeter += shape.perimeter();
            totalArea += shape.area();
            std::cout << "Hexagon: perimeter = " << shape.perimeter()
                      << ", area = " << shape.area() << '\n';
            break;
        }
        case 5:
        {
            Circle shape(size);
            totalPerimeter += shape.perimeter();
            totalArea += shape.area();
            std::cout << "Circle: perimeter = " << shape.perimeter()
                      << ", area = " << shape.area() << '\n';
            break;
        }
        }
    }

    // Command 0 reached: report how many shapes were drawn and their totals.
    std::cout << "\nShapes drawn: " << count << '\n';
    std::cout << "Total perimeter: " << totalPerimeter << '\n';
    std::cout << "Total area: " << totalArea << std::endl;

    return 0;
}
