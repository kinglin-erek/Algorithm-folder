#include<iostream>
using namespace std;

int post[]={0,0,0,0,0,0};
int pre[]={1,2,3,4,5,6};
int in[]={3,2,4,1,6,5};

void solve(int preL, int inL, int postL, int n){
    if(n == 0) return;
    if(n == 1) {
        post[postL] = pre[preL];
        return;
    }
    int root = pre[preL];int i;
    post[postL+n-1] = root;
    for(i=0;i<n;i++)
        if(in[inL+i] == root) break;
    int L = i; int R = n-L-1;
    solve(preL+1, inL, postL, L);
    solve(preL+L+1, inL+L+1, postL+L, R);
}

int main(){
    solve(0,0,0,6);
    for(int i=0;i<6;i++)
        cout<<post[i];
}