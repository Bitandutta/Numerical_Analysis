#include<stdio.h>
#include<math.h>
#define check ( (fabs(m[0][0]) > ( fabs(m[0][1]) + fabs(m[0][2]))) && (fabs(m[1][1]) > fabs(m[1][0]) + fabs(m[1][2])) && (fabs(m[2][2]) > fabs(m[2][0]) + fabs(m[2][1])) )
#define et 0.01

int significant(double a, int sig){
	
	return ((int)(a*(pow(10,sig)))) / (int)(pow(10,sig));
	
}

int main(){
	
	// sin 30
	
	float degToRad = 30.0 * ((22.0/7.0)/180.0);
	
	printf("Sin 30 = %f", sin(degToRad));
	/*
	printf("4 significant figure of 13.788 is %d\n", significant(13.788, 4));
	printf("5 significant figure of 513.782138 is %d\n", significant(513.782138, 5));
	printf("6 significant figure of 13.788234 is %d\n", significant(13.788234, 6));
	*/
	/*
	int i, j;
	
	float m[3][4];
	float tx=0.0, ty=0.0, tz=0.0, x, y, z;
	float lx, ly, lz;
	
	printf("Enter the linear equations:");
	for(i=0;i<3;i++){
		printf("\nEnter equation %d:\n", i+1);
		for(j=0;j<3;j++){
			printf("Enter coefficient of x^%d: ", (2-j));
		 	scanf("%f", &m[i][j]);
		}
		printf("Enter the constant: ");
		scanf("%f", &m[i][j]);
	}
	
	if(!check){
		printf("Gauss seidel not applicable");
		return 0;
	}
	
	printf("\n\tsl_no\t\tx\t\ty\t\tz\n\t");
	for(i=1;i<=15;i++) printf("---");
	printf("\n");

	i=1;
	
	while(1){
		tx = ( m[0][3] - (m[0][1]*y) - (m[0][2]*z) ) / m[0][0];
		ty = ( m[1][3] - (m[1][0]*x) - (m[1][2]*z) ) / m[1][1];
		tz = ( m[2][3] - (m[2][0]*x) - (m[2][1]*y) ) / m[2][2];
		
		x=tx, y=ty, z=tz;
		
		printf("\t%d\t\t%0.4f\t\t%0.4f\t\t%0.4f\n\t\n", i, x, y, z);
		
		if(i>0){
			if( (fabs(lx)-fabs(x))<=et && (fabs(ly)-fabs(y))<=et && (fabs(lz)-fabs(z))<=et ) break;
		}
		
		lx=x;
		ly=y;
		lz=z;
		
		i++;
	}
	
	
	printf("\n\nRoots:\nx= %f\ny= %f\nz= %f", x, y, z);
	return 0;
	*/
}
