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

void QuickSort(int list[], int left, int right) {  //�ǵݹ飬��������
	//�ֶ�����ջ���洢ÿ�ηֿ���ŵ���ʼ��
	//ջ�ǿ�ʱѭ����ȡ������ջ
	stack<int> Stack;
	if (left < right)
	{
		int border = partition(list, left, right);

		if (border - 1 > left) //ȷ�����������
		{
			//��������˵���ջ
			Stack.push(left);
			Stack.push(border - 1);
		}
		if (border + 1 < right) //ȷ���ҷ�������
		{
			Stack.push(border + 1);
			Stack.push(right);
		}

		while (!Stack.empty())
		{
			//�õ�ĳ���������ұ߽�
			int right = Stack.top();
			Stack.pop();
			int left = Stack.top();
			Stack.pop();

			border = partition(list, left, right);
			if (border - 1 > left) //ȷ�����������
			{
				//��������˵���ջ
				Stack.push(left);
				Stack.push(border - 1);
			}
			if (border + 1 < right) //ȷ���ҷ�������
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