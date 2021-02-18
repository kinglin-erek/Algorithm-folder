
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int double_bubble(int list[],int start, int length) { //Ô­°æ
	int flag,count=0;

	for (int i = start; i < length/2 - 1; i++) {
		flag = 0;
		for (int j = start; j < length - 1 - i; j++) {
			if (list[j] > list[j + 1]) {
				swap(list[j], list[j + 1]);
				flag = 1;
			}
			count++;
		}
		if(flag == 0) break;
		flag = 0;
		for (int k = length - i - 2; k > i; k--) {
			if (list[k-1] > list[k]) {
				swap(list[k-1], list[k]);
				flag = 1;
			}
			count++;
		}
		if(flag == 0) break;
	}
	return count;
}

int double_bubble(int list[], int start, int length) {  //ÓÅ»¯°æ
	int flag, count = 0;

	int last_left_index = 0;
	int left_border = 0;
	int last_right_index = 0;
	int right_border = length - 1;

	for (int i = start; i < length / 2 - 1; i++) {
		flag = 0;
		for (int j = left_border; j < right_border; j++) {
			if (list[j] > list[j + 1]) {
				swap(list[j], list[j + 1]);
				flag = 1;
				last_right_index = j;
			}
			count++;
		}
		right_border = last_right_index;
		if (flag == 0) break;
		flag = 0;
		for (int k = right_border; k > left_border; k--) {
			if (list[k - 1] > list[k]) {
				swap(list[k - 1], list[k]);
				flag = 1;
				last_left_index = k;
			}
			count++;
		}
		left_border = last_left_index;
		if (flag == 0) break;
	}
	return count;
}
