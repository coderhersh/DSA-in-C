#include<stdio.h>
#define MAX 1000

int a[MAX], front = -1, rear = -1;

void enqueue(int n);
void dequeue();
void show();

int main(void){
    int option, n;
    while(1){
        printf("1.Enqueue\n2.Dequeue\n3.Show");
        printf("\n4.Exit\n\n");
        scanf("%d", &option);
        if (option == 1){
            printf("Enter n: ");
            scanf("%d", &n);
        }
        switch(option){
            case 1: enqueue(n);  break;
            case 2: dequeue();   break;
            case 3: show();      break;
            case 4: return 0;
        }
    }
}
void enqueue(int n){

}
void dequeue(){

}
void show(){

}