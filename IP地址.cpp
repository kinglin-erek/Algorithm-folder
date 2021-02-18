/* 给定一个仅由数字组成的字符串，
从中按顺序取出四个数字，
组成一个合法的IPv4的地址，
列出所有可能的组合。 
IPv4地址由四个[0, 255] 内的整数组成，
以点’.’作为分隔符。 
例如：”25525512211” 
返回：”255.255.12.211”, 
“255.255.122.11”
 */
#include<iostream>
#include<string>
using namespace std;

bool isIP(string s, int p1, int p2, int p3){
    string slist[4]={
        s.substr(0,p1),
        s.substr(p1,p2-p1),
        s.substr(p2,p3-p2),
        s.substr(p3)
    };
    int num;
    
    for(int i=0; i<4; ++i){
        if(slist[i] != "0" && slist[i][0] == '0'){
            return false;
        }
        num = stoi(slist[i]);
        if(num > 255){
            return false;
        }
    }
    return true;
}

int validIP(string ip){
    int p1, p2, p3;
    int ipNum = 0;
    int ipLen = ip.length();
    for(p1 = 1; p1 <= 3 && ipLen-p1 >= 3; ++p1){
        for(p2 = p1+1;p2 <= p1+3 && ipLen-p2 >= 2; ++p2){
            for(p3 = p2+1;p3 <= p2+3 && ipLen-p3 >= 1; ++p3){
                if(isIP(ip, p1, p2, p3)){
                    string str = ip;
                    str.insert(p1,".");
                    str.insert(p2+1,".");
                    str.insert(p3+2,".");
                    cout<<str<<endl;
                    ipNum++;
                }
            }
        }
    }
    return ipNum;
}