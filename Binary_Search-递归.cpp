#include<iostream>
using namespace std;

int binarySearch(int a[], int K, int len){
    return search(0,len-1,a,K);
}
int search(int start, int end, int a[], int K){
    if(start <= end){
        int index = (start+end)/2;
        if(a[index] == K) 
        return index;
        else if(K > a[index])
            return search(index+1,end,a,K);
        else if(K < a[index])
            return search(start,index-1,a,K);
        else
            return -1;
    }    
    else
        return -1;
}