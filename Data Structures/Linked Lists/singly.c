#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*head = NULL;
typedef struct Node NODE;

NODE* create(int n){
    NODE *p = (NODE*)malloc(sizeof(NODE));
    p->data = n;
    p->next = NULL;
    return p;
}
void insert_beg(int a);
void insert_end(int a);
void show();
void del_beg();
void del_end();
void destroy();
int main(void){
    int option, n;
    while(1){
        printf("1.Insert at beg\n2.Insert at End\n3.Show");
        printf("\n4.Delete at beg\n5.Delete at End\n6.Exit\n\n");
        scanf("%d", &option);
        if (option == 1 || option == 2){
            printf("Enter n: ");
            scanf("%d", &n);
        }
        switch(option){
            case 1: insert_beg(n);  break;
            case 2: insert_end(n);  break;
            case 3: show();         break;
            case 4: del_beg();      break;
            case 5: del_end();      break;
            case 6: destroy();      return 0;
        }
    }
}
void insert_beg(int a){
    if(head != NULL){
        NODE *front = create(a);
        front->next = head;
        head = front;
    }else{
        head = create(a);
    }
}
void insert_end(int a){
    if(head != NULL){
        NODE *last = head;
        while (last->next != NULL)
            last = last->next;
        last->next = create(a);
    }else{
        head = create(a);
    }
}
void show(){
    if(head != NULL){
        NODE *show = head;
        while (show->next != NULL){
            printf("%d->", show->data);
            show = show->next;
        }
        printf("%d\n\n", show->data);
    }else{
        printf("Empty.\n\n");
    }
}
void del_beg(){
    if(head->next == NULL){
        printf("%d removed.\n", head->data);
        free(head);
        head = NULL;
    }
    else if(head != NULL){
        NODE *temp = head;
        head = head->next;
        printf("%d removed.\n", temp->data);
        free(temp);
    }else{
        printf("Empty.\n");
    }
}
void del_end(){
    if(head->next == NULL){
        printf("%d removed.\n", head->data);
        free(head);
        head = NULL;
    }
    else if(head != NULL){
        NODE *lastptr = head, *prevptr = NULL;
        while (lastptr->next != NULL){
            prevptr = lastptr;
            lastptr = lastptr->next;
        }
        prevptr->next = NULL;
        printf("%d removed.\n", lastptr->data);
        free(lastptr);
    }else{
        printf("Empty.\n");
    }
}
void destroy(){
    if(head != NULL){
        NODE *temp = head;
        while (temp != NULL){
            head = head->next;
            free(temp);
            temp = head;
        }
    }
}