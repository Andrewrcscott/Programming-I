//Programming Assignment 1, created by Andrew Scott 2023-10-10

#include <stdio.h>
#define N 5												// Constant value defined as N, where N is the number of students in the 
														// class. N is used throughout main() as an int variable.

// Function Prototypes
														// Function prototypes declared before main, three return no values, two
void printArray(double[], int);							// return double values.

void avgArray(double[], double[], double[], int);

void maxArray(double[], double[], double[], int);

double classAverage(double[], int);

double classMax(double[], int);


// Main Function

int main(void) {

	double lab1Grades[N];										// Four double arrays declared with size N
	double lab2Grades[N];
	double labsAvg[N];											// labsAvg and labsMax aren't initialized until functions avgArray
	double labsMax[N];											// and maxArray are called.

	printf("Enter grades for Lab 1 for %d students: \n", N);
	
	for (int i = 0; i < N; i++) {								// lab1Grades array values are assigned using a FOR loop, user
																// inputs values and are stored at incrementing array indices.
			scanf("%lf", &lab1Grades[i]);							
			if (lab1Grades[i] < 0) {							// Checks inputs for negative number, if negative, prints error and 
				puts("Error, cannot enter negative number");	// decrements i by 1 to retry input.
				i--;
			}
	}

	printf("\nEnter grades for Lab 2 for %d students: \n", N);

	for (int j = 0; j < N; j++) {								// Same input iteration as above for lab2Grades array
		scanf("%lf", &lab2Grades[j]);							// Same negative value detection, decrementing j by 1 to retry input.
		if (lab2Grades[j] < 0) {
			puts("Error, cannot enter negative number");
			j--;
		}
	}
		
	printf("\nThe Class Average for Lab 1 is: %.2lf\n", (classAverage(lab1Grades, N)));
	printf("The Class Average for Lab 2 is: %.2lf\n", (classAverage(lab2Grades, N)));
																// Function classAverage is called twice, passing lab1Grades and 
																// lab2Grades arrays, and N as the array size.

	printf("\nThe Class Maximum for Lab 1 is: %.2lf\n", (classMax(lab1Grades, N)));
	printf("The Class Maximum for Lab 2 is: %.2lf\n", (classMax(lab2Grades, N)));
																// Function classMax is called twice, passing lab1Grades and 
																// lab2Grades arrays, and N as the array size.

	avgArray(lab1Grades, lab2Grades, labsAvg, N);				// Function avgArray is called, passing lab1Grades, lab2Grades,
																// and labsAvg arrays, and N as array size


	maxArray(lab1Grades, lab2Grades, labsMax, N);				// Function maxArray is called, passing lab1Grades, lab2Grades,
																// and labsMax arrays, and N as array size

	puts("\n\n");

	// printf("%.2f %.2f %.2f %.2f %.2f", labsAvg[0], labsAvg[1], labsAvg[2], labsAvg[3], labsAvg[4]);
	// Above line verifies labsAvg values are initialized during function avgArray call

	return 0;
}


// Function Definitions

void printArray(double printArray[], int c) {						// Function printArray takes an array parameter and 
	for (int i = 0; i < c; i++) {									// a single int parameter for array size.
		printf("%.2f  ", printArray[i]);							// Function iterates through array indices and prints to screen.
	}																// Modifier .2 is used to display 2 decimal points
}

void avgArray(double lab1[], double lab2[], double avg[], int c) {	// Function avgArrat takes three array paramaters and a
																	// single int parameter for array size. Function iterates 
	for (int i = 0; i < c; i++) {									// through both array values at i, finds the average of the 
		avg[i] = (lab1[i] + lab2[i]) / 2;							// values and stores them in array avg[].  
	}																// Function then calls printArray and passes array avg[] and 
																	// int c.
	printf("\nThe Average Grade of the two labs for each student is: ");
	printArray(avg, c);
	
}

void maxArray(double lab1[], double lab2[], double max[], int c) {	// Function maxArray takes three array parameters and a 
																	// single int parameter for array size. Function iterates
	for (int i = 0; i < c; i++) {									// through both array values at i, and determines which 
		if (lab1[i] > lab2[i])										// value is the greatest, and assigns the value to max[i].
			max[i] = lab1[i];										// Function then calls printArray and passes array max[] and 
		else max[i] = lab2[i];										// int c.
	}
	printf("\n\nThe Max Grade of the two labs for each student is: ");
	printArray(max, c);
}

double classAverage(double average[], int i) {						// Function classAverage takes a single array and a single
																	// int parameter for array size. Double sum is declared and 
	double sum = 0;													// initialized to 0. Function iterates through FOR loop, and
	for (int i = 0; i < N; i++) {									// the array values are added to sum. 
		sum += average[i];											// The function returns a double which is the sum divided
	}																// by the size of the array
	return (sum / N);
}

double classMax(double classMax[], int c) {							// Function classMax takes a single array and a single 
																	// int parameter for array size. int max is assigned the value 
	int max = classMax[0];											// of the first index in the array. The function iterates 
	for (int i = 1; i < c; i++) {									// through the FOR loop and determines if the value is 
		if (classMax[i] > max)										// greater than max. If yes, max is assigned the new array
			max = classMax[i];										// value. Max is returned as a double
	}
	return max;
}