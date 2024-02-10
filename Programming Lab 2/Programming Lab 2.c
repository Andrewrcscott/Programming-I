//Programming Lab 2, created by Andrew Scott 2023-09-20

#include <stdio.h>

int main(void)
{
	// 5.a

	puts("Part A\n");

	int a = 0;													// Declare and initialize all variables, incliding smallInt that will be 
	int b = 0;													// calculated after determining the smallest input integer
	int c = 0;
	int d = 0;
	int smallInt = 0;

	puts("Please input four integers:");						// Variable inputs and storing to memory
	scanf("%d %d %d %d", &a, &b, &c, &d);
	

	if (a < b && a < c && a < d) {								// Multiple && operators used in condition statement, if TRUE for all conditions, code proceeds
		printf("Integer %d is the smallest.\n", a);
		smallInt = a;											// First implementation of code had nested if...else statements in every code block 
		/*if (a % 3 == 0) {										// to perform remainder operations. Statements were removed for code clarity and remainder
			printf("The integer is a multiple of 3.\n");		// operation is added after code blocks.
		}														// If variable is determined to be smallest it is assigned the value of smallInt
		else {
			printf("The integer is not a multiple of 3\n");
		}*/
	}

	else if (b < a && b < c && b < d) {
		printf("Integer %d is the smallest.\n", b);
		smallInt = b;
		/*if (b % 3 == 0) {
			printf("The integer is a multiple of 3.\n");
		}
		else {
			printf("The integer is not a multiple of 3\n");
		}*/
	}

	else if (c < a && c < b && c < d) {
		printf("Integer %d is the smallest.\n", c);
		smallInt = c;
		/*if (c % 3 == 0) {
			printf("The integer is a multiple of 3.\n");
		}
		else {
			printf("The integer is not a multiple of 3\n");
		}*/
	}

	else {
		printf("Integer %d is the smallest.\n", d);
		smallInt = d;
		/*if (d % 3 == 0) {
			printf("The integer is a multiple of 3.\n");
		}
		else {
			printf("The integer is not a multiple of 3\n");
		}*/
	}

	if (smallInt % 3 == 0 && smallInt != 0) {				// If statement determines if the integer is a multiple of 3 by performing the mod (%) operation
		puts("The integer is a multiple of 3.\n");			// If answer is equal to 0, there is no remainder, therefore integer is a multiple of 3
															// smallInt cannot be 0 or else condition would be set to TRUE
	}

	else {
		puts("The integer is not a multiple of 3.\n");			// If a remainder is present, the integer is not a multiple of 3
	}



	// 5.b

	puts("Part B\n");

	float cost = 1.50;											// Variable declaration and initialization, we set cost to 1.50
	float funds = 0;											// printf length modifier .2 is used to print all values to 2 decimal places
	float change = 0;

	puts("\t\033[1;33mWELCOME!\033[0m\n");
	puts("One can of soda costs \033[1;32m$1.50\033[0m.\nPlease insert funds:");
	
	do {
		scanf("%f", &funds);							// Do...while loop is used to determine if the deposited funds are less than the 
														// cost of a soda. Initial scanf takes user input and assigns it to funds.
		if (funds < 0) {	
			puts("Error. Try again\n");					// Cannot enter a negative number
		}
																 												
		if (funds < 1.50 && funds >= 0) {				// Nested if loop determines if funds < 1.50 is TRUE and is not a negative number
																		
			printf("\nTotal funds is: \033[1;32m$%.2f\033[0m", funds);			
			float totalFunds = 0;												// FLOAT totalFunds is declared as a local variable, in order to add the additional
			puts("\nRequire more funds...");									// funds inputted from the user.
			printf("Funds required: \033[1;32m$%.2f\033[0m\n", (1.50 - funds));	// Calculation determines how much additional funds are required
			puts("Please insert funds:");
			scanf("%f", &totalFunds);							
			funds = funds + totalFunds;											// Adding totalFunds to funds assigning new value to funds
			
			if (funds < 1.50) {
				puts("\nInsufficient funds. Transaction cancelled\n");			// If user does not add enough funds, code breaks out of loop
				puts("Have a nice day!\n");
				break;
			}
			
		}
	} while (funds < cost);

	if (funds >= cost) {	
																// If funds >= cost is TRUE, amount of change is calculated and outputted with
		puts("\nThank you, enjoy!");							// thank you strings
		change = funds - cost;
		printf("Change is: \033[1;32m$%.2f\033[0m\n", change);
	}
	
	return 0;
}