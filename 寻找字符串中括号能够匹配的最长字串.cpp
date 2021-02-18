const int MAXN = 999;

void longestValidParentheses(char* s, int n) {
	int max = 0, i, j = 0, start = 0, end = 0;
	stack<int> stack;
	int maxpred[MAXN];
	for (int i = 0; i < n; i++) {
		maxpred[i] = 0;
	}
	for (i = 0; i < n; i++) {
		if (s[i] == '(') {
			stack.push(i);
		}
		else {
			if (!stack.empty()) {
				j = stack.top(); stack.pop();
				int tmax = i - j + 1;
				if (j > 0)
					tmax += maxpred[j - 1];
				maxpred[i] = tmax;
				if (tmax > max) {
					max = tmax;
					start = i - tmax + 1;
					end = i;
				}
			}
		}
	}
	for (i = start; i < end; i++) cout << s[i];
}
