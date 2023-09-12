#include<stdio.h>
#include<math.h>

int main(){
	int i, j;
	float m[3][4], x, y, z, c;
	
	for(i=0; i<3; i++){
		j=0;
		printf("Enter equation %d\n", i+1);
		printf("Enter coefficient of x: ");
		scanf("%f", &m[i][j++]);
		printf("Enter coefficient of y: ");
		scanf("%f", &m[i][j++]);
		printf("Enter coefficient of z: ");
		scanf("%f", &m[i][j++]);
		printf("Enter constant: ");
		scanf("%f", &m[i][j++]);
        printf("\n");
	}
	
	printf("\nGiven equations:\n");
	for(i=0; i<3; i++){
		printf("%0.2fx + %0.2fy + %0.2fz = %0.4f\n", m[i][0], m[i][1], m[i][2], m[i][3]);
	}
	printf("\n");
	
	
	
	c = m[1][0]/m[0][0];
	for(i=0; i<4; i++){
		m[1][i] -= c*m[0][i]; // R2 = R2 - cR1
	}
	
	printf("\nStep 1:\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%f\t", m[i][j]);
		}
		printf("\n");
	}
	
	c = m[2][0]/m[0][0];
	for(i=0; i<4; i++){
		m[2][i] -= c*m[0][i];  // R3 = R3-cR1
	}
	
	printf("\nStep 2:\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%f\t", m[i][j]);
		}
		printf("\n");
	}
	
	c = m[2][1]/m[1][1];
	for(i=0; i<4; i++){
		m[2][i] -= c*m[1][i];  // R3 = R3-cR2
	}
	
	printf("\nStep 3:\n");
	for(i=0;i<3;i++){
		for(j=0;j<4;j++){
			printf("%f\t", m[i][j]);
		}
		printf("\n");
	}
	
	z = m[2][3]/m[2][2];
	y = (m[1][3]- (z*m[1][2])) / m[1][1];
	x = (m[0][3] - (z*m[0][2]) - (y*m[0][1])) / m[0][0];
	
	printf("\n\nRoots\n");
	printf("x= %f\ny= %f\nz= %f", x, y, z);
	
	return 0;
	
}
