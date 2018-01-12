#include <cstdio>
#include "functions.h"
using namespace std;


/*
    function signatures:

    return_type FunctionName(type argument_name) {
        ... contents ...
    }

    // must be declared before it is called. 
    FunctionName(arg)

    // function defs are separate than the code that calls them. Ofen, you'll
    // see them declared above main, after which they can be defined.

    void func();
    int main(int argc, char ** argv) {... func() ...}
    void func() {...}

    // but more commonly, this is done in a header file. See functions.h.

*/

void f(int a) {
    // local copy is incremented, but caller's copy remains the same
    ++a;
}

void f(int *b) {
    // local copy is incremented, but caller's copy remains the same
    // dereference the pointer using the "*" operator to get at the value of b
    ++(*b);
}

int main( int argc, char ** argv ) {  // this is a function called by the system
    int a = 1;
    f(a);
    // arguments are passed by value, so this will print 1
    printf("a is %d\n", a);

    // call by reference is the alternative, and is done explicitly
    int b = 1;
    // use the reference operator to pass a pointer to b instead of the value of
    // b. The & is sometimes called the "address of" operator
    f(&b);
    printf("b is %d\n", b);

    // even though this function is defined below, it was declared in the header
    // file so it is usable.
    header_function();  
    return 0;
}

void header_function() {
    puts("This function was defined in the header file.");
}
