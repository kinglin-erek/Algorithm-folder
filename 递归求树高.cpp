#include <iostream>
using namespace std;

struct node
{
    int data;
    node *lchild, *rchild;
};

int height(node *root){
    int HL,HR,MAXH;
    if(root){
        HL = height(root->lchild);
        HR = height(root->rchild);
        MAXH = (HL > HR) ? HL : HR ;
        return (MAXH+1);
    }
    else return 0;
}