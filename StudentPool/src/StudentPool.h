#pragma once

// Homework 13: design patterns (factory method) with a doubly linked list.
//
// The trick: nodes are never thrown away. A NodeFactory ("factory class")
// keeps a doubly linked list of SPARE (unused) nodes; a StudentForm
// ("product class") keeps a doubly linked list of the nodes IN USE, sorted by
// student id.
//
//   - when a student is added, the form takes one node from the factory
//     (the factory allocates a new node only if its pool is empty);
//   - when a student is deleted, its node is returned to the factory's pool;
//   - at exit, every node (spare and in use) is deleted, so no memory leaks.

// A node of the doubly linked list.
struct StudentNode
{
    int id;
    int score;
    StudentNode* prev;
    StudentNode* next;

    StudentNode(int id = 0, int score = 0);
};

// Factory class: a doubly linked list of spare (unused) nodes.
class NodeFactory
{
public:
    NodeFactory();
    ~NodeFactory();            // delete every spare node left in the pool

    StudentNode* acquire();    // take one spare node (or allocate a new one)
    void release(StudentNode* node);   // put a node back into the pool

    int spareCount() const;    // how many spare nodes are waiting
    void deleteAllSpare();     // delete all spare nodes (used at exit)

private:
    StudentNode* head_;   // front of the spare list
    StudentNode* tail_;   // back of the spare list
};

// Product class: the doubly linked list of students in use, sorted by id.
// It borrows nodes from a NodeFactory and returns them when not needed.
class StudentForm
{
public:
    StudentForm(NodeFactory& factory);
    ~StudentForm();

    bool add(int id, int score);        // take a node from the factory, insert sorted
    bool removeFirst(int id);           // delete first with id; return its node to factory
    int  removeAllByScore(int score);   // return every node with score to the factory
    bool findScore(int id, int& score); // read the score of an id
    void showIdsByScore(int score);     // print ids whose score matches
    void printAll();                    // print the whole sorted form
    int  size() const;

    void returnAllToFactory();          // move every in-use node back to the factory

private:
    void insertSorted(StudentNode* node);   // keep the list sorted by id
    void unlink(StudentNode* node);         // remove node from this list

    NodeFactory& factory_;   // where spare nodes come from / go back to
    StudentNode* head_;      // front of the in-use list
    StudentNode* tail_;      // back of the in-use list
};
