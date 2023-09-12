/*
    1. Declare and initialise all needed variables
	2. user input a and b such that ( f(a)*f(b) ) < 0 && f(b)-f(a) != 0
    3. decide a logic to terminate the loop
       a. Use concept of significant figures or correct upto n decimal places        [ imp ]
       b. Use a error ( fabs(currentRoot - lastRoot) <= error )                      [ imp ]
       c. given number of steps or predefined inside code
    4. Display the table properly [ i, a, b, root, f(a), f(avg), f(a)*f(avg)] 
    5. display root (latest root)
      lastRoot  currentRoot   correct upto 3 decimal places [dec=3]
       4.5679      4.5672     [ 4.5679*(10^dec) = (int)(4567.9) = 4567 ]   [ 4.5672*(10^dec) = (int)(4567.2) = 4567 ]
*/

/*
    c = ( a*f(b) - b*f(a) ) / f(b) - f(a)
*/

#include<stdio.h>
#include<math.h>

//#define func ( (x*x*x) - (4.0*x) - 9.0 )
#define func sin(x) + cos(x) - 1

double f(double x) {
	return func;
}

int main(){
	int i, dec;
	double a, b, c, lastRoot;
	
	while(1){
		printf("Enter a: ");
		scanf("%lf", &a);
		printf("Enter b: ");
		scanf("%lf", &b);
		if( (f(a)*f(b)) < 0.0 && (f(b)-f(a)) != 0.0 ) break;
		printf("Wrong a and b chosen\nTry again!\n");
	}
	printf("Enter correct decimal places: ");
	scanf("%d", &dec);
	
	printf("\n\ti\t  a\t\t  b\t\t root\n\t");
	for(i=1;i<=16;i++) printf("---");
	printf("\n");
	
	i=1;
	while(1){
		c = ((a*f(b)) - (b*f(a)))/(f(b)-f(a));
		printf("\t%d\t%0.4lf\t\t%0.4lf\t\t%0.4lf\n", i, a, b, c);
		
		a=b;
		b=c;
		
		if( i>1 && (int)(lastRoot*(pow(10,dec))) == (int)(c*(pow(10,dec))) ) break;
		
		i++;
		lastRoot=c;
		
	}
	
	printf("\n\nRoot: %lf", c);
	return 0;
	
}














