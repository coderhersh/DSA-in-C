#include<stdio.h>
#define MAX 1000

int a[MAX], top = -1;

void push(int a);
void pop();
void show();
int main(void){
    int option, n;
    while(1){
        printf("1.Push\n2.Pop\n3.Show");
        printf("\n4.Exit\n\n");
        scanf("%d", &option);
        if (option == 1){
            printf("Enter n: ");
            scanf("%d", &n);
        }
        switch(option){
            case 1: push(n);  break;
            case 2: pop();    break;
            case 3: show();   break;
            case 4: return 0;
        }
    }
}
void push(int n){
    if(top != MAX-1){   
        a[++top] = n;
        printf("%d value pushed.\n", n);
    }else{
        printf("Full.\n");
    }
}
void pop(){
    if(top != -1){
        printf("%d poped.\n", a[top]);
        --top;
    }else{
        printf("Empty.\n");
    }
}
void show(){
    if(top != -1){
        for (int i = top; i >= 0; i--)
            printf("%d ", a[i]);
        printf("\n");
    }else{
        printf("Empty.\n");
    }
}