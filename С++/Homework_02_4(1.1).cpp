#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

struct A {
    A(const char* p)
        : s(new char[strlen(p) + 1])
    {
        strcpy(const_cast<char*>(s), p);
    }

    //new
    A(const A& other)
        : s(new char[strlen(other.s) + 1])
    {
        strcpy(const_cast<char*>(s), other.s);
    }
    //

    ~A() {
        delete s;
    }

    void print() {
        cout << s << endl;
    }

private:
    const char* s;
};

void main() {
    A a("Hello!");
    a.print();
    {
        A copy(a);
        copy.print();
    }
    a.print();
}