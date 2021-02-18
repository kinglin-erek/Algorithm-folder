#include<iostream>
#include<cstdlib>

#define N 20
using namespace std;

int A[N];//排序后的树
int T[N];//结果树

int GetLeftLength(int n){
    return n;
}

int compare(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

void solve(int ALeft, int ARight, int TRoot){
    //初始调用 solve(0,N-1,0)
    int n = ARight = ALeft + 1;
    if(n == 0) return;
    int L = GetLeftLength(n);
    T[TRoot] = A[ALeft + L];
    int LeftTRoot = TRoot * 2 + 1;
    int RightTRoot = LeftTRoot + 1;
    solve(ALeft, ALeft+L-1,LeftTRoot);
    solve(ALeft+L+1, ARight,RightTRoot);
}
int main(){
    for(int i=0; i<N; i++)
        cin>>A[i];
    qsort(A,N,sizeof(int),compare);
    solve(0,N-1,0);
    return 0;
}