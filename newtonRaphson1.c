/*
    1. Declare and initialise all needed variables
	2. user input a such that f'(a) != 0
    3. decide a logic to terminate the loop
       a. Use concept of significant figures or correct upto n decimal places        [ imp ]
       b. Use a error ( fabs(currentRoot - lastRoot) <= error )                      [ imp ]
       c. given number of steps or predefined inside code
    4. Display the table properly [ i, a, root ] 
    5. display root (latest root)
      lastRoot  currentRoot   correct upto 3 decimal places [dec=3]
       4.5679      4.5672     [ 4.5679*(10^dec) = (int)(4567.9) = 4567 ]   [ 4.5672*(10^dec) = (int)(4567.2) = 4567 ]
*/

/*
    c = a - f(a)/f'(a)
    a=c
*/



#include<stdio.h>
#include<math.h>

// #define func ( (x*x*x) - (8.0*x) - 4.0 )
// #define funcD ( (3.0*x*x) - 8.0 )
#define func sin(x) + cos(x) - 1
#define funcD cos(x) - sin(x)

double f(double x) {
	return func;
}
double fd(double x) {
	return funcD;
}

int main(){
	int i, dec;
	double a, c, lastRoot;
	
	while(1){
		printf("Enter a: ");
		scanf("%lf", &a);

		if( fd(a) != 0.0 ) break;
		printf("Wrong a chosen\nTry again!\n");
	}
	printf("Enter correct decimal places: ");
	scanf("%d", &dec);
	
	printf("\n\ti\t  a\t\t root\n\t");
	for(i=1;i<=10;i++) printf("---");
	printf("\n");
	
	i=1;
	while(1){
		c = a - ( f(a)/fd(a) );
		printf("\t%d\t%0.4lf\t\t%0.4lf\n", i, a, c);
		a=c;
		
		if( i>1 && (int)(lastRoot*(pow(10,dec))) == (int)(c*(pow(10,dec))) ) break;
		
		i++;
		lastRoot=c;
		
	}
	
	printf("\n\nRoot: %lf", c);
	return 0;
	
}

