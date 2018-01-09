#include <iostream>  // includes cout.
using namespace std;


int main( int argc, char ** argv ) {

    // cout is a class that overloads the bitwise left shift operator to send a
    // stream of characters to the standard output stream. 
    // sending hello world and a class called endl to cout.
    cout << "Hello, World!" << endl;
    cout << 2 * 17 << endl;  // doesn't have to be strings

    // why use puts and printf instead? semantics, but also because 
    // c++ -static -o hello-puts hello-puts.cpp (-static means statically
    // compile so we don't use shared libraries, so we can see the actualy size
    // of the generated binary.)
    // so if you generate a version with printf, puts and cout, you'll notice
    // the size of the cout binary is quite a bit larger since in needs to bring
    // in a bunch of the STL library to support how it works.

    return 0;
}