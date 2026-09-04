#pragma once

#include <string>
#include <vector>

#include "Student.h"

// The current score sheet: a list of students (id + score), edited from the
// console and saved to / loaded from a text file.
//
// FILE FORMAT (design): one student per line:  "<id> <score>"
//   e.g.  2023010001 90.5
// Only plain data is written (no header/footer text), so a file saved with
// writeToFile() is read back exactly by readFromFile().
class ScoreSheet
{
public:
    // command 2: add a student; false if the id already exists.
    bool add(int id, float score);

    // command 3: remove the student with this id.
    bool remove(int id);

    // command 4: remove every student.
    void clear();

    // command 5: change the score of an existing student.
    bool changeScore(int id, float newScore);

    // command 6: get a student's score (true if found; score written back).
    bool findScore(int id, float& score) const;

    // command 7: show all students.
    void printAll() const;

    // command 1: read the sheet from a file and merge it in.
    bool readFromFile(const std::string& filename);

    // command 8: write the whole sheet to a file (round-trippable).
    bool writeToFile(const std::string& filename) const;

    std::size_t size() const;   // how many students are stored

private:
    int indexOf(int id) const;   // -1 if not found
    void sortById();

    std::vector<Student> students_;
};
