/*
  Step 1: Y`n+1 = Yn + h*f(Xn, Yn)
  Step 2: Yn+1 = Yn + (h/2)*[ f(Xn, Yn) + f(Xn+1, Y`n+1) ]
*/

#include<stdio.h>
#include<math.h>

#define func  (y-x)/(y+x)

double f(double x, double y) {
	return func;
}

int main(){
	
	double x, y, ty, h, targetX;
	int i;
	
	printf("Enter initial x: ");
	scanf("%lf", &x);
	printf("Enter y(%0.2lf): ", x);
	scanf("%lf", &y);
	
	printf("Enter y(x) that you want to find [x]: ");
	scanf("%lf", &targetX);
	printf("Enter step size: ");
	scanf("%lf", &h);
	
	printf("\n\n\tsl_no\t\tx\t\tty\t\ty\n\t");
	for(i=0; i<18; i++) printf("---");
	printf("\n");
	i=0;
	
	// Step 1: Y`n+1 = Yn + h*f(Xn, Yn)
    // Step 2: Yn+1 = Yn + (h/2)*[ f(Xn, Yn) + f(Xn+1, Y`n+1) ]
	while(x<targetX){
		ty = y + h*f(x,y);
		y =  y + (h/2.0)*( f(x,y) + f((x+h), ty) );
		
		printf("\t%d\t\t%0.4lf\t\t%0.4lf\t\t%0.4lf\n", i, x, ty, y);
		
		x += h;
		i++;
	}
	
	printf("\n\n\ty(%0.3lf) = %lf", targetX, y);
	
	return 0;
}
