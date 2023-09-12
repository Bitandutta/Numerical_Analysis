#include<stdio.h>

// 0 1 1 2 3 5 8 13 ...

void printFibonacci(int terms){
	int i, n0=0, n1=1, n2;;
	for(i=1; i<=terms; i++){
		printf("%d ", n0);
		
		n2=n0+n1; // next= sum of prev2 terms
		n0=n1;
		n1=n2;
	}
}

int main(){
	
	int terms;
	
	printf("Enter number of terms:  ");
	scanf("%d", &terms);
	
	printFibonacci(terms);

	return 0;
	
}

