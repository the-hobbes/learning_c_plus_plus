#include <cstdio>
using namespace std;


void arrays() {
    int ia[5];
    ia[0] = 1;

    // array elements can also be accessed as if the array were a pointer. This
    // has the exact same effect as the statement on line 8; it sets the first
    // element of the array to be 1.
    *ia = 1;
    // define an integer pointer and assign the address of the array to the
    // pointer. You don't need the & operator to get an array's address, because
    // an array may be accessed as if it were a pointer.
    int *ip = ia;
    // this sets the first element of the array to 2
    *ip = 2;
    // you can increment the pointer to get at the next element of the array.
    ++ip;
    *ip = 3; // assign 3 to the second element of the array
    *(++ip) = 4; // increment and assign at once
    
    // initialize an array using an initializer list
    int ib[5] = {1, 2, 3, 4, 5};
}

void strings() {
	// a string is just a special case of an array of characters
	// char s[] = {'h', 'e', 'c', 'k'};
	char s[] = "heck"; // this would be the exact same thing as above
	printf("String is: %s\n", s);
	// you can access array elements too
	for (int i = 0; s[i]; ++i) {
		printf("char is %c\n", s[i]); 
	}
	printf("\n"); 
	// you can use pointers instead
	for (char * cp = s; *cp; ++cp) {
		printf("char is %c\n", *cp); 
	}
	// range-based loop: error: range-based ‘for’ loops are not allowed in C++98
	// for (char c : s) {
	// 	if(c == 0) break; // break out to avoid the null terminator at the end
	// 	printf("char is %c\n", c); 
	// }
}

// c-style arrays and strings
int main( int argc, char ** argv ) {
	// arrays();
	strings();


    return 0;
}