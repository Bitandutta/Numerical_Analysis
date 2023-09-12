/*

   1
  12
 123
1234
 123
  12
   1

outer loop := no. of lines
inner loops := prints each line one character at a time



#include <stdio.h>
int main(){
	int height=21;
	int i, j, k;
	for(i=1; i<=height; i++){
		if (i<=(height/2)+1){
			for(k=(height/2); k>=i; k--) printf(" "); // space
			for(j=1; j<=i; j++) printf("%d ", j); // characters	
		}
		else{ // i= 5, 6, 7
			for(k=(height/2)+2; k<=i; k++) printf(" ");
			for(j=1; j<=height-i+1; j++ ) printf("%d ", j);
		}
		
		printf("\n");
	}
	
}

*/


#include<stdio.h>

/*	
i=0	  (0,1) (1,2) (2,3) (3,4)
i=1	  (0,1) (1,2) (2,3)
i=2	  (0,1) (1,2)
i=3	  (0,1)
*/
//bubble sort


int main(){
	
	int arr[] = { 5,-2, 9, -13, 0, 72, 6, 4};
	int len= sizeof(arr)/sizeof(int);
	
	int i, j, t;
	
	printf("Array before sorting: ");
	for(i=0;i<len;i++) printf("%d ", arr[i]);
	
	for (i=0; i<len-1; i++){
		
		for(j=0; j<len-1-i; j++){
			if(arr[j+1] < arr[j]){
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
		
	}
	
	printf("\nArray after sorting: ");
	for(i=0;i<len;i++) printf("%d ", arr[i]);
	
}

