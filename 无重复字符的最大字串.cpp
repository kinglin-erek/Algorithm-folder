#include<iostream>
#include<string>

using namespace std;

int lengthOfLongestSubstring(string s){
    int n=s.length();
    int i=0,j=0;
    int maxLen=0;
    bool exist[256]={false};
    while(j<n){
        if(exist[s[j]]){
            maxLen = j-i >maxLen ? j-i :maxLen;
            while(s[i]!=s[j]){
                exist[s[i]]=false;
                i++;
            }
            i++;
            j++;
        } else {
            exist[s[j]]=true;
            j++;
        }
    }
    maxLen = n-i > maxLen ? n-i : maxLen;
    return maxLen;
}