#include<iostream>
#include<stack>
using namespace std;

int partition(int list[], int left, int right) {
	int temp = list[left];
	while (left < right) {
		while (left < right && list[right] >= temp)
			--right;
		list[left] = list[right];

		while (left < right && list[left] <= temp)
			++left;
		list[right] = list[left];
	}
	list[left] = temp;
	return left;
}

void QuickSort(int list[], int left, int right) {  //非递归，迭代快排
	//手动利用栈来存储每次分块快排的起始点
	//栈非空时循环获取中轴入栈
	stack<int> Stack;
	if (left < right)
	{
		int border = partition(list, left, right);

		if (border - 1 > left) //确保左分区存在
		{
			//将左分区端点入栈
			Stack.push(left);
			Stack.push(border - 1);
		}
		if (border + 1 < right) //确保右分区存在
		{
			Stack.push(border + 1);
			Stack.push(right);
		}

		while (!Stack.empty())
		{
			//得到某分区的左右边界
			int right = Stack.top();
			Stack.pop();
			int left = Stack.top();
			Stack.pop();

			border = partition(list, left, right);
			if (border - 1 > left) //确保左分区存在
			{
				//将左分区端点入栈
				Stack.push(left);
				Stack.push(border - 1);
			}
			if (border + 1 < right) //确保右分区存在
			{
				Stack.push(border + 1);
				Stack.push(right);
			}
		}
	}
}


int main() {
	int list[100];
	srand(0);
	for (int i = 0; i < 100; i++) list[i] = rand() % 100;
	QuickSort(list, 0, 99);
	for (int i = 0; i < 100; i++) cout << list[i] << " ";

	return 0;
}