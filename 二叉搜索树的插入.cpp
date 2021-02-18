#include<iostream>
using namespace std;

struct node{
    int data;
    node *lchild,*rchild;
    node():data(0),lchild(NULL),rchild(NULL){}
};

node* Insert(int K, node* root){
    if(!root){
        root = new node();
        root->data = K;
    }else
        if(K < root->data)
            root->lchild = Insert(K,root->lchild);
        else if(K > root->data)
            root->rchild = Insert(K,root->rchild);
    return root;
}
