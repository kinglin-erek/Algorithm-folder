#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

const int maxn = 10000;

struct node{
    int val,depth;
    node(int a, int b){val = a;depth = b;}
};

vector<node> vec;
vector<int> ans1,ans2,dep;

bool cmp(node a, node b){
    return a.val < b.val;
}

int main(){
    int temp,cnt,depth,pow,min_val,temp1,temp2,t_dep,max_dep;
    cnt = depth = max_dep = 0;
    pow = 1;
    min_val = -1;
    while(cin >> temp){
        if(cnt == pow){
            cnt = 0;
            depth++;
            pow *= 2;
        }
        if(temp != -1)vec.push_back(node(temp,depth));
        cnt++;
    }
    sort(vec.begin(),vec.end(),cmp);
    auto iter1 = vec.begin();
    auto iter2 = iter1;
    iter2++;
    for(iter2; iter2 != vec.end(); iter1++, iter2++){
        temp1 = iter1 -> val;
        temp2 = iter2 -> val;
        if(temp1 > temp2){
            temp = temp1;
            temp1 = temp2;
            temp2 = temp1;}

        t_dep = (iter1->depth > iter2->depth) ?(iter1->depth - iter2->depth):(iter2->depth - iter1->depth);
        
		if(min_val == -1){
            min_val = temp2 - temp1;
            ans1.push_back(temp1);
            ans2.push_back(temp2);
            dep.push_back(t_dep);
            max_dep = t_dep;}
		
		else if(min_val > temp2 - temp1){
            ans1.clear();
            ans2.clear();
            dep.clear();
            min_val = temp2 - temp1;
            ans1.push_back(temp1);
            ans2.push_back(temp2);
            dep.push_back(t_dep);
            max_dep = max(max_dep,t_dep);}

		else if(min_val == temp2 - temp1){
            ans1.push_back(temp1);
            ans2.push_back(temp2);
            dep.push_back(t_dep);
            max_dep = max(max_dep,t_dep);}
    }
        auto it2 = ans2.begin();
        auto it3 = dep.begin();

    for(auto it=ans1.begin();it != ans1.end();it++, it2++, it3++)
        if(*it3 == max_dep) 
			cout<<*it<<" "<<*it2<<" "<<endl;
    
    return 0;
}