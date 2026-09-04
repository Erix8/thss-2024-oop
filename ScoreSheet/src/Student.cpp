#include "Student.h"

Student::Student(int id, float score) : id_(id), score_(score) {}

int Student::id() const
{
    return id_;
}

float Student::score() const
{
    return score_;
}

void Student::setScore(float score)
{
    score_ = score;
}
