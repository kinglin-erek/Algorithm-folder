#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

struct node{
    int val;
    node *lchild,*rchild;
    node():val(0),lchild(NULL),rchild(NULL){}
};

node * Create(vector<int> pre,vector<int> mid){ //len是mid数组的长度
    int i=0;
	int len = mid.size();
	if(len == 0)
        return NULL; 
    node *root = new node();
    root->val=pre[0];
    for(i=0;i<len;i++)
        if(mid[i]==root->val) break;
    vector<int> ltr_m,rtr_m,ltr_p,rtr_p;
	for(int j=0;j<i;j++){
		 ltr_p.push_back(pre[j+1]);
		 ltr_m.push_back(mid[j]);
	}
	for(int j=0;j<len-i-1;j++){
		rtr_p.push_back(pre[j+i+1]);
		rtr_m.push_back(mid[j+i+1]);
	}  
    root->lchild = Create(ltr_p,ltr_m);
    root->rchild = Create(rtr_p,rtr_m);
    return root;
}

void dele_tar(node *root, int tar)
{
	if(root == NULL)
		return;
	dele_tar(root->lchild,tar);
	if(root->val <= tar)  root -> val = -1;
	dele_tar(root->rchild,tar);
}

void swap_tar(node *root)
{
	if(root == NULL)
		return;
	swap_tar(root->lchild);
	if(root->val == -1){
		if(root->lchild != NULL &&root->lchild->val != -1){
			root->val = root->lchild->val;
			root->lchild->val = -1;
		}
		else if(root->rchild != NULL && root->rchild->val != -1){
			root->val = root->rchild->val;
			root->rchild->val = -1;
		}
	}
	swap_tar(root->rchild);
}

int main(){
    ifstream in("input_11_1.txt", ios::in);
	ofstream out("output_11_1.txt", ios::out);    
	int temp,target,len=0;
	vector<int> pre,mid;
    while(in >> temp)
        len++;
	in.close();

	ifstream in1("input_11_1.txt", ios::in);
	for(int i=0;i<(len-1)/2;i++){
		in1 >> temp;
		pre.push_back(temp);
	}
	for(int i=0;i<(len-1)/2;i++){
		in1 >> temp;
		mid.push_back(temp);
	}
	in1 >> target;
	node *p = Create(pre,mid);
	dele_tar(p,target);
	swap_tar(p);
    queue <node*> q;
    if (p != NULL)
        q.push(p);   

    while (q.empty() == false)  
    {
		out<<q.front()->val<<" "; 
		if(q.front()->lchild != NULL)   
			q.push(q.front()->lchild);   
		else if(q.front()->rchild != NULL && q.front()->lchild == NULL){
			node * temp = new node();
			temp->val = -1;
			q.push(temp);
		}
        if(q.front()->rchild != NULL)
			q.push(q.front()->rchild);    
		else if(q.front()->lchild != NULL && q.front()->rchild == NULL){
			node * temp = new node();
			temp->val = -1;
			q.push(temp);
		}
        q.pop();  
	}
	return 0;
}