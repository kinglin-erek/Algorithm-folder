#include<iostream>
#include<stack>
using namespace std;

struct AVLNode{
	int data;
	int balance;
	AVLNode *left,*right;
	AVLNode(int d) : data(d),left(NULL),right(NULL),balance(0){}
};

void RotateLeft(AVLNode *Tree,AVLNode *& NewTree){
	NewTree = Tree->right;
	Tree->right = NewTree->left;
	NewTree->left = Tree;
}

void RotateRight(AVLNode *Tree,AVLNode *& NewTree){
	NewTree = Tree->left;
	Tree->left = NewTree->right;
	NewTree->right = Tree;
}

void RotateLeft(AVLNode*& ptr) {
	AVLNode* subL = ptr;
	ptr = subL->right;
	subL->right = ptr->left;
	ptr->left = subL;
	ptr->balance = subL->balance = 0;
}

void RotateRight(AVLNode*& ptr) {
	AVLNode* subR = ptr;
	ptr = subR->left;
	subR->left = ptr->right;
	ptr->right = subR;
	ptr->balance = subR->balance = 0;
}

void RotateLR(AVLNode*& ptr) {
	AVLNode* subR = ptr, * subL = subR->left;
	ptr = subL->right;
	subL->right = ptr->left;
	ptr->left = subL;
	if (ptr->balance <= 0) subL->balance = 0;
	else subL->balance = -1;
	subR->left = ptr->right;
	ptr->right = subR;
	if (ptr->balance == -1) subR->balance = 1;
	else subR->balance = 0;
	ptr->balance = 0;
}

void RotateRL(AVLNode*& ptr) {
	AVLNode* subL = ptr, * subR = subL->right;
	ptr = subR->left;
	subR->left = ptr->right;
	ptr->right = subR;
	if (ptr->balance >= 0) subR->balance = 0;
	else subR->balance = 1;
	subL->right = ptr->left;
	ptr->left = subL;
	if (ptr->balance == 1) subL->balance = -1;
	else subL->balance = 0;
	ptr->balance = 0;
}

void LeftBalance(AVLNode *& Tree,int & taller){
	AVLNode *leftsub=Tree->left,*rightsub;
	switch(leftsub->balance){
	case -1:
		Tree->balance = leftsub->balance = 0;
		RotateRight(Tree,Tree);
		taller=0;
		break;
	case 0:
			cout<<"树已经平衡化\n";break;
	case 1:
		rightsub = leftsub->right;
		switch(rightsub->balance){
		case -1:
				Tree->balance = 1;
				leftsub->balance = 0;
				break;
		case 0:
			Tree->balance = leftsub->balance = 0;
			break;
		case 1:
			Tree->balance = 0;
			leftsub->balance = -1;
		}
		rightsub->balance = 0;
		RotateLeft(leftsub,Tree->left);
		RotateRight(Tree,Tree);
		taller=0;
	}	
}

void RotateBalance(AVLNode *& Tree,int & taller){
	AVLNode *rightsub=Tree->right,*leftsub;
	switch(rightsub->balance){
	case -1:
		Tree->balance = rightsub->balance = 0;
		RotateLeft(Tree,Tree);
		taller=0;
		break;
	case 0:
			cout<<"树已经平衡化\n";break;
	case 1:
		leftsub = rightsub->right;
		switch(leftsub->balance){
		case -1:
				Tree->balance = 1;
				rightsub->balance = 0;
				break;
		case 0:
			Tree->balance = rightsub->balance = 0;
			break;
		case 1:
			Tree->balance = 0;
			rightsub->balance = -1;
		}
		leftsub->balance = 0;
		RotateRight(rightsub,Tree->left);
		RotateLeft(Tree,Tree);
		taller=0;
	}	
}

bool Insert(AVLNode *& ptr, int & el){ //AVL树的插入算法
	AVLNode * pr = NULL, * p = ptr, *q;int d;
	stack<AVLNode *> st;
	while(p != NULL){
		if(el == p->data) return false;
		pr = p;st.push(pr);
		if(el < p->data) p = p->left;
		else p = p->right;
	}
	p = new AVLNode(el);
	if(p == NULL){cerr<<"存储空间不足!"<<endl;exit(1);}
	if(pr == NULL) {ptr = p; return true;}
	if(el < pr->data) pr->left = p;
	else pr->right = p;
	while(st.empty() == false){
		pr = st.top();st.pop();
		if(p == pr->left) pr->balance--;
		else pr->balance++;
		if(pr->balance == 0) break;
		if(pr->balance == 1 || pr->balance == -1) p = pr;
		else{
			d = (pr->balance < 0)? -1 : 1;
			if(p->balance == d){
				if(d == -1) RotateRight(pr,pr);
				else RotateLeft(pr,pr);
			}
			else{
				if(d == -1) RotateLR(pr,pr->balance);
				else RotateRL(pr,pr->balance);
			}
			break;
		}
	}
	if(st.empty() == true) ptr = pr;
	else{
		q = st.top();
		if(q->data > pr->data) q->left = pr;
		else q->right = pr;
	}
	return true;
}

bool Remove(AVLNode *& ptr, int x,int & el){     //AVL树的删除算法
	AVLNode *pr = NULL, *p = ptr, *q, *ppr; int d, dd = 0;
	stack<AVLNode *> st;
	while(p != NULL){
		if(x == p->data) break;
		pr = p;st.push(pr);
		if(x <p->data) p = p->left;
		else p = p->right;
	}
	if(p == NULL) return false;
	if(p->left != NULL && p->right != NULL){
		pr = p;st.push(pr);
		q = p->left;
		while(q->right != NULL)
			{pr = q;st.push(pr);q = q->right;}
		p->data = q->data;
		p = q;
		}
	if(p->left != NULL) q = p->left;
	else q = p->right;
	if(pr == NULL) ptr = q;
	else {
		if(pr->left == p) pr->left = q;
		else pr->right = q;
		while(st.empty() == false){
			pr=st.top();st.pop();
			if(pr->right == q) pr->balance--;
			else pr->balance++;
			if(st.empty() == false){
				ppr = st.top();
				dd = (ppr->left == pr) ? -1 : 1;
			}
			else dd = 0;
			if(pr->balance == 1 || pr->balance == -1) break;
			if(pr->balance != 0){
				if(pr->balance < 0){d = -1;q = pr->left;}
				else{d = 1;q = pr->right;}
				if(q->balance == 0){
					if(d == -1)
						{RotateRight(pr,pr); pr->balance=1; pr->left->balance = -1;}
					else
						{RotateLeft(pr,pr); pr->balance = -1; pr->right->balance = 1;}
					break;
				}
				if(q->balance == d){
					if(d == -1) RotateRight(pr,pr);
					else RotateLeft(pr,pr);
				}
				else{
					if(d == -1) RotateLR(pr,pr->balance);
					else RotateRL(pr,pr->balance);
				}
				if(dd == -1) ppr->left = pr;
				else if(dd == 1) ppr->right = pr;
			}
			q = pr;
		}
		if(st.empty() == true) ptr = pr;
	}
	delete p;return true;
}