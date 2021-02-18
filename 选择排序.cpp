#include<iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void selection_sort(int a[], int num) {
	int i, j, min;
	for (i = 0; i < num; i++) {
		for (min = i, j = i + 1; j < num; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[i], a[min]);
	}
}

int main() {
	int list[100];
	srand(0);
	for (int i = 0; i < 100; i++) list[i] = rand() % 100;
	selection_sort(list, 100);
	for (int i = 0; i < 100; i++) cout << list[i] << " ";

	return 0;
}