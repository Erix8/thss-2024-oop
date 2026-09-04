#include <iostream>

#include "StudentList.h"

static void showMenu()
{
    std::cout << "\nMain menu:\n"
              << "  1  Add students (id score pairs, stop with id 0)\n"
              << "  2  Delete the FIRST student with a given id\n"
              << "  3  Delete ALL students with a given score\n"
              << "  4  Show the score of the first student with a given id\n"
              << "  5  Show ids of ALL students with a given score\n"
              << "  6  Show all students\n"
              << " -1  Exit\n";
}

int main()
{
    StudentList list;   // always sorted by id ascending

    int command = 0;
    bool running = true;
    while (running)
    {
        showMenu();
        std::cout << "Instruction: ";
        std::cin >> command;

        switch (command)
        {
        case 1:   // add several students, one by one, keeping the order
        {
            int id = 0;
            int score = 0;
            std::cout << "Enter id score ... (finish with id 0):\n";
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
                list.add(id, score);   // inserts one node in sorted place
            }
            std::cout << "Students now:\n";
            list.printAll();
            break;
        }

        case 2:   // delete the first student with the given id
        {
            int id = 0;
            std::cout << "Delete by id. Id: ";
            std::cin >> id;
            if (id <= 0)
            {
                std::cout << "Id must be positive.\n";
            }
            else if (list.removeFirstById(id))
            {
                std::cout << "Removed the first student with id " << id << ".\n";
            }
            else
            {
                std::cout << "No student with id " << id << ".\n";
            }
            std::cout << "Students now:\n";
            list.printAll();
            break;
        }

        case 3:   // delete all students with the given score
        {
            int score = 0;
            std::cout << "Delete by score. Score: ";
            std::cin >> score;
            if (score < 0)
            {
                std::cout << "Score must be non-negative.\n";
            }
            else
            {
                int removed = list.removeAllByScore(score);
                std::cout << "Removed " << removed << " student(s) with score "
                          << score << ".\n";
                std::cout << "Students now:\n";
                list.printAll();
            }
            break;
        }

        case 4:   // show score of the first student with the given id
        {
            int id = 0;
            std::cout << "Show score by id. Id: ";
            std::cin >> id;
            int score = 0;
            if (id > 0 && list.findScoreById(id, score))   // score comes back by reference
            {
                std::cout << "Student(" << id << ") score is " << score << ".\n";
            }
            else
            {
                std::cout << "No student with id " << id << " (id must be positive).\n";
            }
            break;
        }

        case 5:   // show ids of all students with the given score
        {
            int score = 0;
            std::cout << "Show ids by score. Score: ";
            std::cin >> score;
            if (score < 0)
            {
                std::cout << "Score must be non-negative.\n";
            }
            else
            {
                list.showIdsByScore(score);
            }
            break;
        }

        case 6:   // show all students
            list.printAll();
            break;

        case -1:  // exit
            running = false;
            break;

        default:
            std::cout << "Unknown command " << command << ". Try again.\n";
            break;
        }
    }

    std::cout << "Bye!\n";
    return 0;
}
