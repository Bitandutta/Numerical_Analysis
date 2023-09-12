// Forward Interpolation

#include<stdio.h>
#include<math.h>

int main(){
	int tableSize, i, j, k;
	printf("Enter tabler size: ");
	scanf("%d", &tableSize);
	
	float fdt[tableSize][tableSize+1], x, u, result=0.0;
	
	// user input
	for(i=0; i<tableSize; i++){
		printf("Enter x%d: ", i);
		scanf("%f", &fdt[i][0]); // column 0
		printf("Enter y%d: ", i);
		scanf("%f", &fdt[i][1]); // column 1
		printf("\n");
	}
	
	for(i=0; i<tableSize-1; i++){ // fdt created
		
		for(j=0; j<tableSize-1-i; j++){
			fdt[j][i+2] = fdt[j+1][i+1] - fdt[j][i+1];
		}
	}
	
	printf("Forward difference table\n\n");

	for(i=0; i<tableSize; i++){
		
		for(j=0; j<=tableSize-i; j++){
			printf("%0.2f\t", fdt[i][j]);
		}
		printf("\n");
	}
	
	printf("Enter the value of x you want to find [f(x)]: ");
	scanf("%f", &x);
	
	u = (x-fdt[0][0]) / (fdt[1][0] - fdt[0][0]);
	
	float num, den;
	
	for(i=0; i<tableSize; i++){
		num=1.0;
		den=1.0;
		for(j=0; j<i; j++){
			num *= (u-j); // numerator
			den *= (j+1); // factorial
		}
		
		result += (num/den)*fdt[0][i+1];
	}
	
	printf("\n\nResult: %f", result);
	
	return 0;
}
