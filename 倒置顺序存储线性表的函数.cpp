#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void rever(int l[],int n)
{
	int j,t;
	for(j=0;j<n/2;j++)
	{
		t=l[j];
		l[j]=l[n-j-1];
		l[n-j-1]=t;
	}
}


int main()
{
	int list[19]={0},i,n=19;
	srand((int)time(0));

	for(i=0;i<n;i++) 
		list[i]=(rand()%100);

	for(i=0;i<n;i++)  cout<<list[i]<<"  ";
	cout<<endl;
	rever(list,n);
	
	for(i=0;i<n;i++)  cout<<list[i]<<"  ";


	return 0;
}