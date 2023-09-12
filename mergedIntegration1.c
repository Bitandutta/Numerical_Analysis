#include<stdio.h>
#include<math.h>

#define func (1.0/(1.0 + x)) // this is the given function that is to be integrated from a->b
#define flag 1 // if set to 1 it will check for discontinuity for all intervals
#define fd (1.0 + a) // if fd=0 then fx is discontinious
#define actual 0.69314718

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
	double a, b, h, It=0.0, Is=0.0;
	
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
	
	
	// TRAPEZOIDAL
	printf("\n\tTrapezoidal\n");
	printf("\n\ti\t\tx=(a+ih)\tf(x)\t\tI\n\t");
	for(i=0;i<19;i++) printf("---");
	printf("\n");

	for(i=0; i<=n; i++){
		if(i==0 || i==n){ // first and last
			It += (h/2.0)*(f(a+(i*h)));
		}
		else{ // rest cases
			It += h*(f(a+(i*h)));
		}
		printf("\t%d\t\t%0.4lf\t\t%0.4lf\t\t%0.4lf\n", i, (a+(i*h)), f(a+(i*h)), It );
	}
	
	// SIMPSON
	printf("\n\tSimpson\n");
	printf("\n\t i\t\tx=(a+ih)\t f(x)\t\tMulFac\t\t  I\n\t");
	for(i=0;i<24;i++) printf("---");
	printf("\n");

	char mf[4];

    for(i=0; i<=n; i++){
		if(i==0 || i==n){ // First and Last
			Is += (h/3.0)*(f(a+(i*h)));
			strcpy(mf, "1/3");
		}
		else if(i%2==0) { // Even
			Is += ((2.0*h)/3.0)*(f(a+(i*h)));
			strcpy(mf, "2/3");
		}
		else { // Odd
			Is += ((4.0*h)/3.0)*(f(a+(i*h)));
			strcpy(mf, "4/3");
		}
		printf("\t %d\t\t %0.4lf\t\t%0.4lf\t\t %s\t\t%0.4lf\n", i, (a+(i*h)), f(a+(i*h)), mf, Is );
	}
	
    printf("\nTrapezoidal I = %f", It);
    printf("\nSimpson I = %f", Is);
    printf("\n\nActual Answer: %f", actual);
    printf("\nError in Trapezoidal = %f", fabs(actual-It));
    printf("\nError in Simpson = %f", fabs(actual-Is));
    printf("\n\nPercentage Error in Trapezoidal = %f%%", 100.0*fabs((actual-It)/actual));
    printf("\nPercentage Error in Simpson = %f%%", 100.0*fabs((actual-Is)/actual));

	return 0;
	
}




	
	







	
	
	
	
	
	    

    
	
	
