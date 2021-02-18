算法1:
int MaxSubseqSum1(int A[],int N)
{
	int ThisSum,MaxSum =0;
	int i,j,k;
	for(i=0;i<N;i++){
		for(j=i;j<N;j++){
			ThisSum=0;
			for(k=i;k<=j;k++)
				ThisSum+=A[k];
			if(ThisSum>MaxSum)
				MaxSum=ThisSum;
		}
	}
	return MaxSum;
}
算法2:
int MaxSubseqSum2(int A[],int N)
{
	int ThisSum,MaxSum=0;
	for(i=0;i<N;i++){
		ThisSum=0;
		for(j=i;j<N;j++){
			ThisSum+=A[j];
			if(ThisSum>MaxSum)
				MaxSum=ThisSum;
		}
	}
	return MaxSum;
}
算法3：略

算法4：
int MaxSubseqSum4(int A[],int N)
{
	int ThisSum,MaxSum;
	int i;
	ThisSum=MaxSum=0;
	for(i=0;i<N;i++){
		ThisSum+=A[i];
		if(ThisSum>MaxSum)
			MaxSum=ThisSum;
		else if(ThisSum<0)
			ThisSum=0;
	}
	return MaxSum;
}
