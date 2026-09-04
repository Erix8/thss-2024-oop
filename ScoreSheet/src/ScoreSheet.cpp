#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "ScoreSheet.h"

std::size_t ScoreSheet::size() const
{
    return students_.size();
}

int ScoreSheet::indexOf(int id) const
{
    for (std::size_t i = 0; i < students_.size(); ++i)
    {
        if (students_[i].id() == id)
        {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void ScoreSheet::sortById()
{
    // Order the sheet by student id so the display is tidy.
    std::sort(students_.begin(), students_.end(),
              [](const Student& a, const Student& b) { return a.id() < b.id(); });
}

bool ScoreSheet::add(int id, float score)
{
    if (indexOf(id) >= 0)
    {
        return false;   // this id already exists
    }
    students_.push_back(Student(id, score));
    sortById();
    return true;
}

bool ScoreSheet::remove(int id)
{
    int pos = indexOf(id);
    if (pos < 0)
    {
        return false;
    }
    students_.erase(students_.begin() + pos);
    return true;
}

void ScoreSheet::clear()
{
    students_.clear();
}

bool ScoreSheet::changeScore(int id, float newScore)
{
    int pos = indexOf(id);
    if (pos < 0)
    {
        return false;
    }
    students_[static_cast<std::size_t>(pos)].setScore(newScore);
    return true;
}

bool ScoreSheet::findScore(int id, float& score) const
{
    int pos = indexOf(id);
    if (pos < 0)
    {
        return false;
    }
    score = students_[static_cast<std::size_t>(pos)].score();
    return true;
}

void ScoreSheet::printAll() const
{
    if (students_.empty())
    {
        std::cout << "  (the sheet is empty)\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    for (std::size_t i = 0; i < students_.size(); ++i)
    {
        std::cout << "  [" << i + 1 << "] id " << students_[i].id()
                  << "   score " << students_[i].score() << '\n';
    }
}

bool ScoreSheet::readFromFile(const std::string& filename)
{
    std::ifstream in(filename.c_str());
    if (!in)
    {
        return false;   // cannot open the file
    }

    int id = 0;
    float score = 0.0f;
    while (in >> id >> score)
    {
        int pos = indexOf(id);
        if (pos >= 0)
        {
            // the id is already in the sheet: update its score
            students_[static_cast<std::size_t>(pos)].setScore(score);
        }
        else
        {
            students_.push_back(Student(id, score));
        }
    }
    sortById();
    return true;
}

bool ScoreSheet::writeToFile(const std::string& filename) const
{
    std::ofstream out(filename.c_str());
    if (!out)
    {
        return false;
    }

    out << std::fixed << std::setprecision(2);
    for (std::size_t i = 0; i < students_.size(); ++i)
    {
        out << students_[i].id() << ' ' << students_[i].score() << '\n';
    }
    return true;
}
