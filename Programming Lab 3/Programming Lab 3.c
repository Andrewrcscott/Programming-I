// Programming Lab 3, created by Andrew Scott

#include <stdio.h>

int main(void)
{
	// 5.a

	puts("Part A\n");

	int int1 = 0;									// Declare and initialize variables for both integers, as well as a variable for
	int int2 = 0;									// the sum of the integers within the range, and a counter for the # of integers in the range
	int sum = 0;
	int counter = 0;

	puts("Please input 2 different integers.");

	scanf("%d %d", &int1, &int2);					// User inputs both integers

	if (int1 < int2) {								// Enters IF code block when int1 is less than int2

		for (++int1; int1 < int2; int1++)			// FOR loop starts at the first number after int1 (++i), iterates as long as int1 is less 
													// than int2, post-increasing by 1 after every iteration (i++)

			if (int1 % 2 == 0) {					// Every int in the FOR loop is calculated using the modulo operator, if the remainder is 0
													// int 1 is added to int sum, and the counter is increased by 1
				counter == counter++;				// If the remainder is not 0, the loop continues to the next integer in the range
				sum = sum + int1;

				//printf("\033[0;32m%d\033[0m ", int1);		// Printf statements were used to verify even integers are being counted, the sum
				//printf("\033[0;33m%d\033[0m ", sum);		// is increasing after each iteration, and the counter is increasing by 1 after 
				//printf("\033[0;34m%d\033[0m ", counter);	// every iteration
			}												// int1 set to green, sum set to yellow, counter set to blue
	}

	if (int2 < int1) {										// Enters IF code block when int2 is less than int1
															// Same operations performed as above
		for (++int2; int2 < int1; int2++)
			
			if (int2 % 2 == 0) {
				counter == counter++;
				sum = sum + int2;
			}
	}

	//printf("\nThe sum of the even integers between the inputs is %d.\n", sum);		// Displays the sum of the integers in the range
	//printf("There are %d even integers in the range.\n", counter);					// Displays the # of integers in the range
														
	if (counter >= 1) {
		printf("The average of the even integers between the inputs is %d.\n", (sum / counter));		// Displays the average of the integers in the range
	}
	else {
		puts("Cannot calculate average");
	}
	


	// 5.b				// Code was referenced from LAB 2, modified to continue prompting for addtional funds

	puts("\nPart B\n");

	float cost = 2.50;											// Variable declaration and initialization, we set cost to 2.50
	float funds = 0;											// printf length modifier .2 is used to print all values to 2 decimal places
	float change = 0;

	puts("\t\033[1;33mWELCOME!\033[0m\n");
	puts("One can of soda costs \033[1;32m$2.50\033[0m.\nPlease insert funds:");

	do {
		scanf("%f", &funds);							// DO...WHILE loop is used to determine if the deposited funds are less than the 
														// cost of a soda. Initial scanf takes user input and assigns it to funds.
		if (funds < 0) {
			puts("Error. Try again\n");					// Cannot enter a negative number
		}

		while (funds < 2.50 && funds >= 0) {				// WHILE loop displays the total funds and any additional funds required

			printf("\nTotal funds is: \033[1;32m$%.2f\033[0m", funds);
			float totalFunds = 0;												// FLOAT totalFunds is declared as a local variable, in order to add the additional
			puts("\nRequire more funds...");									// funds inputted from the user.
			printf("Funds required: \033[1;32m$%.2f\033[0m\n", (2.50 - funds));	// Calculation determines how much additional funds are required
			puts("Please insert funds:");
			scanf("%f", &totalFunds);
			funds = funds + totalFunds;											// Adding totalFunds to funds assigning new value to funds
						
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


