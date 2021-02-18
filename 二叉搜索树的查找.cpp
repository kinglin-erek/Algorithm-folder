#include <iostream>
using namespace std;

struct node
{
    int data;
    node *lchild, *rchild;
};

node * Find(int K, node* root){
    if(!root) return NULL;
    if(K > root->data)
        return Find(K,root->rchild);
    else if(K <  root->data)
        return Find(K,root->lchild);
    else
        return root;
}

node * FindMin(node *root){
    if(!root) return NULL;
    else if(!root->lchild)
        return root;
    else
        return FindMin(root->lchild);  
}

node * FindMax(node * root){
    if(root)
        while(root->rchild)
            root = root->rchild;
    return root;
}