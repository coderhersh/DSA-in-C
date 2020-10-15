#include<stdio.h>
void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}
void BubbleSort(int a[], int n){
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; ++j)
            if (a[j] > a[j+1])
                swap(&a[j], &a[j+1]);
}
void print(int a[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
int main(void){
    int a[] = {31, 4, 23, 12, 67, 99, 1, 14, 21, 2};
    int n = sizeof(a)/sizeof(a[0]);
    print(a, n);
    BubbleSort(a, n);
    print(a, n);
    return 0;
}