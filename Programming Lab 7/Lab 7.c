// Lab 7, created by Andrew Scott


#include <stdio.h>
#include <stdlib.h>


struct customerOrder {						// Structure definition with 3 variables
	char name[30];
	int numTea;
	int numCoffee;
	float totalCost;
};

typedef struct customerOrder order;			// typedef used to set customerOrder synonym to order


// Function Definitions


void cb(void) {								// Function to clear scanf input stream
	char c = getchar();
	while (c != '\n' && c != EOF)
		c = getchar();
}

void fullOrder(struct customerOrder* i) {																// Function gets passed a pointer to the structure
	
	printf("\nOk %s, you ordered %d coffees and %d teas, your total comes to $%.2f.\n",					// i-> is used to dereference the
		i->name, i->numCoffee, i->numTea, i->totalCost);												// value at the address pointed to.
}


void printReceipt(struct customerOrder* j) {															// Function prints a receipt for the customer that
	puts("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");														// displays the # of each item ordered, and the total
	printf("    Coffee x %d   $%.2f\n\n", j->numCoffee, (float)(j->numCoffee) * 1.50);					// calculated with tax applied
	printf("    Tea    x %d   $%.2f\n\n", j->numTea, (float)(j->numTea) * 2.50);
	puts("------------------------------\n\n");
	printf("   Total + 13%% Tax   $%.2f\n\n", j->totalCost);
	puts("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
}

void totalCost(struct customerOrder* k) {																// totalCost calculates the total plus applicable tax
	(*k).totalCost = (((k->numCoffee) * 1.50) + ((k->numTea) * 2.50)) * 1.13;
}

// Main Program


int main(void) {

	order order1;														// Struct member order1 is declared

	puts("Welcome to Java & Java! Can I get your name?\n");
	gets(order1.name);													// User inputs name, string is stored at order1.name

	printf("\nHello %s!\n\n", order1.name);								

	do {
		puts("How many coffees would you like?");
		scanf("%d", &order1.numCoffee);									// Number of coffees requested is stored at order1.numCoffee
		cb();															// Reprompts for input if request is less than 0
		if (order1.numCoffee < 0) {
			puts("\nSorry, we can't do that.\n");
		}
	} while (order1.numCoffee < 0);

	do {
		puts("\nOk, how many teas would you like?");
		scanf("%d", &order1.numTea);									// Number of teas requested is stored at order1.numTea
		cb();															// Reprompts for input if request is less than 0
		if (order1.numTea < 0) {
			puts("\nSorry, we can't do that.\n");
		}
	} while (order1.numTea < 0);

	totalCost(&order1);
	fullOrder(&order1);													// totalCost, fullOrder and printReceipt functions are called, passing			 
	printReceipt(&order1);												// the address of member order1 as the argument

	return 0;
}