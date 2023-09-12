#include<stdio.h>
#include<math.h>

#define func  (y-x)/(y+x)

double f(double x, double y) {
	return func;
}

int main(){
	
	double x, y, h, targetX;
	int i;
	
	printf("Enter initial x: ");
	scanf("%lf", &x);
	printf("Enter y(%0.2lf): ", x);
	scanf("%lf", &y);
	
	printf("Enter y(x) that you want to find [x]: ");
	scanf("%lf", &targetX);
	printf("Enter step size: ");
	scanf("%lf", &h);
	
	printf("\n\n\tsl_no\t\tx\t\ty\n\t");
	for(i=0; i<13; i++) printf("---");
	printf("\n");
	i=0;
	while(x<targetX){
		y = y + h*f(x,y);
		
		printf("\t%d\t\t%0.4lf\t\t%0.4lf\n", i, x, y);
		
		x += h;
		i++;
	}
	
	printf("\n\n\ty(%0.3lf) = %lf", targetX, y);
	
	return 0;
}
