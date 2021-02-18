#include<iostream>
using namespace std;

int BinarySearch(int a[], int K, int len){
    int left,right,mid;
    left = 1;
    right = len;
    while(left <= right){
        mid =(left+right)/2;
        if(K < a[mid]) right = mid - 1;
        else if(K > a[mid]) left = mid + 1;
        else return mid;
    }
    return -1;
}
