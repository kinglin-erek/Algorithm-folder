#include <iostream>
using namespace std;
struct node
{
    int data;
    node *lchild, *rchild;
    node() : data(0), lchild(NULL), rchild(NULL) {}
};
node *FindMin(node *root)
{
    if (!root)
        return NULL;
    else if (!root->lchild)
        return root;
    else
        return FindMin(root->lchild);
}
node *Delete(int K, node *root)
{
    node * p;
    if (!root)  cout<<"未找到要删除的元素!"<<endl;
    else if (K < root->data)
        root->lchild = Delete(K, root->lchild);
    else if (K > root->data)
        root->rchild = Delete(K, root->rchild);
    else if (root->lchild && root->rchild){
        p = FindMin(root->rchild);
        root->data = p->data;
        root->rchild = Delete(root->data,root->rchild);
    }else{
        p = root;
        if(!root->lchild)
            root = root->rchild;
        else if(!root->rchild)
            root = root->lchild;
            delete p;
        }
    return root;
}
