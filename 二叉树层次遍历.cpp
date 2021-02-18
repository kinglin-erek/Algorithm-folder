#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    node *lchild,*rchild;
};

void Level_Order(node *root){
    queue<node*> q;node* p = root;
    if(!root) return;
    q.push(p);
    while(!q.empty()){
        p = q.front(); q.pop();
        cout<<p->data;
        if(p->lchild) q.push(p->lchild);
        if(p->rchild) q.push(p->rchild);
    }
}