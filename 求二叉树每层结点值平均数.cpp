/* 给定一棵非空二叉树，
求出每层所有结点的平均值，以数组形式返回。
 注：二叉树中所有结点值大于零，在空结点处则输入 - 1。
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *leftchild, *rightchild;
};

vector<double> averageOfLevels(TreeNode *root){
    vector<double> res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        long temp=0;
        int s=q.size();
        for(int i=0;i<s;i++){
            TreeNode *t=q.front();
            q.pop();
            if(t->leftchild) q.push(t->leftchild);
            if(t->rightchild) q.push(t->rightchild);
            temp+=t->data;
        }
        res.push_back((double)temp/s);
    }
    return res;
}