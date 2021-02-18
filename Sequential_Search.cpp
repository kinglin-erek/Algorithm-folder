#include<iostream>
using namespace std;
int SequentialSearch(int a[], int K,int len){
    int i;
    a[0] = K;
    for(i = len; a[i] != K; i--);
    return i;
}