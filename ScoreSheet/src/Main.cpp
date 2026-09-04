#include <iostream>
#include <string>

#include "ScoreSheet.h"

static void showMenu()
{
    std::cout << "\nScore-sheet menu:\n"
              << "  1  read a file and merge it into the sheet\n"
              << "  2  add a student (id + score)\n"
              << "  3  delete the student with an id\n"
              << "  4  delete ALL students\n"
              << "  5  change a student's score\n"
              << "  6  show one student's score\n"
              << "  7  show all students\n"
              << "  8  save the sheet to a file\n"
              << " -1  exit\n";
}

int main()
{
    ScoreSheet sheet;
    int command = 0;
    bool running = true;

    while (running)
    {
        showMenu();
        std::cout << "Instruction: ";
        std::cin >> command;

        switch (command)
        {
        case 1:   // read from a file
        {
            std::string filename;
            std::cout << "File to read: ";
            std::cin >> filename;
            if (sheet.readFromFile(filename))
            {
                std::cout << "Read OK (" << sheet.size() << " students now).\n";
            }
            else
            {
                std::cout << "Could not open " << filename << ".\n";
            }
            break;
        }
        case 2:   // add one student
        {
            int id = 0;
            float score = 0.0f;
            std::cout << "Id: ";
            std::cin >> id;
            std::cout << "Score: ";
            std::cin >> score;
            if (sheet.add(id, score))
            {
                std::cout << "Added id " << id << ".\n";
            }
            else
            {
                std::cout << "Id " << id << " already exists.\n";
            }
            break;
        }
        case 3:   // delete by id
        {
            int id = 0;
            std::cout << "Id to delete: ";
            std::cin >> id;
            std::cout << (sheet.remove(id)
                              ? "Deleted.\n"
                              : "No such id.\n");
            break;
        }
        case 4:   // delete everything
            sheet.clear();
            std::cout << "All students deleted.\n";
            break;
        case 5:   // change a score
        {
            int id = 0;
            float score = 0.0f;
            std::cout << "Id: ";
            std::cin >> id;
            std::cout << "New score: ";
            std::cin >> score;
            std::cout << (sheet.changeScore(id, score)
                              ? "Score changed.\n"
                              : "No such id.\n");
            break;
        }
        case 6:   // show one score
        {
            int id = 0;
            float score = 0.0f;
            std::cout << "Id: ";
            std::cin >> id;
            if (sheet.findScore(id, score))
            {
                std::cout << std::fixed << "id " << id << " -> score "
                          << score << '\n';
            }
            else
            {
                std::cout << "No such id.\n";
            }
            break;
        }
        case 7:   // show all
            sheet.printAll();
            break;
        case 8:   // save to a file
        {
            std::string filename;
            std::cout << "File to save: ";
            std::cin >> filename;
            if (sheet.writeToFile(filename))
            {
                std::cout << "Saved " << sheet.size() << " student(s).\n";
            }
            else
            {
                std::cout << "Could not open " << filename << ".\n";
            }
            break;
        }
        case -1:
            running = false;
            break;
        default:
            std::cout << "Unknown instruction " << command << ".\n";
            break;
        }
    }

    std::cout << "Bye!\n";
    return 0;
}
