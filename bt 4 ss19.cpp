#include <stdio.h>
int countValue(int *arr, int n, int x) {
    int count = 0;
    int *p = arr;
    int *end = arr + n;
    while (p < end) {
        if (*p == x) {
            count++;
        }
        p++; 
    }
    
    return count;
}

int main() {
    int arr[] = {10, 25, 30, 10, 45, 10, 50, 25}; 
    int n = sizeof(arr) / sizeof(arr[0]);        
    int x;

    printf("Mang da cho: {10, 25, 30, 10, 45, 10, 50, 25}\n");
    printf("Nhap gia tri can tim (x): ");
    
    if (scanf("%d", &x) != 1) {
        printf("Gia tri nhap vao khong hop le.\n");
        return 1;
    }
    int result = countValue(arr, n, x);
    
    printf("Gia tri %d xuat hien %d lan trong mang.\n", x, result);
    
    return 0;
}
