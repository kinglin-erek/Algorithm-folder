/*
给定一个被编码字符串，将其解码。
编码规则为：
k[被编码串]，指[]内的字符串重复k(k>0)次，
保证输入的被编码串是合法的
（不存在空格、[]数量匹配、不含0-9数字字符）
输入：3[a]2[bc]
输出：aaabcbc
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

string decodeString(string s){
    stack<string> chars;
    stack<int>  nums;
    string res;
    int num = 0;
    for(char c : s){
        if(isdigit(c)){
            num = num*10 + (c-'0');
        }
        else if(isalpha(c)){
            res.push_back(c);
        }
        else if(c == '['){
            chars.push(res);
            nums.push(num);
            res = "";
            num = 0;
        }
        else if(c==']'){
            string tmp = res;
            for(int i=0;i < nums.top()-1; ++i){
                res +=tmp;
            }
            res = chars.top() +res;
            chars.pop();
            nums.pop();
        }
    }
    return res;
}