#include<iostream>

int akm(int m, int n){
    unsigned v;
    if(m==0)
        return n+1;
    if(n==0)
        return akm(m-1,1);
    v = akm(m,n-1);
    return akm(m-1,v);
}