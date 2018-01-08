#include <cstdio>
using namespace std;

void pointerIntro() {
    /*
    Notes:
    - The name of a variable is used as an index to map to a memory address and
    an associated data type. 
    - you can also create a variable that is a pointer to a value, rather than
    carrying the value itself.
    - "&" is called a reference operator, or more commonly the "address of"
    operator.
    - "*" the pointer de-reference operator, used to get at the value pointed to
    by the pointer.
    */ 
    int x;  // definition
    x = 1;  // assignment
    int y = x;  // both

    // pointer definition. memory is allocated in the size of a pointer
    int *ip;
    // the address of the variable integer x is placed into the pointer variable
    // named IP
    ip = &x;
    // copy the value pointed to by the ip variable, which currently porints to
    // the integer variable x, to the integer variable y.
    y = *ip;

    /*
        Think of a pointer as a piece of paper with the address of a house on it
        and the memory block it references as the actual house.
        https://tinyurl.com/y83teckh

        Dangling pointers
        The house is gone, but you forget to erase the address from your piece
        of paper. When you go to visit it, it isn't there

        Memory Leak
        You lose the piece of paper and cannot find the house. When you want to
        build a new house somehwere, you can't use the spot with the old one.
    */
}

void pointers() {
    // What is the purpose of a pointer? https://tinyurl.com/yasuxkwf
   
    int x = 7;
    int y = 42;
    int *ip = &x;

    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of *ip is %d\n", *ip);
    printf("The value of ip is %p\n", ip);  // this is the address of ip
    printf("The address of &ip is %p\n", &ip);
    printf("The address of &x is %p\n", &x);
}

void references() {
    int x = 7;
    int *ip = &x;
    // you can't define a ref without initializing it
    int &y = x;

    // all these print 7
    printf("The value of x is %d\n", x);
    // don't need to dereference the reference y, as you do with a pointer
    printf("The value of y is %d\n", y);
    printf("The value of *ip is %d\n", *ip);
    printf("\n");

    /*
        a reference is effectively immutable; once it referes to a variable, it
        will always refer to that same variable. 
    */

    int z = 149;
    ip = &z;
    y = z;
    // all these are 149. this is because ip is set to the value stored at the
    // address of z. y is a reference to x, and if we set y we set x through it.
    // This is why the value of x is also 149 here.
    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of *ip is %d\n", *ip);
    printf("The value of z is %d\n", z);

}

int main( int argc, char ** argv ) {
    // pointerIntro();
    pointers();
    // references();

    return 0;
}
