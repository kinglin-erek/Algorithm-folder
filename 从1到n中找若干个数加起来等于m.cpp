#include<iostream>
#include<stack>
#include<list>
using namespace std;

//������������n��m��������1��2��3��������n���ҵ����ɸ������ɵļ���S��ʹ��͵���m,Ҫ���г����п��ܵ�S���ϵ�Ԫ�ء�
list<int> list1;
void find_factor(int sum, int n) {
	if (n <= 0 || sum <= 0) return;
	if (sum == n) {
		list1.reverse();
		for (list<int>::iterator iter = list1.begin(); iter != list1.end(); iter++)
			cout << *iter << " + ";
		cout << n << endl;
		list1.reverse();
	}
	list1.push_front(n);
	find_factor(sum - n, n - 1);
	list1.pop_front();
	find_factor(sum, n - 1);
}

int main() {
	int sum, n;
	cout << "����������Ҫ���ڶ��ٵ���ֵsum:" << endl;
	cin >> sum;
	cout << "��������Ҫ��1.....n������ȡֵ��n:" << endl;
	cin >> n;
	cout << "���п��ܵ����У�����:" << endl;
	find_factor(sum, n);
	return 0;
}