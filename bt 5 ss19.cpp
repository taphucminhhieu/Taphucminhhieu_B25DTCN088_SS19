#include <stdio.h>
int compareArrays(int *a, int *b, int n) {
    for (int i = 0; i < n; i++) {
        if (*(a + i) != *(b + i)) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {10, 20, 30, 40, 50}; 
    int arr3[] = {10, 20, 99, 40, 50}; 
    int n = sizeof(arr1) / sizeof(arr1[0]);

    printf("Mang 1: {10, 20, 30, 40, 50}\n");
    printf("Mang 2: {10, 20, 30, 40, 50}\n");
    printf("Mang 3: {10, 20, 99, 40, 50}\n");
    printf("So phan tu (n) = %d\n\n", n);


    int result1 = compareArrays(arr1, arr2, n);
    printf("Ket qua so sanh Mang 1 va Mang 2: %d", result1);
    printf(" (%s)\n", result1 == 1 ? "Giong nhau" : "Khac nhau");
    
    int result2 = compareArrays(arr1, arr3, n);
    printf("Ket qua so sanh Mang 1 va Mang 3: %d", result2);
    printf(" (%s)\n", result2 == 1 ? "Giong nhau" : "Khac nhau");

    return 0;
}
