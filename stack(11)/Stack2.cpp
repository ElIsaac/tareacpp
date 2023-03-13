//: C04:Stack.cpp {O}
// Linked list with nesting
#include "Stack2.h"
#include "require.h"
#include <iostream>
using namespace std;
void
Stack::Link::initialize(void* dat, Link* nxt) {
data = dat;
next = nxt;
}
void Stack::initialize() { head = 0; }
void Stack::push(void* dat) {
Link* newLink = new Link;
newLink->initialize(dat, head);
head = newLink;
}
void* Stack::peek() {
require(head != 0, "Stack empty");
return head->data;
}
void* Stack::pop() {
if(head == 0) return 0;
void* result = head->data;
Link* oldHead = head;
head = head->next;
delete oldHead;
return result;
}
void Stack::cleanup() {
require(head == 0, "Stack not empty");
} ///:~
using namespace std;
int main(int argc, char* argv[]) {
requireArgs(argc, 1); // File name is argument
ifstream in(argv[1]);
assure(in, argv[1]);
Stack textlines;
textlines.initialize();
string line;
// Read file and store lines in the Stack:
while(getline(in, line))
textlines.push(new string(line));
// Pop the lines from the Stack and print them:
string* s;
while((s = (string*)textlines.pop()) != 0) {
cout << *s << endl;
delete s;
}
textlines.cleanup();
} ///:~