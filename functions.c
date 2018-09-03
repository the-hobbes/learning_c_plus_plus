#include <cstdio>
#include <cstdarg>
#include <string>
#include "functions.h"

using namespace std;

// compile and run:
// g++ -std=c++0x functions.c -o functions && ./functions

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

// Overloadding f, possible because it has a different signature.
void f(int *b) {
    // The caller's copy is incremented by 1.
    // dereference the pointer using the "*" operator to get at the value of b
    ++(*b);
}

void dangerReference(int & c) {
    // Passing references instead of pointers. By using the reference operator,
    // we arepulling the reference instead of the value, and the calling code 
    // doesn't know about it (just passes c in as normal).
    c = 73;

    // this can be prevented by setting the variable to read-only, using const
    // e.g., dangerReference(const int & c) {...}
}

void staticExample() {
    static int i = 1;
    printf("i is... %d\n", ++i);
}

int returnExample(int i) {
    return i * 2;
}

const string & largeReturnExample() {
    // Use static memory when return values are large and should avoid the 
    // stack. Constant is used here to avoid side-effects like the string being
    // changed in the caller.
    static string s = "This is a static string";
    return s;
}

void functionPointerExample() {
    printf("Made it to functionPointerExample!\n");
}

// Function pointer jump table.
const char * prompt();
int jump(const char *);

void fa() {puts("This is fa");}
void fb() {puts("This is fb");}
void fc() {puts("This is fc");}

// Array of function pointers (the address of the 3 functions and a null pointer
// to terminate the list).
void (*funcs[])() = {fa, fb, fc, nullptr};

const char * prompt() {
    puts("Choose and option:");
    puts("1, Function fa()");
    puts("2, Function fb()");
    puts("3, Function fc()");
    puts("Q, Quit.");
    printf(">> ");

    fflush(stdout); // flush stdout buffer after prompt
    const int kbuffsz = 16; // constant for buffer size
    static char response[kbuffsz]; // static storage for response buffer
    fgets(response, kbuffsz, stdin); // gets the response from the console

    return response;
}

int jump(const char * rs) {
    // we only care about the first element of the array returned from prompt()
    char code = rs[0];
    // break out of the while() in main()
    if(code == 'q' || code =='Q') return 0;

    // count the length of the funcs array
    int func_length = 0;
    while(funcs[func_length] != NULL) func_length++;

    int i = (int) code - '0'; // convert ascii numeral from stdin to int
    i--; // list is 0-based
    if(i < 0 || i >= func_length){
        puts("invalid choice");
        return 1;
    } else {
        funcs[i](); // call the function pointer stored at position i
        return 1;
    }
}

// overloading operators with functions.
class A {
    int a;
public:
    // We can overload integers
    A (const int &a) : a(a) {}
    // and have one method for returning a value
    const int & value() const {return a;}
};
// Operator overload function here, accepting 2 A's and calling the value()
// function to do the adding.
// 'operator' is a keyword, and the '+' is the operator that will be overloaded.
// there are some rules governing what operators can be overloaded in what ways.
int operator + (const A & lhs, const A & rhs) {  // references, for space saving
    puts("operator + for class A");
    return lhs.value() + rhs.value();
}

// Variadic arguments
// The first arg is an int count of arguments passed in. The `...` represents
// a variable number of arguments which are doubles across which we want to
// compute the average.
/// Macros are provided by the cstdarg header.
double average(const int count, ...) {
    va_list ap; // macro used to declare the list of arguments in `...`
    double total = 0.0;

    // macro used to determine where the start of the variadic arguments is 
    // across all arguments in this function (those variadic ones start right
    // after `count` up in the function signature).
    va_start(ap, count);
    for(int i = 0; i < count; i++) {
        // va_arg macro grabs the next macro from the list and declares its type
        total += va_arg(ap, double);
    }
    // macro to do some bookkeeping and indicate you are done with the variadic
    // arguments.
    va_end(ap);
    return total / count;
}

// pretty much how printf works, adds some formatting around strings
int message(const char * fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    // pass the whole list of arguments to the vfprintf function from the std
    // library.
    int rc = vfprintf(stdout, fmt, ap);
    puts("");
    va_end(ap);
    return rc;
}

unsigned long int factorial(unsigned long int n) {
    // n * n-1
    if(n < 2) return 1; // base case
    return factorial(n - 1) * n;
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

    // The more common way to do this, by accepting the reference in the 
    // function rather than passing a pointer and dereferencing it later. The
    // main reason references were created.
    int c = 42;
    dangerReference(c);
    printf("c is %d\n", c);  // prints 73

    // Static keyword allocates objects to persistent static (x-function)
    // storage instead of automatic storage on the stack.
    staticExample(); // 1
    staticExample(); // 2, since the value is carried between invocations.

    // even though this function is defined below and not before it is used, it
    // was declared in the header file so it is usable.
    header_function();

    // Static storage space vs stack (automatic) returns
    printf("return value is: %d\n", returnExample(42));
    // c_str gives the string value repr of the returned static string reference
    printf("return value is: %s\n", largeReturnExample().c_str());

    // Function pointer, used to call functions through a pointer.
    // Return type of the function pointer needs to match.
    void (*fp)() = functionPointerExample;
    fp();
    // Jump tables can be implemented with function pointers.
    while(jump(prompt()));
    puts("\nDone");

    // Overloading operators with functions.
    A z(7);
    A x(42);
    printf("result of overloaded addition: %d\n", z + x);

    // Variadic argument examples
    message("Here's some message, variadic.");
    // remember, the first arg to average() is the number of args.
    message("The average is: %lf", average(4, 1.0, 2.0, 3.0, 4.0));  // 2.5

    //Recursion
    unsigned long int n = 10;
    printf("10 factorial is: %lu\n", factorial(n));

    return 0;
}

void header_function() {
    puts("This function was defined in the header file.");
}
