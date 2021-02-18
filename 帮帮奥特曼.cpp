#include<iostream>
#include<queue>
using namespace std;

int main(){
    int temp;
    int res=0;
    priority_queue<int,vector<int>,greater<int> > heap; //优先级队列  这个是最小堆,top是最小的值,最大堆就写 less<int>
    while(cin>>temp)
        heap.push(temp);
    
    while(heap.size() > 1){
        int a = heap.top();
        heap.pop();
        int b=heap.top();
        heap.pop();
        res += a+b;
        heap.push(a+b);
    }
    res += heap.top();

    return 0;
}