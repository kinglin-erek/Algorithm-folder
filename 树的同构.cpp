#include<stdio.h>
#include<string>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree],T2[MaxTree];

int lsomorphic(Tree R1,Tree R2)
{
	
}


Tree BuildTree(struct TreeNode T[])
{
	int i,N,Root,check[MaxTree];
	scanf("%d",&N);
	if(N){
		for(i=0;i<N;i++) check[i]=0;
		for(i=0;i<N;i++){
			scanf("%c%c%c",&T[i].Element,&cl,&cr);
			if(cl!='-'){
				T[i].Left=cl-'0';
				check[T[i].Left]=1;
			}
			else T[i].Left=Null;

		}
		for(i=0;i<N;i++){
		if(!check[i]) break;
		Root=i;
		}
	}
	return Root;
}

int main()
{
	Tree R1,R2;
	R1=BuildTree(T1);
	R2=BuildTree(T2);
	if(lsomorphic(R1,R2)) printf("Yes\n");
	else printf("No\n");
	return 0;
}
