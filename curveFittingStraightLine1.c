#include<stdio.h>
#include<math.h>

// straight line curve fitting
int main(){
	
	int tableSize, i, j;
	printf("Enter table size: ");
	scanf("%d", &tableSize);
	
	float m[2][tableSize];
	float sumX=0.0, sumY=0.0, sumXY=0.0, sumXX=0.0;
	float slope, intercept;
	
	for(i=0; i<tableSize; i++){ // i point the column
		
		printf("\nEnter x%d: ", i);
		scanf("%f", &m[0][i]);
		printf("Enter y%d: ", i);
		scanf("%f", &m[1][i]);
		
		sumX += m[0][i];
		sumY += m[1][i];
		sumXY += m[0][i]*m[1][i];
		sumXX += m[0][i]*m[0][i];
		
	}
	
	slope = ((tableSize*sumXY) - (sumX*sumY))/(tableSize*sumXX-(sumX*sumX));
	intercept = (sumY - (slope*sumX))/tableSize;
	
	// y = slope*x + intercept
	
	printf("\nThe equation of the straight line is:\ny = %fx + %f", slope, intercept);
	
	return 0;
	
}
