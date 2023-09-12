#include<stdio.h>
#include<math.h>

#define func (y-x)/(y+x)

double f(double x, double y){
	return func;
}

double rk(double x, double y, double h){
	
	double k1 = h*f(x,y);
	double k2 = h*f( x+(h/2.0), y+(k1/2.0) );
	double k3 = h*f( x+(h/2.0), y+(k2/2.0) );
	double k4 = h*f( x+h, y+k3 );
	
	return ((1/6.0)*(k1 + (2.0*k2) + (2.0*k3) + k4));
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
		y = y + rk(x,y,h);
		
		printf("\t%d\t\t%0.4lf\t\t%0.4lf\n", i, x, y);
		
		x += h;
		i++;
	}
	
	printf("\n\n\ty(%0.3lf) = %lf", targetX, y);
	return 0;
	
}
