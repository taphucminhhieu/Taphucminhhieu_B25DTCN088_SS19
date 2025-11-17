#include<stdio.h>
int main() {
	int a[5] ={1,2,3,4,5};
	printf("gia tri bien a: %d\n",a);
	for(int i=0;i<5;i++){
		printf("dia chi cua phan tu a [%d]: %d \n",i, &a[i]); 
	}
	return 0;
}
