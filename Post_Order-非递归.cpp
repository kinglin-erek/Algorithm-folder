#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    node *lchild, *rchild;
};

void Mid_Order(node *root,int len){
    node *p = root;
    stack<node *> S;
    int tag[len];
    while (p || !S.empty()){
        while (p){
            S.push(p);
            tag[S.top()->data]=0;
            p = p->lchild;
        }
        while(!S.empty() && tag[S.top()->data]==1){
            p = S.top();
            S.pop();
            cout<<p->data<<" ";
        }
        if (!S.empty()){
            tag[S.top()->data] = 1;
            p = S.top();
            S.pop();
            p = p->rchild;
        }
    }
}