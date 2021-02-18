#include<iostream>
#include<stack>
using namespace std;

struct node{
    int data;
    node *lchild,*rchild;
};

void Mid_Order(node * root){
    node * p = root;
    stack<node*> S;
    while(p || !S.empty()){
        while(p){
            S.push(p);
            p = p->lchild;
        }
        if(!S.empty()){
            p = S.top();
            S.pop();
            cout<<p->data;
            p = p->rchild;
        }
    }
}