#include <iostream>
#include <string.h>

using namespace std;
const int maxn = 10000;
int arr[maxn];

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
    return;
}

int parent(int n){ return (n - 1) / 2; }

void buildHeap(int n , int data[])
{
    for(int i= 1; i < n ; i++)
    {
        int  t = i;
        while( t != 0 && data[parent(t)] > data[t])
        {
            swap(data[t], data[parent(t)]);
            t = parent(t);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(arr,0,sizeof(arr));
    int N,lim,temp1,temp2,temp,ans;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    buildHeap(N,arr);
    ans = 0;
    lim = N;
    while(1){
        temp1 = arr[0];
        swap(arr[lim - 1],arr[0]);
        lim--;
        if(lim == 0){
            ans += temp1;
            break;
        }
        buildHeap(lim,arr);
        temp2 = arr[0];
        swap(arr[lim - 1],arr[0]);
        temp = temp1 + temp2;
        ans += temp;
        arr[lim - 1] = temp;
        buildHeap(lim,arr);
        //cout << temp1 << " " << temp2 << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}