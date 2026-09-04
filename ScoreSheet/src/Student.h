#pragma once

// One student record in the sheet: a student id and a score.
class Student
{
public:
    Student(int id = 0, float score = 0.0f);

    int id() const;
    float score() const;
    void setScore(float score);

private:
    int id_;
    float score_;
};
