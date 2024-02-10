// Programming Lab 5, created by Andrew Scott

#include <stdio.h>

// Function Prototypes

void minMax(int* a, int* b, int* c);					//Function prototypes declared before main().
void swap(int* a, int* b);

// Function Definitions

void minMax(int* a, int* b, int* c) {					// Function minMax gets passed three pointers from caller, does not return
														// a value.
	int max = *a;										 
	int min = *c;										// int max is assigned the dereferenced value of int a.
														// int min is assigned the dereferenced value of int c.

	if (max < *b) {										// IF statements determine which variable is biggest and which is
		max = *b;										// smallest, and assigns them as max and min as necessary
	}
	if (max < *c) {
		max = *c;
	}
	if (min > *a) {
		min = *a;
	}
	if (min > *b) {
		min = *b;
	}

	*a = max;											// The pointer of a is assigned the value of max.
	*c = min;											// The pointer of c is assigned the value of min.
	
	//printf("max is %d\n", max);						// Testing operation of function
	//printf("min is %d\n", min);
	
}

void swap(int* a, int* b) {								// Function swap gets passed two pointers from caller, does not return
														// a value.
	int swap = *a;										// Temporary variable swap is declared and assigned the value at a.
	*a = *b;											// Pointer a is assigned the value of pointer b
	*b = swap;											// Pointer b is assigned the value of swap (a)
}


// Main Function

int main(void)
{

	// Part A

	int a = 0;											// Three variables declared and initialized
	int b = 0;
	int c = 0;
	
	puts("Please input 3 integers: \n");
	scanf("%d %d %d", &a, &b, &c);						// User inputs values.

	int* aPtr = &a;										// Pointers initialized to variable addresses.
	int* bPtr = &b;
	int* cPtr = &c;

	minMax(&a, &b, &c);									// Function minMax called, passed the addresses of a, b, c as arguments.
	
	printf("\nThe Max value is: %d\n", a);				// Values are printed after function call.
	printf("The Min value is: %d\n\n", c);

	// Part B

	int swapA = 0;										// Two variables declared and initialized.
	int swapB = 0;

	puts("Please input 2 integers");
	scanf("%d %d", &swapA, &swapB);						// User inputs values.

	printf("\nThe values before swapping are:\n%d \n%d\n\n", swapA, swapB); // Values printed before swap function is called

	swap(&swapA, &swapB);													// Function swap called, addresses of swapA and swapB
																			// passed as arguments.

	printf("The values after swapping are:\n%d \n%d\n", swapA, swapB);		// Values are printed again after swap function is
																			// called.
	return 0;
}


