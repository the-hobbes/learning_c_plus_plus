#include <cstdio>
using namespace std;


int main(int argc, char const *argv[]) {
	int a[5] = {1, 2, 3, 4, 5};

	// while loop
	int i = 0;
	while(i < 5) {
		printf("char is %d\n", a[i]);
		++i;
	}
	puts("\n");
	
	// do while does the condition check at the end instead of the beginning
	i = 0;
	do {
		printf("char is %d\n", a[i]);
		++i;
	} while (i < 5);
	puts("\n");

	// for loop
	for (int i = 0; i < 5; ++i)	{
		printf("char is %d\n", a[i]);
	}
	puts("\n");
	// for using pointers and a string
	char s[] = "string";
	for (char * cp = s; *cp; ++cp) {  // *cp; is a shortcut for "is true?"
		printf("char is %c\n", *cp); 
	}
	puts("\n");

	// range-based loop: error: range-based ‘for’ loops are not allowed in C++98
	// for (char c : s) {
	// 	if(c == 0) break; // break out to avoid the null terminator at the end
	// 	printf("char is %c\n", c); 
	// }
	
	return 0;
}