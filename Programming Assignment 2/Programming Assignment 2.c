// Programming Assignment 2, created by Andrew Scott

#include <stdio.h>
#include <stdlib.h>


void printBinary(unsigned int x);
void printByte(char c);

unsigned int packCharacters(char c[]) {							// function takes a string as the parameter
	
	unsigned int charShift = c[0];								// unsigned int variable is assigned the decimal value at 
																// string index [0].
	for (int i = 0;i < 4; i++) {								// Loop iterates through string indexes, each iteration prints
		printf("\nDecimal value is: %u\n", charShift);			// the decimal value of the current value of charShift, and calls
		printBinary(charShift);									// function printBinary to print the binary value of charShift.
		charShift = charShift << 8;								// charShift is then left shifted 8 bits, then the bitwise OR
		charShift = charShift | c[i + 1];						// operator is performed using the next string index.
	}		
	return charShift;
}

	void printBinary(unsigned int x) {
		int array[32];								// Loop iterates from i values 0-31, num is checked for remainder using modulo
		for (int i = 0; i < 32; i++) {				// No remainder will set array[i] to 0
			array[i] = x % 2;						// Any non-zero result indicates a remainder, so array[i] is set to 1
			x = x / 2;								// num is divided by 2 after every iteration.
		}

		printf("Binary value is:  ");

		for (int i = 31; i > -1; i--) {				// Loop prints the binary representaion starting at the end of the array
			printf("%d", array[i]);
			if (i % 8 == 0) 						// Spaces are added to separate bytes when i is divisible by 8 with no remainder (i = 24,16,8)
				putchar(' ');
		}
		puts("\n");
		
	}

	void printByte(char c) {						// Function printByte takes a single char as a parameter, and prints the 
		printf("The Binary value of %c is ", c);	// 8-bit binary equivalent of the character.

		int i = c;									// int i is assigned the decimal value of a character
		int array[8];
		for (int i = 0; i < 8; i++) {				
			array[i] = c % 2;
			c = c / 2;
		}
		
		for (int i = 7; i > -1; i--) {			// Loop prints the binary representaion starting at the end of the array
			printf("%d", array[i]);
			if (i % 8 == 0) 					
				putchar(' ');
		}
		puts("\n");				
	}
	

typedef struct totalOrder {						// Structure definition with 4 variables, 
	char name[30];
	int numTea;
	int numCoffee;
	float totalCost;
}order;

void fullOrder(struct totalOrder* i) {														// Function gets passed a pointer to the structure

	printf("\nOk %s, you ordered %d coffees and %d teas, your total comes to $%.2f.\n",		// i-> is used to dereference the
		i->name, i->numCoffee, i->numTea, i->totalCost);									// value at the address pointed to.
}


void printReceipt(struct totalOrder* j) {													// Function prints a receipt for the customer that
	puts("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");	
	printf("   Customer Name: %s\n\n", j->name);											// displays the # of each item ordered, and the total
	printf("    Coffee x %d   $%.2f\n\n", j->numCoffee, (float)(j->numCoffee) * 1.50);		// calculated with tax applied
	printf("    Tea    x %d   $%.2f\n\n", j->numTea, (float)(j->numTea) * 2.50);
	puts("------------------------------\n\n");
	printf("   Total + 13%% Tax   $%.2f\n\n", j->totalCost);
	puts("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
}

void totalCost(struct totalOrder* k) {											// totalCost calculates the total plus applicable tax
	(*k).totalCost = (((k->numCoffee) * 1.50) + ((k->numTea) * 2.50)) * 1.13;
}

void cb(void) {								// Function to clear scanf input stream
	char c = getchar();
	while (c != '\n' && c != EOF)
		c = getchar();
}

int main(void) {

	// Part A

	char proceed;

	char character[4];								// Character string is declared
	
	puts("Please enter the first character: ");		// User gets prompted for 4 characters, each is assigned to an index in the 
	character[0] = getchar();						// string
	cb();

	puts("Please enter the second character: ");
	character[1] = getchar();
	cb();

	puts("Please enter the third character: ");
	character[2] = getchar();
	cb();

	puts("Please enter the fourth character: ");
	character[3] = getchar();

	system("cls");

	for (int i = 0; i < 4; i++) {						// Loop iterates through string indexes, printing the 8-bit binary 
		printByte(character[i]);						// representation of the character.
	}	
	
	packCharacters(character);							// Function packCharacters is called passing the character string as the
														// argument.
	puts("Press any key to continue");	
	proceed = getchar();
	cb();
	system("cls");


	//Part B									// Section of code was referenced from Lab 7

	int numCustomers = 0;

	puts("Welcome to Java & Java! How many customers are there?\n");
	scanf("%d", &numCustomers);
	cb();

	order* orderArray;										// pointer orderArray pointing to struct order is declared
	orderArray = malloc(numCustomers * sizeof(order));		// memory is allocated to struct pointer using malloc, calculated by 
															// multiplying the number of customers by the size of the struct
	for (int i = 0; i < numCustomers; i++) {
		puts("\nHi! Can I get your name?\n");
		gets(orderArray[i].name);

		printf("\nHello %s!\n\n", orderArray[i].name);

		do {
			puts("How many coffees would you like?");
			scanf("%d", &orderArray[i].numCoffee);					// Number of coffees requested is stored at order1.numCoffee
																// Reprompts for input if request is less than 0
			if (orderArray[i].numCoffee < 0) {
				puts("\nSorry, we can't do that.\n");
			}
		} while (orderArray[i].numCoffee < 0);

		do {
			puts("\nOk, how many teas would you like?");
			scanf("%d", &orderArray[i].numTea);						// Number of teas requested is stored at order1.numTea
																// Reprompts for input if request is less than 0
			if (orderArray[i].numTea < 0) {
				puts("\nSorry, we can't do that.\n");
			}
		} while (orderArray[i].numTea < 0);

		totalCost(&orderArray[i]);								// totalCost and fullOrder functions are called, passing
		fullOrder(&orderArray[i]);								// orderArray pointer as argument			 
		
		puts("Next customer!");
		puts("\nPress any key to continue");
		proceed = getchar();
		cb();
		system("cls");
	}

	for (int i = 0; i < numCustomers; i++) {					// Loop iterates through each customer order, printing a 
		printReceipt(&orderArray[i]);							// receipt which includes the customer name, the # of coffees and
		puts("Press any key to continue");						// teas ordered, and the total cost with tax.
		proceed = getchar();		
		system("cls");
	}

	free(orderArray);										// Allocated memory is freed to avoid memory leaks.
	
	return 0;
}