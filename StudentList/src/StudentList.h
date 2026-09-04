#pragma once

#include "Student.h"

// A doubly linked list of students. Homework 06 practises this week's lesson
// (pointers and references): every node is created with new and linked with
// prev/next pointers, and one output value is returned through a reference
// parameter (see findScoreById). The list always stays sorted by id ascending:
// add() inserts a single new student into its correct place.
class StudentList
{
public:
    StudentList();               // start with an empty list
    ~StudentList();              // delete every node

    bool add(int id, int score);        // insert one student, keep it sorted
    bool removeFirstById(int id);       // remove the first student with this id
    int  removeAllByScore(int score);   // remove every student with this score
    bool findScoreById(int id, int& score); // write the score back by reference
    void showIdsByScore(int score);     // print ids of all students with score
    void printAll();                    // print every student in list order
    int  size();                        // how many students are stored

private:
    struct Node
    {
        Student student;
        Node* prev;
        Node* next;

        Node(int id, int score, Node* p, Node* n)
            : student(id, score), prev(p), next(n) {}
    };

    Node* head_;
};
