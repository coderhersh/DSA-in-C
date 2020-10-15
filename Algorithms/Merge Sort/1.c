#include<stdio.h>

void Merge(int a[], int low, int middle, int high){
    int n1 = middle - low + 1;
    int n2 = high - middle;
    int T1[n1], T2[n2], i, j, k;
    
    for (i = 0; i < n1; ++i)    T1[i] = a[low + i];
    for (j = 0; j < n2; ++j)    T2[j] = a[middle + j + 1];

    i = j = 0;
    k = low;

    while (i < n1 && j < n2){
        if (T1[i] <= T2[j]){
            a[k] = T1[i];
            ++i;
        }else{
            a[k] = T2[j];
            ++j;
        }
        ++k;
    }

    while (i < n1){
        a[k] = T1[i];
        ++i;++k;
    }

    while (j < n2){
        a[k] = T2[j];
        ++j;++k;
    }
}
void MergeSort(int a[], int low, int high){
    if (low < high){
        int middle = low + (high-low) / 2;  // To handle overflow situation
        MergeSort(a, low, middle);
        MergeSort(a, middle+1, high);
        Merge(a, low, middle, high);
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
    MergeSort(a, 0, n-1);
    print(a, n);
    return 0;
}