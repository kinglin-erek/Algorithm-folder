#include<iostream>
using namespace std;

void insert_sort(int a[], int num) {
	int i, j, temp;
	for (i = 1; i < num; ++i)
		if (a[i] < a[i - 1]) {
			temp = a[i]; j = i - 1;
			do {
				a[j + 1] = a[j]; j--;
			} while (j >= 0 && temp < a[j]);
			a[j + 1] = temp;
		}
}

int main() {
	int list[100];
	srand(0);
	for (int i = 0; i < 100; i++) list[i] = rand() % 100;
	insert_sort(list, 100);
	for (int i = 0; i < 100; i++) cout << list[i] << " ";

	return 0;
}