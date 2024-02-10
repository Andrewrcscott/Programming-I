// Programming Lab 6, created by Andrew Scott

#include <stdio.h>
#include <stdlib.h>

#define SIZE 30									// SIZE is declared 30

// Function Prototypes

void clearB(void) {								// Function clearB removes garbage characters from std input stream after using scanf
	char c = getchar();							// void function does not take any arguments or return any values
	while (c != '\n' && c != EOF)				// getchar() stores values at c, function loops until terminating characters are encountered.
	{
		c = getchar();
	}
}

char arrayValue(const char* array, int offset, int length);		// Function arrayValue gets passed a pointer to a constant char array, and two 
																// int values


void printString(char* array);									// Function get passed a pointer to a char array


int main(void) {

	// Part A

	char array[] = "leafs";										// Declare and initialze a 5-element array
	const char* ptr1 = array;									// Initialize a pointer to constant char array

	int index = 0;												// Declare and initialize int index to store user input

	puts("Part A\n\n");
	
	do {																			// DO...WHILE loop iterates at least once, prompting user for 
		puts("\nPlease enter an array index to display. input -1 to Exit.");		// input and comparing stored value to multiple IF statements
		scanf("%d", &index);														// while index is not -1.

		if (index >= 0 && index < ((sizeof(array) / sizeof(char))) - 1) {				// If index value is greater than ot equal to zero, and less 
			printf("\n%c\n", arrayValue(ptr1, index, (sizeof(array) / sizeof(char))));	// than the array size, prints the output of function arrayValue.
		} 																				// arrayValue passes the pointer to the array, and the index and array size 
																						// values as ints.

		if (index != -1 && index >= ((sizeof(array) / sizeof(char))) - 1) {						// If index value is not -1, and is greater than the 
			puts("\nCannot display value, requested index is greater than size of array.\n");	// array size, prints error message, and reprompts for input.
		}

		if (index == -1) {																// If index value is -1, loop terminates
			puts("\nExit\n");
		}

	} while (index != -1);

	
	// Part B

	puts("Part B\n\n");

	clearB();										// Function clearB is called to remove garbage characters from input stream
	
	char name[SIZE];								// char array is initialized to size SIZE (30)

	puts("Please enter name:\n");
	fgets(name, SIZE, stdin);						// fgets is used rather than scanf as a more secure input method (fgets prevents buffer 
													// overflow errors). fgets is passed a pointer to a string, the maximum size of the string 
	puts("");										// including terminating characters, and the input stream. 
		
	printString(name);								// Function printName is called, passes pointer to name as argument
	
	return 0;
}

//Function Definitions

char arrayValue(const char* array, int offset, int length) {
	
	int i = offset;												// int i is assigned the value of int offset.
	if (offset < length) {										// If the offset is less than the size of the array, function returns the 
		return *(array + i);									// value at the address of (array + i).
	}
	else return NULL;											// if offset is greater than or equal to length, returns NULL 
}

void printString(char* array) {
	
		for (int i = 0; i < strlen(array); i++) {				// FOR loop iterates through i as long as i is less than the size of the 
			printf("%c\n", *(array + i));						// array. Function prints a single character for every loop iteration, and i
		}														// increases by 1.
}