#include <iostream>

#include "StudentList.h"

StudentList::StudentList() : head_(0) {}

StudentList::~StudentList()
{
    Node* p = head_;
    while (p != 0)
    {
        Node* next = p->next;
        delete p;
        p = next;
    }
    head_ = 0;
}

// Insert one student so the list stays sorted by id (ascending).
bool StudentList::add(int id, int score)
{
    Node* node = new Node(id, score, 0, 0);
    if (node == 0)
    {
        return false;   // out of memory
    }

    // Walk to the first node whose id is >= the new id.
    Node* prev = 0;
    Node* cur = head_;
    while (cur != 0 && cur->student.id < id)
    {
        prev = cur;
        cur = cur->next;
    }

    // Link the new node between prev and cur.
    node->prev = prev;
    node->next = cur;
    if (prev != 0)
    {
        prev->next = node;
    }
    else
    {
        head_ = node;   // inserted at the front
    }
    if (cur != 0)
    {
        cur->prev = node;
    }
    return true;
}

// Remove the first node whose id matches.
bool StudentList::removeFirstById(int id)
{
    Node* cur = head_;
    while (cur != 0)
    {
        if (cur->student.id == id)
        {
            // Unlink cur from its neighbours.
            if (cur->prev != 0)
            {
                cur->prev->next = cur->next;
            }
            else
            {
                head_ = cur->next;
            }
            if (cur->next != 0)
            {
                cur->next->prev = cur->prev;
            }
            delete cur;
            return true;
        }
        cur = cur->next;
    }
    return false;   // no such id
}

// Remove every node with the given score; returns how many were removed.
int StudentList::removeAllByScore(int score)
{
    int removed = 0;
    Node* cur = head_;
    while (cur != 0)
    {
        Node* next = cur->next;
        if (cur->student.score == score)
        {
            if (cur->prev != 0)
            {
                cur->prev->next = cur->next;
            }
            else
            {
                head_ = cur->next;
            }
            if (cur->next != 0)
            {
                cur->next->prev = cur->prev;
            }
            delete cur;
            ++removed;
        }
        cur = next;
    }
    return removed;
}

// Look up a student by id and write the score back through the reference
// parameter (this is where a function sends a result out by reference).
bool StudentList::findScoreById(int id, int& score)
{
    const Node* cur = head_;   // read-only scan: pointer to const Node
    while (cur != 0)
    {
        if (cur->student.id == id)
        {
            score = cur->student.score;
            return true;
        }
        cur = cur->next;
    }
    return false;   // not found
}

void StudentList::showIdsByScore(int score)
{
    bool any = false;
    const Node* cur = head_;   // read-only scan: pointer to const Node
    while (cur != 0)
    {
        if (cur->student.score == score)
        {
            std::cout << "  Student(" << cur->student.id << ")\n";
            any = true;
        }
        cur = cur->next;
    }
    if (!any)
    {
        std::cout << "  No student has score " << score << ".\n";
    }
}

void StudentList::printAll()
{
    if (head_ == 0)
    {
        std::cout << "  (no students yet)\n";
        return;
    }

    int index = 1;
    const Node* cur = head_;   // read-only scan: pointer to const Node
    while (cur != 0)
    {
        std::cout << "  [" << index << "] Id(" << cur->student.id
                  << "), Score(" << cur->student.score << ")\n";
        ++index;
        cur = cur->next;
    }
}

int StudentList::size()
{
    int count = 0;
    const Node* cur = head_;   // read-only scan: pointer to const Node
    while (cur != 0)
    {
        ++count;
        cur = cur->next;
    }
    return count;
}
