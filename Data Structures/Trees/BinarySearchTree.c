#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};
typedef struct Node NODE;

NODE *create(int n){
    NODE *t = (NODE*)malloc(sizeof(NODE));
    t->data = n;
    t->left = t->right = NULL;
    return t;
}

NODE* insert(NODE* root, int n);
NODE* search(NODE* root, int key);
void inorder(NODE* root);
void preorder(NODE* root);
void postorder(NODE* root);

int main(void){
    NODE *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 05);
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    preorder(root);
    return 0;
}
NODE* insert(NODE* root, int n){
    if(root == NULL){
        root = create(n);
    }else if(n <= root->data){
        root->left = insert(root->left, n);
    }else{
        root->right = insert(root->right, n);
    }
    return root;
}
NODE* search(NODE *root, int key){
    if(root == NULL || root->data == key){
        return root;
    }else if(key <= root->data){
        return search(root->left, key);
    }else{
        return search(root->right, key);
    }
    return root;
}
void inorder(NODE* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(NODE* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(NODE* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}