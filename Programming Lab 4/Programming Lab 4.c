// Programming Lab 4, created by Andrew Scott

#include <stdio.h>

// Part A

// Function Prototypes

int smallest(int num1, int num2, int num3, int num4);	// Function prototypes declared before main()
														// int smallest() takes 4 arguments
int isMultipleOf3(int number);							// int isMultipleOf3() takes 1 argument


double oddAverage(int a, int b);						// Function oddAverage() takes 2 arguments and returns a double

// Main Program

int main(void) {

	puts("Part A\n");

	int intA = 0;										// Declaring and initializing 4 int variables
	int intB = 0;
	int intC = 0;
	int intD = 0;

	puts("Please enter 4 integers:\n");					// Prompt for user input, assigning variables to addresses
	scanf("%d %d %d %d", &intA, &intB, &intC, &intD);

	printf("\nThe smallest integer is %d\n", smallest(intA, intB, intC, intD));	// printf statement calls function smallest() and passes 
																				// 4 variables to function
	
	printf("Is %d a multiple of 3?\n", smallest(intA, intB, intC, intD));

	if (isMultipleOf3(smallest(intA, intB, intC, intD)) == 1) {			// Calls function isMultipleOf3, argument being passed is
		printf("Yes, the integer is a multiple of 3.\n\n");				// return value of function smallest.
	}																	// If the return value is 1, the integer is a multiple of 3
	else
		printf("No, the integer is not a multiple of 3.\n\n");			// If the return value is 0, the integer is not a mulitple 
																		// of 3.
	



	// Part B

	puts("Part B\n");

	
	int int1 = 0;
	int int2 = 0;

	puts("Please input two different integers: ");
	scanf("%d %d", &int1, &int2);

	if (int1 < int2) {										// Calls function oddAverage and passes int1 and int2 as arguments
		printf("\nThe average of the odd integers between the inputs is %.1lf\n", oddAverage(int1, int2));
	}											

	if (int1 > int2) {										// Calls function oddAverage and passes int2 and int1 as arguments
		printf("\nThe average of the odd integers between the inputs is %.1lf\n", oddAverage(int2, int1));
	}

	if (int1 == int2)										// Prevents duplicate number inputs
		puts("Error, please try again\n");

	return 0;
}

// Function Definitions

int smallest(int num1, int num2, int num3, int num4) {		// Function int smallest() defined after main(), receives 4 arguments
	int smallest = num1;									// Local variable int smallest is assigned the value of num1
	if (smallest > num2)									// If statements determine which int is smallest, also handles duplicate
		smallest = num2;									// integers
	if (smallest > num3)
		smallest = num3;
	if (smallest > num4)
		smallest = num4;
	return smallest;										// returns int smallest to main()
}

int isMultipleOf3(int number) {								// Function int isMultipleOf3 receives 1 argument
	int multiple = number;									// Local variable int multiple is assigned the value of int number
	if (multiple % 3 == 0 && multiple != 0)					// If remainder of variable / 3 is 0 and the variable is not 0, function
		return 1;											// returns 1 to main().
	else
		return 0;											// If remainder is greater than 0, functions returns 0 to main().
	}

double oddAverage(int a, int b) {							// Function oddAverage receives two arguments and returns a double.
	int counter = 0;										// Local variables counter and sum are used inside function to 
	int sum = 0;											// calculate the # of integers and the sum of odd integers.
	for (++a; a < b; a++)
															// FOR loop iterates through all values from the first number after 
		if (a % 2 != 0) {									// int a, to the integer before int b
			//printf("\033[0;32m%d\033[0m ", a);			// IF statement determines if integer is an odd integer, if the remainder 
			counter == counter++;							// of an integer divided by 2 is 0, the number is even.
			sum = sum + a;									// if condition is true, counter increases by 1, and integer is added 
		}													// to sum total.
	if (counter < 1)
		puts("Cannot calculate average");					// If counter does not increase, no value to calculate, prints error
	//printf("\033[0;33m%d\033[0m ", sum);
	//printf("\033[0;34m%d\033[0m ", counter);
	double oddAverage = (double)sum / counter;				// oddAverage is calculated by dividing the sum by the number of integers
	return oddAverage;										// in the range, and returned to caller as a double.
}