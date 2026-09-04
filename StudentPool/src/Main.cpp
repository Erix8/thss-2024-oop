#include <iostream>

#include "StudentPool.h"

static void showMenu()
{
    std::cout << "\nStudent form menu (factory pattern / node pool):\n"
              << "  1  add students (id score pairs; finish with id 0)\n"
              << "  2  delete the FIRST student with an id\n"
              << "  3  delete ALL students with a score\n"
              << "  4  show the score of a student (by id)\n"
              << "  5  show the ids of all students with a score\n"
              << "  6  show all students\n"
              << " -1  exit\n";
}

int main()
{
    NodeFactory factory;        // spare-node pool ("factory class")
    StudentForm form(factory);  // in-use list ("product class")

    int command = 0;
    bool running = true;
    while (running)
    {
        showMenu();
        std::cout << "Instruction: ";
        std::cin >> command;

        switch (command)
        {
        case 1:   // add several, one by one; each takes a node from the factory
        {
            std::cout << "Enter id score ... (finish with id 0):\n";
            int id = 0;
            int score = 0;
            while (true)
            {
                std::cin >> id;
                if (id == 0)
                {
                    break;
                }
                if (id < 0)
                {
                    std::cout << "Id must be positive. Ignored.\n";
                    continue;
                }
                std::cin >> score;
                if (score < 0)
                {
                    std::cout << "Score must be non-negative. Ignored.\n";
                    continue;
                }
                form.add(id, score);   // borrows a node from the factory
            }
            std::cout << "In-use now: " << form.size()
                      << "   spare in factory: " << factory.spareCount() << "\n";
            break;
        }

        case 2:   // delete first by id -> node returned to factory
        {
            int id = 0;
            std::cout << "Id to delete: ";
            std::cin >> id;
            if (id > 0 && form.removeFirst(id))
            {
                std::cout << "Deleted first id " << id << " (node returned).\n";
            }
            else
            {
                std::cout << "No student with id " << id << ".\n";
            }
            std::cout << "In-use now: " << form.size()
                      << "   spare in factory: " << factory.spareCount() << "\n";
            break;
        }

        case 3:   // delete all with a score -> nodes returned to factory
        {
            int score = 0;
            std::cout << "Score to delete all: ";
            std::cin >> score;
            int removed = (score >= 0) ? form.removeAllByScore(score) : 0;
            std::cout << "Removed " << removed << " student(s) with score "
                      << score << ".\n";
            std::cout << "In-use now: " << form.size()
                      << "   spare in factory: " << factory.spareCount() << "\n";
            break;
        }

        case 4:   // show score by id
        {
            int id = 0;
            int score = 0;
            std::cout << "Id: ";
            std::cin >> id;
            if (id > 0 && form.findScore(id, score))
            {
                std::cout << "Student(" << id << ") score is " << score << ".\n";
            }
            else
            {
                std::cout << "No student with id " << id << ".\n";
            }
            break;
        }

        case 5:   // show ids by score
        {
            int score = 0;
            std::cout << "Score: ";
            std::cin >> score;
            form.showIdsByScore(score);
            break;
        }

        case 6:   // show all
            form.printAll();
            break;

        case -1:
            running = false;
            break;

        default:
            std::cout << "Unknown instruction " << command << ".\n";
            break;
        }
    }

    // Exit: give every in-use node back, then free all nodes (no leaks).
    form.returnAllToFactory();
    std::cout << "Returned all in-use nodes; freeing "
              << factory.spareCount() << " nodes now.\n";
    factory.deleteAllSpare();

    std::cout << "Bye!\n";
    return 0;
}
