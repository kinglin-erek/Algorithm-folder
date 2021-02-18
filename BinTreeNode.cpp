#include<iostream>
using namespace std;
template<class T>
struct BinTreeNode{
    T data;
    BinTreeNode<T> *leftChild,*rightChild;
    BinTreeNode(T x,BinTreeNode<T> *l = NULL,BinTreeNode<T> *T=NULL):data(x),leftChild(l),rightChild(r){}
};

template<class T>
class BinaryTree{
    public:
        BinaryTree():root(NULL){}
        BinaryTree(T value):RefValue(value),root(NULL){}
        BinaryTree(BinaryTree<T>&s)
        ~BinaryTree(){destroy(root);}
        bool IsEmpty(){return(root == NULL)?true:false;}
        BinTreeNode
}