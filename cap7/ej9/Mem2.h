//: C07:Mem2.h
#ifndef MEM2_H
#define MEM2_H
typedef unsigned char byte;
class Mem
{
    byte *mem;
    int size;
    void ensureMinSize(int minSize);
    byte* old_mem; // nuevo miembro de datos

public:
    Mem(int sz = 0);
    ~Mem();
    int msize();
    byte *pointer(int minSize = 0);
    bool moved(); // nuevo método
};
#endif // MEM2_H ///:~./    