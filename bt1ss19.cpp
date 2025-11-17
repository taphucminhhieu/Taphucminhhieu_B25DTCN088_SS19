#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 100
void inputArray(int *p, int *x);
void displayArray(int arr[], int x);
int findMax(int *arr, int n);

int main(){
	int arr[MAX];
	int n = 0;

	inputArray(arr, &n);
	displayArray(arr, n);

	int max = findMax(arr,n);
	printf("\nPhan tu lon nhat cua mang: %d",max);
}


void inputArray(int *p, int *x){
	do{
		printf("Nhap so phan tu cua mang: ");
		scanf("%d",x);
		if(*x<1 || *x>MAX){
			printf("Nhap lai so phan tu cua mang \n");
		}
	}while(*x<1 || *x>MAX);

	for(int i=0;i<*x;i++){
		printf("Nhap phan tu %d: ",(i+1));
		scanf("%d",(p+i));
	}
}

void displayArray(int arr[], int x){
	printf("\nCac phan tu cua mang: \n");
	for(int i=0;i<x;i++){
		printf("%d  ",arr[i]);
	}
}

int findMax(int *arr, int n){
	int max = *(arr+0);
	for(int i=1;i<n;i++){
		if(max<*(arr+i)){
			max = *(arr+i);
		}
	}
	return max;
}
