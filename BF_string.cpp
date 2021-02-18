#include<iostream>
#include<string>
int find(string &pat){
    char *p=pat.ch,*s=ch;
    int i=0;
    while(*p!='\0'&&*s!='\0')
        if(*p++!=*s++)
        {
            i++;
            s=ch+i;
            p=pat.ch;
        }
    if(*p=='\0')
        return i;
    else return -1;
}