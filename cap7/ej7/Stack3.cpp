//: C06:Stack3.cpp {O}
// Constructors/destructors
#include "Stack3.h"
#include "../require.h"
using namespace std;
Stack::Link::Link(void *dat, Link *nxt)
{
    data = dat;
    next = nxt;
}
Stack::Link::~Link() {}
Stack::Stack()
{
    head = 0;
}

Stack::Stack(void **arr, size_t size)
{
    head = 0;
    for (size_t i = 0; i < size; ++i)
        push(arr[i]);
}
void Stack::push(void *dat)
{
    head = new Link(dat, head);
}
void *Stack::peek()
{
    require(head != 0, "Stack empty");
    return head->data;
}
void *Stack::pop()
{
    if (head == 0)
        return 0;
    void *result = head->data;
    Link *oldHead = head;
    head = head->next;
    delete oldHead;
    return result;
}
Stack::~Stack()
{
    require(head == 0, "Stack not empty");
} ///:~