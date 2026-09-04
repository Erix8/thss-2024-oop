#pragma once

// A single student record: a positive id and a non-negative score.
class Student
{
public:
    Student(int id = 0, int score = 0);

    int id;      // student number (positive)
    int score;   // grade (0 or more)
};
