#include <stdio.h>
//задача 1.2
struct A {
    A()           { printf("ctor(A )\n"); v = 1; }
    A(const A& x) { printf("ctor(A&)\n"); v = 2; }
    ~A()          { printf("~tor(A)\n");  v = 0; }

    int hello() const { return v; }

    int v;
};

void functionC(A a) {
    printf("inside copy: %d\n", a.hello());
}

void functionR(const A& a) {
    printf("inside refs: %d\n", a.hello());
}

void functionA(const A* a) {
    printf("inside addr: %d\n", a->hello());
}

void main() {
    A* p = nullptr;
    {
        A a;
        p = &a;
        functionC(a);
        functionR(a);
        functionA(p);
    }
    functionA(p);
}

/*
При запуске получим:
ctor(A )
ctor(A&)
inside copy: 2
~tor(A)
inside refs: 1
inside addr: 1
~tor(A)
inside addr: 0
*/