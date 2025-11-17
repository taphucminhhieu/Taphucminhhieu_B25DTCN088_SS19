#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 100

void inputArray(int *arr, int *n);
void displayArray(int arr[], int n);
void countEvenOdd(int *arr, int n, int *even, int *odd);

int main(){
	int arr[MAX];
	int n;
	int even, odd;
	
	inputArray(arr, &n);
	displayArray(arr, n);
	
	countEvenOdd(arr,n,&even,&odd);
	printf("\nSo phan tu chan cua mang: %d",even);
	printf("\nSo phan tu le cua mang: %d",odd);
}

void inputArray(int *arr, int *n){
	do{
		printf("Nhap so phan tu cua mang: ");
		scanf("%d",n);
		if(*n<1 || *n>MAX){
			printf("Nhap lai n\n");
		}
	}while(*n<1 || *n>MAX);
	
	for(int i=0;i<*n;i++){
		printf("Nhap phan tu %d: ",(i+1));
		scanf("%d",(arr+i));
	}
}

void displayArray(int arr[], int n){
	printf("\nCac phan tu cua mang: \n");
	for(int i=0;i<n;i++){
		printf("%d  ",arr[i]);
	}
}

void countEvenOdd(int *arr, int n, int *even, int *odd){
	*even = 0;
	*odd = 0;
	for(int i=0;i<n;i++){
		if(*(arr+i)%2==0){
			*even = *even+1;
		}else{
			*odd = *odd + 1;
		}
	}
}
