/*
    1. Declare and initialise all needed variables
	2. user input a and b such that ( f(a)*f(b) ) < 0
    3. decide a logic to terminate the loop
       a. Use concept of significant figures or correct upto n decimal places        [ imp ]
       b. Use a error ( fabs(currentRoot - lastRoot) <= error )                      [ imp ]
       c. given number of steps or predefined inside code
    4. Display the table properly [ i, a, b, avg, f(a), f(avg), f(a)*f(avg), update ] 
    5. display root (latest avg)
      lastRoot  currentRoot   correct upto 3 decimal places [dec=3]
       4.5679      4.5672     [ 4.5679*(10^dec) = (int)(4567.9) = 4567 ]   [ 4.5672*(10^dec) = (int)(4567.2) = 4567 ]
*/

#include<stdio.h>
#include<math.h>
//#define func ((x*x*x) - (4.0*x) - 9.0)


#define func sin(x) + cos(x) - 1

double f(double x) { // this function returns f(x)
	return func;
}

int main() {
	int i, dec;
	double a, b, avg, fa, favg, lastRoot;
	while(1){
		// user input is taken
		printf("Enter value of a: ");
		scanf("%lf", &a);
		printf("Enter value of b: ");
		scanf("%lf", &b);
		if( (f(a)*f(b)) < 0.0 ) break; // if root lies between a and b we break the infinite loop
		else printf("Root does not lie between a and b!\nTry again\n");
	}
	
	printf("\nEnter the decimal place: ");
	scanf("%d", &dec);
	// i, a, b, avg, f(a), f(avg), f(a)*f(avg), update
	
	printf("\n\ti\t  a\t\t  b\t\t avg\t\tf(a)\t\tf(avg)\t\tf(a)*f(avg)\tupdate\n\t");
	for(i=1;i<=37;i++) printf("---");
	printf("\n");
	
	i=1;
	while(1){
		avg = (a+b)/2.0;
		printf("\t%d\t%0.4lf\t\t%0.4lf\t\t%0.4lf\t\t%0.4lf\t\t%0.4lf\t\t%0.4lf\t\t", i, a, b, avg, f(a), f(avg), f(a)*f(avg));
		if( (f(a)*f(avg)) < 0.0 ) {
			b=avg;
			printf("b=avg\n");
		}
		else {
			a=avg;
			printf("a=avg\n");
		}
		
		if(i>1){ // for the first time we donot have anything the lastRoot
		     if( (int)(lastRoot*(pow(10,dec))) == (int)(avg*(pow(10,dec))) ) break;
		}
		i++;
		lastRoot = avg;
	}
	
	printf("\n\nRoot: %lf", avg);
	return 0;
}


