// compile and run with
// g++ hello.cpp -o hello && ./hello

// This is a directive for the preprocessor, not actually c++ code. It takes a
// file, in this case a standard library file called cstdio, and includes it
// into this current file.
#include <cstdio>
#include <iostream>  // for cout below

// tells the compiler we are using a namespace with this code. The compiler will
// look in the std namespace for functions if it doesn't find them in the current
// unit (file). This is done so we don't need to write std:puts, and can just
// write puts instead (for any std library function).
using namespace std;

// main() is the entry point for any c++ program. There can be only one and it
// must exist. The standard arguments are optional, but should be present. They
// get arguments from the command line.
int main( int argc, char ** argv )
{
    puts("Hello, World!");  // print a string to the console w/a newline. 
    // sometimes you'll see printf, but that doesn't add a newline.
    // sometimes you'll see it with cout, which will need an <iostream>, and
    // will look like this:
    cout << "Hello, World!\n";
    return 0;  // the main function must return an integer value
}
