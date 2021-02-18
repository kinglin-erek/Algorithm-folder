#include<iostream>
#include<vector>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode() : data(0), leftchild(NULL), rightchild(NULL) {}
    TreeNode(int x) : data(x), leftchild(NULL), rightchild(NULL) {}
    TreeNode(int x, TreeNode *leftchild, TreeNode *rightchild) : data(x), leftchild(leftchild), rightchild(rightchild) {}
};

TreeNode *buildTree(vector<int> arr)
{
    if (arr.size() == 0)
        return NULL;
    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (i < arr.size())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node != NULL)
        {
            TreeNode *l = (arr[i] != -1) ? new TreeNode(arr[i]) : nullptr;
            TreeNode *r = ((i + 1) < arr.size() && arr[i + 1] != -1) ? new TreeNode(arr[i + 1]) : nullptr;
            node->leftchild = l;
            node->rightchild = r;
            q.push(l);
            q.push(r);
            i += 2;
        }
    }
    return root;
}

void pre_traversal(TreeNode *root)
{
    stack<TreeNode *> node_stack;
    while (root != nullptr || !node_stack.empty())
    {
        if (root != nullptr)
        {
            cout << root->data << " ";
            node_stack.push(root);
            root = root->leftchild;
        }
        else
        {
            root = node_stack.top();
            node_stack.pop();
            root = root->rightchild;
        }
    }
}

int main()
{
    int v;
    vector<int> a;
    cout << "enter the values one by one(must be >= 0):" << endl;
    while (cin >> v)
    {
        a.push_back(v);
        if (cin.get() == '\n')
            break;
    }
    TreeNode *root = buildTree(a);
    pre_traversal(root);
    return 0;
}