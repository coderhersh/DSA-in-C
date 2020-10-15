#include<stdio.h>

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}
void SelectionSort(int a[], int n){
    for (int i = 0; i < n; i++){
        int min = i;
        for (int j = i+1; j < n; ++j)
            if (a[j] < a[min])
                min = j;
        swap(&a[min], &a[i]);
    }
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
    SelectionSort(a, n);
    print(a, n);
    return 0;
}