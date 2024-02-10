// PROG1955 Programming Lab 1, created by Andrew Scott  Sept. 12, 2023

#include <stdio.h>

int main(void)
{
	//5.a
	
	int mile = 0;		// 5.a.i Declare and initialize both variables as INT data type. Calculation kilo = mile * 1.609 will give correct integer values,
	int kilo = 0;		//		 but decimal values are truncated due to INT data types.  We can simply ignore INT kilo and cast INT mile as a FLOAT
	
	puts("Part A\n");
	puts("Welcome, please enter the miles to be converted: ");
	scanf("%d", &mile);

	//kilo = ((float)8 / 5) * (float)mile;
	//printf("Kilometers is:\n%.2f\n\n", (float)mile * 1.609);
	printf("Kilometers is: \n%.2f\n\n", ((float)8 / 5) * (float)mile);	/* 5.a.ii Format control % f is required to output a floating point value.
																				  INT mile and one of the integers are cast as FLOAT in argument in order 
																				  to display decimal values.

																		   5.a.iii .2 precision modifier is used to display value to two decimal places. */
	
	//5.b
	
	long l;
	long double ld;
	
	puts("Part B\n");
	printf("The size of Long Int l is %zd bytes.\n", sizeof(l));			// Size of Long Int is 4 bytes
	printf("The size of Long Double ld is %zd bytes.\n\n", sizeof(ld));	// Size of Long Double is 8 bytes
																		// Both values are platform & compiler dependent

	//5.c

	int costBattery = 1000;
	int costTotal = costBattery * 200;
	
	puts("Part C\n");
	printf("The total cost of batteries is $%hd \tOutput as SHORT\n", costTotal);
	printf("The total cost of batteries is $%d \tOutput as INT\n", costTotal);		/* Expected value is incorrect, outputted as 3392, expected answer is 200, 000.
																					   This is due to integer overflow, SHORT can only hold values from 0-65535.
																					   200000 mod 65535 = 3395, which is the approximate output displayed by printf.
																					   Changing variable data type to INT solves problem */
	
	return 0;
}

	
												