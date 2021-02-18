#include<iostream>
#include<stack>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *leftchild,*rightchild;
};

bool hasPathSum_rec(TreeNode * root,int sum){ //中序递归
    if(root == NULL) return false;
    int new_sum = sum - root->data;
    if(!root->leftchild &&
        !root->rightchild)
        return new_sum == 0;
    return hasPathSum_rec(root->leftchild,new_sum)||hasPathSum_rec(root->rightchild,new_sum);
}

bool hasPathSum(TreeNode *root, int sum){ //非递归方法
    if(root == NULL) return false;
    stack<pair<TreeNode*,int>> st;
    st.push({root,root->data});
    while(!st.empty()){
        TreeNode * current = st.top().first;
        int total_sum = st.top().second;
        st.pop();
        if(current->rightchild)
            st.push({current->rightchild,total_sum+current->rightchild->data});
        if(current->leftchild)
            st.push({current->leftchild, total_sum + current->leftchild->data});
        if(!current->rightchild && !current->leftchild && total_sum == sum){
            return true;
        }
    }
    return false;
}
