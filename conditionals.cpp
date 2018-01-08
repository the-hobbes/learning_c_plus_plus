#include <cstdio>
using namespace std;


int main(int argc, char const *argv[]) {
	int x = 42;
	int y = 7;
	if (x > y) {
		puts("x > y"); 
	}
	else if (x < y) {
		puts("x < y");
	} 
	else {
		puts("they must be equal");
	}

	// ternary expression- alternate answers based on an expression
	// condition ? return_value_if_true : return_value_if_false
	printf("The greater is: %d\n", x > y ? x : y); 

	// switch statements. choose between possibilities.
	// (need constants)
	const int iONE = 1;
	const int iTWO = 2;
	const int iTHREE = 3;
	const int iFOUR = 4;
	const int iTWENTY = 20;

	int z = 20;

	switch (z) {
		case iONE:
			puts("1");
			break;
		case iTWO:
		case iTWENTY:
			puts("2 or 20");
			break;
		case iTHREE:
			puts("3");
			break;
		case iFOUR:
			puts("4");
			break;
		default:
			puts("default");
			break;
	}

	return 0;
}