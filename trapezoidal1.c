/*
    Step 1. Declare and initialise all necessary variables
    Step 2. User input:- a, b, h or n
	Step 3. Calculate the number of steps the loop will run
	Step 4. Calculate I = h*[ f(a)/2 + SUM[f(a+ih)] (0<i<n) + f(a+nh)/2 ] and display i, x, f(x), I
	
*/

#include<stdio.h>
#include<math.h>

#define func (1.0/(1.0 + x)) // this is the given function that is to be integrated from a->b
#define flag 1 // if set to 1 it will check for discontinuity for all intervals
#define fd (1.0 + a) // if fd=0 then fx is discontinious

double f(double x){ // returns f(x)
	return func;
}
int check(double a, double b, double h){ // checks for discontinuity for all intervals
	if(flag==0) return 1;
	while(a<=b){
		if(fd==0) return 0; // function is discontinous at a
		a += h;
	}
	return 1;
}

int main(){
	
	int i, n;
	double a, b, h, I=0.0;
	
	while(1){
		printf("Enter Lower Limit: ");
		scanf("%lf", &a);
		printf("Enter Upper Limit: ");
		scanf("%lf", &b);
		printf("Enter sub-intervals: ");
		scanf("%d", &n);
		
		h = (b-a)/(double)(n);
		
		if(check(a,b,h)) break;
		printf("Enter proper limits\nTry again!\n");
		
	}
	
	printf("\n\ti\t\tx=(a+ih)\tf(x)\t\tI\n\t");
	for(i=0;i<19;i++) printf("---");
	printf("\n");
	/*
	0 -> 1   [n=4 sub-interval]  h=0.25
	I = h*[ f(0 + 0*0.25)/2 + f(0 + 1*0.25) + f(0 + 2*0.25) + f(0 + 3*0.25) + f(0 + 4*0.25)/2 ]
	
	*/
	for(i=0; i<=n; i++){
		if(i==0 || i==n){ // first and last
			I += (h/2.0)*(f(a+(i*h)));
		}
		else{ // rest cases
			I += h*(f(a+(i*h)));
		}
		printf("\t%d\t\t%0.4lf\t\t%0.4lf\t\t%0.4lf\n", i, (a+(i*h)), f(a+(i*h)), I );
	}
	
	printf("\n\n\tI= %lf", I);
	return 0;
	
}






	
	
	
	
	
	
