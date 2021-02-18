#include<iostream>
using namespace std;

template<class T>
struct ThreadNode{
    T data;
    int ltag,rtag;
    ThreadNode<T> *leftChild,*rightChild;
    ThreadNode(const T item):data(item),leftChild(NULL),rightChild(NULL),ltag(0),rtag(0){}
};

template<class T>
class ThreadTree{
    protected:
        ThreadNode<T>*root;
        void createInThread(ThreadNode<T> *current,ThreadNode<T>*&pre);
    ThreadNode<T> *parent(ThreadNode<T>*t);
    public:
        ThreadTree():root(NULL){}
        void createInThread();
        ThreadNode<T> *First(ThreadNode<T>*current);
        ThreadNode<T> *Last(ThreadNode<T>*current);
        ThreadNode<T> *Next(ThreadNode<T>*current);
        ThreadNode<T> *Prior(ThreadNode<T>*current);
        void midorder(void(*visit)(ThreadNode<T>*p));
        void Preorder(void(*visit)(ThreadNode<T>*p));
        void postorder(void(*visit)(ThreadNode<T>*p));
};
template<class T>
ThreadNode<T> *ThreadTree<T>::First(ThreadNode<T>*current){
    ThreadNode<T> *p=current;
    while(p->ltag==0)p=p->leftChild;
    return p;
};

template<class T>
ThreadNode<T> *ThreadTree<T>::Next(ThreadNode<T>*current){
    ThreadNode<T> *p=current->rightChild;
    if(current->rtag==0)return First(p);
    else return p;
};

template<class T>
ThreadNode<T> *ThreadTree<T>::Last(ThreadNode<T>*current){
    ThreadNode<T> *p=current;
    while(p->rtag==0)p=p->rightChild;
    return p;
};

template<class T>
ThreadNode<T> *ThreadTree<T>::Prior(ThreadNode<T>*current){
    ThreadNode<T> *p=current->leftChild;
    if(current->ltag==0) return Last(p);
    else return p;
};

template<class T>
void ThreadTree<T>::midorder(void(*visit)(ThreadNode<T>*p)){
    ThreadNode<T> *p;
    for(p=First(root);p!=NULL;p=Next(p)) visit(p);
};

template<class T>
void ThreadTree<T>::createInThread(){
    ThreadNode<T> *pre = NULL;
    if(root != NULL){
        createInThread(root,pre);
        pre->rightChild==NULL;pre->rtag = 1;
    }
};

template<class T>
void ThreadTree<T>::createInThread(ThreadNode<T>*current,ThreadNode<T>*&pre){
    if(current==NULL)return;
    createInThread(current->leftChild,pre);
    if(current->leftChild==NULL)
        {current->leftChild=pre;current->ltag=1;}
    if(pre!=NULL&&pre->rightChild==NULL)
        {pre->rightChild=current;pre->rtag=1;}
    pre=current;
    createInThread(current->rightChild,pre);
};

template<class T>
void thread_sort(T a[],T n)
{
    ThreadNode<T> *head;
    head =createInTread(ThreadNode<T> *)
}

int main(){
  return 0;
}