#include<stdio.h>
#include<math.h>

#define check ( (fabs(m[0][0]) > (fabs(m[0][1])+fabs(m[0][2])) ) && (fabs(m[1][1]) > (fabs(m[1][0])+fabs(m[1][2])) ) && (fabs(m[2][2]) > (fabs(m[2][0])+fabs(m[2][1])) ) )
#define et 0.01

int main(){
	
	int i,j;
	float m[3][4], x=0.0, y=0.0, z=0.0, lx, ly, lz;
	
	printf("Enter the equations:\n");
	
	for(i=0; i<3; i++){
		j=0;
		printf("\nEnter equation %d\n", i+1);
		printf("Enter coefficient of x: ");
		scanf("%f", &m[i][j++]);
		printf("Enter coefficient of y: ");
		scanf("%f", &m[i][j++]);
		printf("Enter coefficient of z: ");
		scanf("%f", &m[i][j++]);
		printf("Enter constant: ");
		scanf("%f", &m[i][j++]);
	}
	
	// given equations
	printf("\nGiven Equations\n");
	for(i=0; i<3; i++){
		printf("%0.3fx + %0.3fy + %0.3fz = %0.3f\n", m[i][0], m[i][1], m[i][2], m[i][3]);
	}
	
	if(!check){
		printf("Gauss seidel cannot be implemented!");
		return;
	}
	
	printf("\n\tsl_no\t\tx\t\ty\t\tz\n\t");
	for(i=1; i<=20; i++) printf("---");
	printf("\n");
	
	i=1;
	while(1){
		x = ( m[0][3] - m[0][1]*y - m[0][2]*z ) / m[0][0];
		y = ( m[1][3] - m[1][0]*x - m[1][2]*z ) / m[1][1];
		z = ( m[2][3] - m[2][0]*x - m[2][1]*y ) / m[2][2];
		
		printf("\t%d\t\t%0.4f\t\t%0.4f\t\t%0.4f\n", i, x, y, z);
		
		if(i>1 && (fabs(lx-x)<=et && fabs(ly-y)<=et && fabs(lz-z)<=et) ){
			break;
		}
		
		lx=x;
		ly=y;
		lz=z;
		i++;
	}
	
	printf("\n\nRoots\n");
	printf("x=%f\ny=%f\nz=%f\n", x, y, z);
	return 0;
	
}  
