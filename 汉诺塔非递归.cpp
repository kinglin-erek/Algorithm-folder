#include<iostream>
#include<stack>
using namespace std;
struct node{
    int n;
    char a,b,c;
};

stack<node> s;
node wrap(int n, char a, char b, char c){
    node t;
    t.n = n;
    t.a = a;
    t.b = b;
    t.c = c;
    return t;
}
int main(){
    int n;
    cin>>n;
    node t;
    t.n = n;
    t.a = 'A';
    t.b = 'B';
    t.c = 'C';
    s.push(t);
    while(!s.empty()){
        t = s.top();
        s.pop();
        if(t.n == 1)
            cout<<t.a<<"->"<<t.c<<endl;
        else{
            s.push(wrap(t.n-1,t.b,t.a,t.c));
            s.push(wrap(1,t.a,t.b,t.c));
            s.push(wrap(t.n-1,t.a,t.c,t.b));
        }
    }
    return 0;
}