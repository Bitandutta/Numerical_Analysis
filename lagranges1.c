/*
   1. Forward and Backward tables creation
   2. Value finding using Forward difference
   3. Value finding using Backward difference
   4. Value finding using Lagranges
   
	x 0  1   2  3  4  5  6
	y 21 23 45 34 45 23 90
*/

// Lagranges
#include<stdio.h>
#include<math.h>

int main(){
	int tableSize, i, j;
	printf("Enter your table size: ");
	scanf("%d", &tableSize);
	
	float x[tableSize], y[tableSize], fx, num, den, result=0.0;
	
	printf("\nEnter the table contents:\n");
	for(i=0; i<tableSize; i++){
		printf("Enter x%d: ", i);
		scanf("%f", &x[i]);
		printf("Enter y%d: ", i);
		scanf("%f", &y[i]);
		printf("\n");
	}
	
	printf("Enter x that you want to find [f(x)]: ");
	scanf("%f", &fx);
	
	for(i=0; i<tableSize; i++){
		
		num=1.0;
		den=1.0;
		for(j=0; j<tableSize; j++){
			if(j==i) continue;
			num *= fx - x[j];    // numerator
			den *= x[i] - x[j];   // denominator
		}
		
		result += (num/den)*y[i]; // (num/den)*yi
	}
	
	printf("\n\nf(%0.2f) = %f", fx, result);
	return 0;
}
