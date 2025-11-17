#include <stdio.h>
#include <stdlib.h> 
int *array = NULL;
int size = 0;


void input_array() {
    int n;
    if (array != NULL) {
        free(array);
        array = NULL;
        size = 0;
    }

    printf("Nhap so luong phan tu cua mang (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("So luong phan tu khong hop le hoac <= 0.\n");
        return;
    }

    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Loi cap phat bo nho!\n");
        return;
    }
    size = n;

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < size; i++) {
        printf("Phan tu thu %d: ", i + 1);
        if (scanf("%d", (array + i)) != 1) { 
            printf("Gia tri nhap vao khong hop le. Xin thu lai.\n");
            free(array);
            array = NULL;
            size = 0;
            return;
        }
    }
    printf("Da nhap mang thanh cong.\n");
}

void display_array() {
    if (array == NULL) {
        printf("Mang chua duoc nhap. Vui long chon chuc nang 1 truoc.\n");
        return;
    }

    printf("Cac phan tu trong mang (%d phan tu): ", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", *(array + i)); 
    }
    printf("\n");
}

void get_size() {
    if (array == NULL) {
        printf("Mang chua duoc nhap.\n");
        return;
    }
    printf("Do dai (so luong phan tu) cua mang la: %d\n", size);
}

void calculate_sum() {
    if (array == NULL) {
        printf("Mang chua duoc nhap. Vui long chon chuc nang 1 truoc.\n");
        return;
    }

    long long sum = 0;
    int *p = array;
    int *end = array + size;
    while (p < end) {
        sum += *p; 
        p++;     
    }
    
    printf("Tong cac phan tu trong mang la: %lld\n", sum);
}

void find_max() {
    if (array == NULL) {
        printf("Mang chua duoc nhap. Vui long chon chuc nang 1 truoc.\n");
        return;
    }

    if (size == 0) {
        printf("Mang rong, khong co phan tu lon nhat.\n");
        return;
    }

    int max_val = *array; 

    for (int i = 1; i < size; i++) {
        if (*(array + i) > max_val) {
            max_val = *(array + i);
        }
    }

    printf("Phan tu lon nhat trong mang la: %d\n", max_val);
}

void show_menu() {
    printf("\n============== MENU CHUONG TRINH ==============\n");
    printf("1. Nhap so phan tu va tung phan tu\n");
    printf("2. Hien thi cac phan tu trong mang\n");
    printf("3. Tinh do dai mang\n");
    printf("4. Tinh tong cac phan tu trong mang\n");
    printf("5. Hien thi phan tu lon nhat\n");
    printf("6. Thoat\n");
    printf("==============================================\n");
    printf("Chon chuc nang (1-6): ");
}

int main() {
    int choice;
    
    do {
        show_menu();
        if (scanf("%d", &choice) != 1) {
            printf("Loi nhap. Vui long nhap so.\n");
            while (getchar() != '\n');
            choice = 0; 
            continue;
        }

        switch (choice) {
            case 1:
                input_array();
                break;
            case 2:
                display_array();
                break;
            case 3:
                get_size();
                break;
            case 4:
                calculate_sum();
                break;
            case 5:
                find_max();
                break;
            case 6:
                printf("Tam biet. Chuong trinh ket thuc.\n");
                break;
            default:
                printf("Chuc nang khong hop le. Vui long chon tu 1 den 6.\n");
        }
    } while (choice != 6);
    if (array != NULL) {
        free(array);
    }

    return 0;
}
