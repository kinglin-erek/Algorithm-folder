#include<iostream>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *leftchild,*rightchild;
};

TreeNode* lowestCommonAncestor(TreeNode *root,TreeNode *p, TreeNode *q){
    if(!root || root == p || root == q)
        return root;
    TreeNode* left = lowestCommonAncestor(root->leftchild,p,q);
    TreeNode* right = lowestCommonAncestor(root->rightchild,p,q);

    if(left&&right)
        return root;
    
    return left ? left : right;
}