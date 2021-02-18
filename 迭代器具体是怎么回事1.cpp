#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string szWord;
	vector<string> text;
	while(cin>>szWord)
		text.push_back(szWord);
	sort(text.begin(),text.end());
	for(int iX=0;iX<text.size();iX++)
		cout<<text[iX]<<endl;
}
