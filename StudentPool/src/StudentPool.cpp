#include <iostream>

#include "StudentPool.h"

// --------------------------------------------------------------------------
// StudentNode
// --------------------------------------------------------------------------

StudentNode::StudentNode(int id, int score)
    : id(id), score(score), prev(0), next(0)
{
}

// --------------------------------------------------------------------------
// NodeFactory  (the spare-node pool, a doubly linked list)
// --------------------------------------------------------------------------

NodeFactory::NodeFactory() : head_(0), tail_(0)
{
}

NodeFactory::~NodeFactory()
{
    deleteAllSpare();
}

// Pop one spare node from the pool; if the pool is empty, make a new node.
StudentNode* NodeFactory::acquire()
{
    if (head_ == 0)
    {
        return new StudentNode();   // pool empty -> factory allocates
    }

    StudentNode* node = head_;
    head_ = node->next;
    if (head_ != 0)
    {
        head_->prev = 0;
    }
    else
    {
        tail_ = 0;
    }
    node->prev = 0;
    node->next = 0;
    return node;
}

// Push a node back into the pool (append at the tail).
void NodeFactory::release(StudentNode* node)
{
    node->prev = tail_;
    node->next = 0;
    if (tail_ != 0)
    {
        tail_->next = node;
    }
    else
    {
        head_ = node;
    }
    tail_ = node;
}

int NodeFactory::spareCount() const
{
    int count = 0;
    for (const StudentNode* p = head_; p != 0; p = p->next)
    {
        ++count;
    }
    return count;
}

void NodeFactory::deleteAllSpare()
{
    StudentNode* p = head_;
    while (p != 0)
    {
        StudentNode* next = p->next;
        delete p;
        p = next;
    }
    head_ = 0;
    tail_ = 0;
}

// --------------------------------------------------------------------------
// StudentForm  (the product list, sorted by id, borrowing nodes)
// --------------------------------------------------------------------------

StudentForm::StudentForm(NodeFactory& factory)
    : factory_(factory), head_(0), tail_(0)
{
}

StudentForm::~StudentForm()
{
    // The nodes belong to the factory; they are freed when the factory pool
    // is cleared (deleteAllSpare) at the end of the program.
    returnAllToFactory();
}

void StudentForm::insertSorted(StudentNode* node)
{
    // Insert so the list stays sorted by id (ascending).
    StudentNode* prev = 0;
    StudentNode* cur = head_;
    while (cur != 0 && cur->id < node->id)
    {
        prev = cur;
        cur = cur->next;
    }

    node->prev = prev;
    node->next = cur;
    if (prev != 0)
    {
        prev->next = node;
    }
    else
    {
        head_ = node;
    }
    if (cur != 0)
    {
        cur->prev = node;
    }
    else
    {
        tail_ = node;
    }
}

void StudentForm::unlink(StudentNode* node)
{
    if (node->prev != 0)
    {
        node->prev->next = node->next;
    }
    else
    {
        head_ = node->next;
    }
    if (node->next != 0)
    {
        node->next->prev = node->prev;
    }
    else
    {
        tail_ = node->prev;
    }
    node->prev = 0;
    node->next = 0;
}

bool StudentForm::add(int id, int score)
{
    StudentNode* node = factory_.acquire();   // borrow (or new) a node
    node->id = id;
    node->score = score;
    insertSorted(node);
    return true;
}

bool StudentForm::removeFirst(int id)
{
    for (StudentNode* p = head_; p != 0; p = p->next)
    {
        if (p->id == id)
        {
            unlink(p);
            factory_.release(p);   // give the node back to the factory
            return true;
        }
    }
    return false;
}

int StudentForm::removeAllByScore(int score)
{
    int removed = 0;
    StudentNode* p = head_;
    while (p != 0)
    {
        StudentNode* next = p->next;
        if (p->score == score)
        {
            unlink(p);
            factory_.release(p);
            ++removed;
        }
        p = next;
    }
    return removed;
}

bool StudentForm::findScore(int id, int& score)
{
    for (StudentNode* p = head_; p != 0; p = p->next)
    {
        if (p->id == id)
        {
            score = p->score;
            return true;
        }
    }
    return false;
}

void StudentForm::showIdsByScore(int score)
{
    bool any = false;
    for (StudentNode* p = head_; p != 0; p = p->next)
    {
        if (p->score == score)
        {
            std::cout << "  Student(" << p->id << ")\n";
            any = true;
        }
    }
    if (!any)
    {
        std::cout << "  No student has score " << score << ".\n";
    }
}

void StudentForm::printAll()
{
    if (head_ == 0)
    {
        std::cout << "  (no students yet)\n";
        return;
    }
    int index = 1;
    for (StudentNode* p = head_; p != 0; p = p->next)
    {
        std::cout << "  [" << index << "] Id(" << p->id
                  << "), Score(" << p->score << ")\n";
        ++index;
    }
}

int StudentForm::size() const
{
    int count = 0;
    for (const StudentNode* p = head_; p != 0; p = p->next)
    {
        ++count;
    }
    return count;
}

void StudentForm::returnAllToFactory()
{
    while (head_ != 0)
    {
        StudentNode* node = head_;
        unlink(node);
        factory_.release(node);
    }
}
