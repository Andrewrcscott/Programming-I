// Lab 8, created by Andrew Scott

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cb(void) {											// Function to clear scanf input stream
	char c = getchar();
	while (c != '\n' && c != EOF)
		c = getchar();
}

void countFunction(void) {								// Void function takes no arguments and returns nothing
	static int i = 0;									// Static int i is initialized, local to function. Every time function is called 
	i = i + 1;											// i is increased by 1.
	printf("The function has printed %d times\n", i);
}

unsigned int reverseBinary(unsigned int num) {			// function reverseBinary takes unsigned int as argument, returns unsigned int
	
	int array[32];										// Array of size 32 is declared, as well as an unsigned int rnum acting as a placeholder
	unsigned int rnum = num;							// for the reversed decimal number.
	
	printf("You entered %u with bits ", num);

	for (int i = 0; i < 32; i++) {						// Loop iterates from i values 0-31, num is checked for remainder using modulo operator
		array[i] = num % 2;								// No remainder will set array[i] to 0
		num = num / 2;									// Any non-zero result indicates a remainder, so array[i] is set to 1
	}													// num is divided by 2 after every iteration.

	for (int i = 31; i > -1; i--) {						// Loop prints the binary representaion of num starting at the end of the array
		printf("%d", array[i]);
		if (i % 8 == 0) 								// Spaces are added to separate bytes when i is divisible by 8 with no remainder (i = 24,16,8)
			putchar(' ');
	}
	putchar('\n');

	printf("The reversed-bit number is: %u with bits ", reverseNum(rnum));		// print functions calls reverseNum function passing rnum as argument

	for (int i = 1; i <= 32; i++) {							// Loop prints the reversed binary representation, starting at beginning of array
		printf("%d", array[i-1]);							// array[i-1] is used to prevent byte spacing error when i = 0, since 0 % 8 = 0
		if (i % 8 == 0)						
			putchar(' ');
	}
		
	return reverseNum(rnum);
}

unsigned int reverseNum(unsigned int num) {

	int array[32];										// Array of size 32 is declared, and two variables initialized, sum and totalSum.
	unsigned int sum = 0;								
	unsigned int totalSum = 0;
	
	for (int i = 0; i < 32; i++) {						// Similar to reverseBinary, the loop iterates from 0-31 and values at array[i] are
		array[i] = num % 2;								// assigned 0 or 1 depending on the modulo operator.
		num = num / 2;
	}

	
	for (int i = 31; i > -1; i--) {						// Loop iterates through all values of i, if a 1 is encountered, the pow() function 
		if (array[i] == 1)								// takes the base number (2) and raises it to the power of (31-i)
			sum = pow(2, 31-i);
		totalSum = totalSum + sum;						// sum is added to totalSum for every iteration, then sum is reset to 0 to prevent 
		sum = 0;										// continued adding during iterations.
	}
	return totalSum;
}



int main(void) {

	// Part A

	puts("\nPart A\n");

	countFunction();			// countFunction is called several times to verify function operation
	countFunction();
	countFunction();
	countFunction();
	countFunction();

	// Part B

	unsigned int num = 0;										// Unsigned int is initialized, capable of 32 bits, values from 0 to 4,294,967,295
		
	puts("\n\nPart B\n\nPlease enter an unsigned integer (Minimum 0, Maximum 4,294,967,295):");
	scanf("%u", &num);
	cb();
			
	reverseBinary(num);											// Function reverseBinary is called passing unsigned int as argument.
																
	//printf("The output is %u", reverseBinary(num));			// Verify return value from function call.
			
	return 0;
}