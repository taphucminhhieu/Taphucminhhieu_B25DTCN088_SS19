#include <stdio.h>
float average(int *arr, int n) {
    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += *(arr + i); 
    }
    
    if (n > 0) {
        return (float)sum / n; 
    } else {
        return 0.0f;
    }
}

int main() {
    int n;
    
    printf("Nhap so luong phan tu cua mang (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("So luong phan tu khong hop le.\n");
        return 1;
    }

    int arr[n]; 
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
             printf("Gia tri nhap vao khong hop le.\n");
             return 1;
        }
    }

    float avg = average(arr, n);
    printf("Gia tri trung binh cua mang la: %.2f\n", avg);
    
    return 0;
}
