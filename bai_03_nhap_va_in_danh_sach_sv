#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char hoten[30];
    int masv;
    float d1, d2, d3;
} SinhVien;
int main() {
    SinhVien *p;
    int n, i;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    p = (SinhVien*)malloc(n * sizeof(SinhVien));
    for (i = 0; i < n; i++) {
        printf("\nNhap sinh vien thu %d:\n", i + 1);
        printf("Ho ten: ");
        scanf(" %[^\n]", (p + i)->hoten);
        printf("Ma sinh vien: ");
        scanf("%d", &(p + i)->masv);
        printf("Diem 1: ");
        scanf("%f", &(p + i)->d1);
        printf("Diem 2: ");
        scanf("%f", &(p + i)->d2);
        printf("Diem 3: ");
        scanf("%f", &(p + i)->d3);
    }
    printf("\nDanh sach sinh vien\n");
    for (i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("Ho ten: %s\n", (p + i)->hoten);
        printf("Ma sinh vien: %d\n", (p + i)->masv);
        printf("Diem 1: %.2f\n", (p + i)->d1);
        printf("Diem 2: %.2f\n", (p + i)->d2);
        printf("Diem 3: %.2f\n", (p + i)->d3);
    }
    free(p);
    return 0;
}
