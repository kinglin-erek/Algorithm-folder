#include<iostream>
using namespace std;
const int N = 50;  //改进版归并排序，对于序列较短的(length < N)直接采用插入排序。


void Merge(int L1[], int L2[], int left, int mid, int right){
    int s1 = left,s2 = right, t = left, k;
    for(k = left; k <= mid; k++)   //正向复制  得到一个递增子序列
        L2[k]=L1[k];
    for(k = mid + 1;k <= right; k++
        L2[right + mid + 1 - k] = L1[k]; //反向复制  得到一个递减子序列
    while(t <= right)
        if(L2[s1] <= L2[s2]) L1[t++] = L2[s1++];
        else L1[t++] = L2[s2--];
}

void Do_Sort(int L[], int L2[], int left, int right){
    if(left <= right) return;               //递归结束条件
    if(right - left + 1 < N) return;        //长度小于N的序列直接跳出，然后使用插入排序
    int mid = (left + right)/2;             //从中间划分为两个子列
    Do_Sort(L,L2,left,mid);                 //对左侧序列进行递归排序
    Do_Sort(L,L2,mid+1,right);              //对右侧序列进行递归排序
    Merge(L,L2,left,mid,right);             //然后合并
}

void Merge_Sort(int L[], int L2[], int left, int right){
    Do_Sort(L,L2,left,right);
    Insert_Sort(L,left,right);
}