// Lab 1.cpp : Defines the entry point for the console application.
//
// Program to calculate the frequency of a 555 timer astable oscillator
//

#include "stdio.h"			// give access to printf and scanf functions

int main(int argc, char* argv[])
{
	float f;						// 
	double r1, r2, c1;				// declare the variables we will be using
	const double numerator=1.44;	// the constant numerator used in the frequency calculation

	printf("Enter the value of r1 in kilohms: ");    // enter the circuit values
	scanf("%lf",&r1);
	printf("Enter the value of r2 in kilohms: ");
	scanf("%lf",&r2);
	printf("Enter the value of c1 in microfarads: ");
	scanf("%lf",&c1);

	f=(numerator/((r1*1000+2.0*r2*1000)*c1*1e-6)); // calculate the frequency
	printf("\nThe oscillator frequency is: %-10.2lf Hz\n",f); // display the result

    getchar();
	getchar();
	getchar();
	getchar();
	
	return 0;
}

