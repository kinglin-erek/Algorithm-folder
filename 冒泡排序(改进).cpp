#include<iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void bubble_sort(int a[], int num) {
	int flag;
	for (int i = 0; i < num; ++i) {
		flag = 0;
		for (int j = num - 1; j > 0; --j) {
			if (a[j - 1] > a[j]) {
				swap(a[j - 1], a[j]);
				flag = 1;
			}
		}
		if (!flag) return;
	}
}

int main() {
	int list[100];
	srand(0);
	for (int i = 0; i < 100; i++) list[i] = rand() % 100;
	bubble_sort(list, 100);
	for (int i = 0; i < 100; i++) cout << list[i] << " ";

	return 0;
}