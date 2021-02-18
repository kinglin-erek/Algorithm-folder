#include<iostream>
#include<string>
using namespace std;

struct node{
    char val;
    node *lchild,*rchild;
    node():val(' '),lchild(NULL),rchild(NULL){}
};

node * Create(string pre,string mid){
    int i,len = mid.length();
    if(len == 0)
        return NULL;
    
    node *root = new node();
    root->val=pre[0];

    for(i=0;i<len;i++)
        if(mid[i]==root->val) break;
    
    string ltr_m,rtr_m,ltr_p,rtr_p;

    ltr_p = pre.substr(1,i);
    rtr_p = pre.substr(i+1);

    ltr_m = mid.substr(0,i);
    rtr_m = mid.substr(i+1);
    
    root->lchild = Create(ltr_p,ltr_m);
    root->rchild = Create(rtr_p,rtr_m);

    return root;
}

int Height(node *root){
    if(root == NULL)
        return 0;
    else{
        int i = Height(root->lchild);
        int j = Height(root->rchild);
        return(i<j)?j+1:i+1;
    }
}

int main(){
    int N,i,r_len;
    string s_pre,s_mid;
    node *root=NULL;
    int h;
    cin>>N;
    if(N>50) return 0;
    cin>>s_pre;
    cin>>s_mid;
    root=Create(s_pre,s_mid);
    h=Height(root);
    cout<<h;
    return 0;
}