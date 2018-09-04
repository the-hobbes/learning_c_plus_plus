#include <cstdio>
using namespace std;

// preprocessor directives start with the # sign
#define ONE 1
#define HELLO_STRING "hello world"

int main( int argc, char ** argv )
{
    printf("value is %d\n", ONE);
    printf("the string is %s\n", HELLO_STRING);
    // this is an actual c++ constant.
    const int one = 1; 
    return 0;
}

