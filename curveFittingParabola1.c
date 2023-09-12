#include<stdio.h>
#include<math.h>

// ax^2 + bx + c (parabola) curve fitting
int main(){
	
	int tableSize, i, j;
	printf("Enter table size: ");
	scanf("%d", &tableSize);
	
	float m[2][tableSize];
	float sumX=0.0, sumY=0.0, sumXY=0.0, sumXX=0.0, sumXXX=0.0, sumXXY=0.0, sumXXXX=0.0;
	float a, b, c;
	
	for(i=0; i<tableSize; i++){ // i point the column
		
		printf("\nEnter x%d: ", i);
		scanf("%f", &m[0][i]);
		printf("Enter y%d: ", i);
		scanf("%f", &m[1][i]);
		
		sumX += m[0][i];
		sumY += m[1][i];
		sumXY += m[0][i]*m[1][i];
		sumXX += m[0][i]*m[0][i];
		sumXXX += pow(m[0][i], 3);
		sumXXY += m[0][i]*m[0][i]*m[1][i];
		sumXXXX += pow(m[0][i], 4);
		
	}
	
	float mt[3][4], t;
	
	// gauss elimination
	mt[0][0] = sumXX;
	mt[0][1] = sumX;
	mt[0][2] = tableSize;
	mt[0][3] = sumY;
	
	mt[1][0] = sumXXX;
	mt[1][1] = sumXX;
	mt[1][2] = sumX;
	mt[1][3] = sumXY;
	
	mt[2][0] = sumXXXX;
	mt[2][1] = sumXXX;
	mt[2][2] = sumXX;
	mt[2][3] = sumXXY;
	/*
	printf("\nEquation Matrix\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%0.2f\t", mt[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/
	t = mt[1][0]/mt[0][0]; // step 1
	for(i=0; i<4; i++){
		mt[1][i] -= t*mt[0][i]; // R2 = R2 - tR1
	}
	
	t = mt[2][0]/mt[0][0]; // step 2
	for(i=0; i<4; i++){
		mt[2][i] -= t*mt[0][i];  // R3 = R3-tR1
	}
	
	t = mt[2][1]/mt[1][1]; // step 3
	for(i=0; i<4; i++){
		mt[2][i] -= t*mt[1][i];  // R3 = R3-tR2
	}
	
	c = mt[2][3]/mt[2][2];
	b = (mt[1][3]- (c*mt[1][2])) / mt[1][1];
	a = (mt[0][3] - (c*mt[0][2]) - (b*mt[0][1])) / mt[0][0];
	
	printf("\nThe equation of the parabola is:\ny = %fx^2 + %fx + %f", a, b, c);
	
	return 0;
	
}
