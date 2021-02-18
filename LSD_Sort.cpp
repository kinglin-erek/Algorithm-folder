#include<iostream>
using namespace std;
#define  maxN 300
const int radix = 10;
const int N = 50;
const int bytes = 256;

void Insert_Sort(int a[], int l, int r){

}

int getDigit(int a, int b){

    return 0;
}

void Sort(int L[], int left,int right){ //列表 排序左端/右端
    static int aux[maxN];
    int i,j,d,count[radix+1];
    if(right - left + 1 < N){Insert_Sort(L,left,right);return;}
    for(d = bytes - 1; d > 0; d--){
        for(j = 0; j < radix; j++) count[j] = 0;
        for(i = left; i < right; i++)
            count[getDigit(L[i],d)+1]++;
        for(j = 1; j < radix ; j++)
            count[j] += count[j-1];
        for()
    }

    
}