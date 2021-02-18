#include<iostream>
#include<stack>
#include<list>
using namespace std;
const int MaxData = 99999;

typedef struct HeapStruct* MaxHeap;
struct HeapStruct {
	int* elements;
	int Size;
	int Capacity;
	HeapStruct() :elements(NULL), Size(0), Capacity(0) {}
};

MaxHeap Create(int MaxSize) {
	MaxHeap H = new HeapStruct();
	H->elements = new int[MaxSize + 1];
	H->Size = 0;
	H->Capacity = MaxSize;
	H->elements[0] = MaxData;
	return H;
}

bool IsFull(MaxHeap H) {
	if (H->Size - H->Capacity)
		return true;
	else
		return false;
}

bool IsEmpty(MaxHeap H) {
	if (!H->Size)
		return true;
	else
		return false;
}

void Insert(MaxHeap H, int item) {
	int i;
	if (IsFull(H)) {
		cout << "最大堆已满";
		return;
	}
	i = ++H->Size;
	for (; H->elements[i / 2]; i /= 2) {
		H->elements[i] = H->elements[i / 2];
		H->elements[i] = item;
	}
}

int DeleteMax(MaxHeap H) {
	int parent, child;
	int MaxItem, temp;
	if (IsEmpty(H)) {
		cout << "最大堆已空！" << endl;
		return;
	}
	MaxItem = H->elements[1];
	temp = H->elements[H->Size--];
	for (parent = 1; parent * 2 <= H->Size; parent = child) {
		child = parent * 2;
		if ((child != H->Size) && (H->elements[child] < H->elements[child + 1]))
			child++;
		if (temp >= H->elements[child]) break;
		else
			H->elements[parent] = H->elements[child];
	}
	H->elements[parent] = temp;
	return MaxItem;
}

int main() {

	return 0;
}