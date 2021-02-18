#include<iostream>
#include<stack>
using namespace std;

const int maxSize = 20;

unsigned akm(unsigned m, unsigned n){
    struct node {unsigned vm, vn;};
    stack<node> st;
    node w;
    unsigned v;
    w.vm = m;w.vn = n; st.push(w);
    do{
        while(st.top().vm > 0){
            while(st.top().vn >0){
                w.vn--;st.push(w);
            }
            w=st.top();
            st.pop();
            w.vm--;w.vn = 1; st.push(w);
        }
        if(st.empty() == 0){
            w = st.top();
            st.pop();
            w.vm--;
            w.vn = v;
            st.push(w);
        }
    }while(st.empty() == 0);

    return v;
}