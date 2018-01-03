#include <cstdio>
using namespace std;

int main( int argc, char ** argv )
{
    puts("Hello, World!");
    int x; // undefined integer variable
    x = 42;  // initialized integer variable
    // you can intitialize and define all in one, int x = 42.
    printf("x is %d\n", x); // %d for integers w/printf

    // constant variables can't change once they've been defined
    const int i = 7;
    printf("%d\n", i);
    // since i is a constant, if you tried to do i = 42; you'd get a compiler
    // error.
    return 0;
}

// expression = anything that returns a value
// statement = unit of code
