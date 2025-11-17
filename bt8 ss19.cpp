
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 100
void inputArray(int *arr, int *n);
void displayEven(int *arr, int n);
void displayPrime(int *arr, int n);
void inverseArray(int *arr, int n);
void sortingAscending(int *arr, int n);
void sortingDescending(int *arr, int n);
void findElement(int *arr, int n);

int main(){
	int choose;
	int arr[MAX];
	int n;
	int sortType;
	int existSorting = 1;
	
	
	while(1){
		printf("\n------------- MENU -------------");
		printf("\n1. Nhap vao so phan tu va tung phan tu");
		printf("\n2. In ra cac phan tu la so chan");
		printf("\n3. In ra cac phan tu la so nguyen to");
		printf("\n4. Dao nguoc mang");
		printf("\n5. Sap xep mang");
		printf("\n6. Nhap vao 1 phan tu va tim kiem phan tu trong mang");
		printf("\n7. Thoat");

		printf("\nMoi chon: ");
		scanf("%d",&choose);
		switch(choose){
			case 1:
				inputArray(arr, &n);
				break;
			case 2:
				displayEven(arr, n);
				break;
			case 3:
				displayPrime(arr, n);
				break;
			case 4:
				inverseArray(arr, n);
				break;
			case 5:
				while(existSorting){
					printf("\nLua chon sap xep");
					printf("\n1. Tang dan");
					printf("\n2. Giam dan");
					printf("\n3. Back");
					printf("\nMoi ban chon kieu sap xep: ");
					scanf("%d",&sortType);
					switch(sortType){
						case 1:
							sortingAscending(arr,n);
							break;
						case 2:
							sortingDescending(arr,n);
							break;
						case 3:
							existSorting = 0;
							break;
						default:
							printf("\nLoi - Ban phai chon tu 1 den 3");
					}
				}
				break;
			case 6:
				findElement(arr,n);
				break;
			case 7:
				exit(0);
			default:
				printf("\nLoi - Ban khong chon tu 1 den 7");
		}
	}
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

void displayEven(int *arr, int n){
	printf("\nCac phan tu la so chan: ");
	for(int i=0;i<n;i++){
		if(*(arr+i)%2==0){
			printf("%d  ",*(arr+i));
		}
	}
}

void displayPrime(int *arr, int n){
	printf("\nCac phan tu la so nguyen to cua mang: \n");
	for(int i=0;i<n;i++){
		int flag = 1;
		if(*(arr+i)<2){
			flag = 0;
		}else{
			for(int j=2;j<=sqrt(*(arr+i));j++){
				if(*(arr+i)%j==0){
					flag = 0;
					break;
				}
			}
		}
		if(flag==1){
			printf("%d  ",*(arr+i));
		}
	}
}

void inverseArray(int *arr, int n){
	for(int i=0;i<n/2;i++){
		int temp = *(arr+i);
		*(arr+i) = *(arr+n-1-i);
		*(arr+n-1-i) = temp;
	}
	printf("\nMang dao nguoc: \n");
	for(int i=0;i<n;i++){
		printf("%d  ",*(arr+i));
	}
}

void sortingAscending(int *arr, int n){
	int temp;
	//sap xep noi bot
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(*(arr+j)>*(arr+j+1)){
				temp = *(arr+j);
				*(arr+j) = *(arr+j+1);
				*(arr+j+1) = temp;
			}
		}
	}
	printf("\nMang sap xep tang dan: \n");
	for(int i=0;i<n;i++){
		printf("%d  ",*(arr+i));
	}
}
void sortingDescending(int *arr, int n){
	int temp;
	//sap xep noi bot
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(*(arr+j)<*(arr+j+1)){
				temp = *(arr+j);
				*(arr+j) = *(arr+j+1);
				*(arr+j+1) = temp;
			}
		}
	}
	printf("\nMang sap xep tang dan: \n");
	for(int i=0;i<n;i++){
		printf("%d  ",*(arr+i));
	}
}

void findElement(int *arr, int n){
	int x;
	printf("\nNhap vao phan tu can tim: ");
	scanf("%d",&x);
	
	int found = 0;
	printf("\nKet qua tim kiem:");
	for(int i=0;i<n;i++){
		if(*(arr+i)==x){
			found++;		
		}
	}
	if(found!=0){
		printf("\nPhan tu %d xuat hien %d lan trong mang",x,found);
		printf("\nTai cac vi tri: \n");
		for(int i=0;i<n;i++){
		if(*(arr+i)==x){
			printf("%d  ",i);
		}
	}
	}else{
		printf("\nPhan tu %d khong xuat hien trong mang",x);
	}
}

