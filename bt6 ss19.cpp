#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void copyArray(int *src, int *dest, int n);

int main(){
	const int n = 10;
	
	int a[n] = {2,6,4,2,4,3,4,6,4,1};
	int b[n];
	
	copyArray(a,b,n);
	
	printf("\nMang sau khi copy: \n");
	for(int i=0;i<n;i++){
		printf("%d  ",b[i]);
	}
}

void copyArray(int *src, int *dest, int n){
	for(int i=0;i<n;i++){
		*(dest+i) = *(src+i);
	}
}
