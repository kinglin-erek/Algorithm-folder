#include<iostream>
#include<string>
using namespace std;

struct Node{
    char val;
    Node *left,*right;
    Node(char c):val(c),left(NULL),right(NULL){}
};

Node* create(const string &s){
    char c = getType(s);
    Node* root = new Node(c);
    int len = s.length();
    if(len>1){
        Node* l = create(s.substr(0,len/2));
        Node* r = create(s.substr(len/2,len/2));
        root->left = l;
        root->right = r;
    }
    return root; 
}

char getType(const string &s){
    string::size_type a = s.find('0');
    string::size_type b = s.find('1');
    if(a != string::npos && b != string::npos)
        return 'U';
    else if(a == string::npos)
        return 'D';
    else return 'F';
}