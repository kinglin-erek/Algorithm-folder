#include<iostream>
using namespace std;

struct BSTNode{
    int data;
    BSTNode *left,*right;
    BSTNode() : data(0),left(NULL),right(NULL){}
    BSTNode(int val) : data(val), left(NULL), right(NULL) {}
};

//搜索
BSTNode* Search(const int x,BSTNode *ptr){
    if(ptr == NULL)
        return NULL;
    else if(x < ptr->data)
        return Search(x,ptr->left);
    else if(x > ptr->data)
        return Search(x,ptr->right);
    else return ptr;
}
//插入
bool Insert(const int &el, BSTNode *& ptr){
    if(ptr == NULL){
        ptr = new BSTNode(el);
        if(ptr == NULL) {cout<<"Out of space!"<<endl;exit(1);}
        return true;
    }
    else if(el < ptr->data) Insert(el,ptr->left);
    else if(el > ptr->data) Insert(el,ptr->right);
    else return false;
}
//建树
BSTNode* BST(int value){   //value为结束条件
    int x; BSTNode* root = NULL;
    cin >> x;
    while(x != value){
        Insert(x,root);cin >> x;
    }
	return root;
}

//找最小值结点
BSTNode* Min(BSTNode* ptr){
    BSTNode* cur = ptr;
    while(!(cur->left == NULL))
        cur = cur->left;
    return cur;
}

//删除
bool Remove(const int &x,BSTNode*& ptr){
    if(ptr != NULL)
        if(x < ptr->data)
            Remove(x,ptr->left);
        else if(x > ptr->data)
            Remove(x,ptr->right);
        else if(ptr->left!=NULL && ptr->right!=NULL){
            BSTNode* temp = Min(ptr->right);
            ptr->data = temp->data;
            Remove(ptr->data,ptr->right);
        }
        else {
            BSTNode* temp=ptr;
            if(ptr->left == NULL)
                ptr = ptr->right;
            else if(ptr->right == NULL)
                ptr = ptr->left;
            delete temp;
            return true;
        }
        return false;
}