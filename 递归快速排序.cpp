#include<iostream>
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
void Quick_Sort(int list[], int left, int right) {  //µÝ¹é¿ìÅÅ
	if (left > right)
		return;
	int i = partition(list, left, right);
	Quick_Sort(list, left, i - 1);
	Quick_Sort(list, i + 1, right);
}

int main() {
	int list[100];
	srand(0);
	for (int i = 0; i < 100; i++) list[i] = rand() % 100;
	Quick_Sort(list, 0, 99);
	for (int i = 0; i < 100; i++) cout << list[i] << " ";

	return 0;
}