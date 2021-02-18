#include<iostream>
#include<stack>
#include<list>
using namespace std;

//输入两个整数n和m，从数列1，2，3，。。。n中找到若干个数构成的集合S，使其和等于m,要求列出所有可能的S集合的元素。
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
	cout << "请你输入你要等于多少的数值sum:" << endl;
	cin >> sum;
	cout << "请输入你要从1.....n数列中取值的n:" << endl;
	cin >> n;
	cout << "所有可能的序列，如下:" << endl;
	find_factor(sum, n);
	return 0;
}