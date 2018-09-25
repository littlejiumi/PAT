#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 105;
int origin[N], temp[N], aim[N];
int n;
bool isSame(int A[], int B[]) {
	for (int i = 0; i < n; i++) {
		if (A[i] != B[i]) {
			return false;
		}
	}
	return true;
}
bool cout(int A[]) {
	for (int i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i < n - 1)printf(" ");
	}
	printf("\n");
}

bool insertSort() {
	bool flag = false;
	for (int i = 1; i < n; i++) {
		if (i != 1 && isSame(temp, aim)) {
			flag = true;
		}
		int tempnum = temp[i], j = i;
		while (j > 0 && temp[j - 1] > tempnum) {
			temp[j] = temp[j - 1];
			j--;
		}
		temp[j] = tempnum;
		if (flag == true) {
			return true;
		}
	}
	return false;
}

void mergeSort() {
	bool flag = false;
	for (int step = 2; step / 2 <= n; step *= 2) {
		if (step != 2 && isSame(temp, aim)) {
			flag = true;
		}
		for (int i = 0; i < n; i += step) {
			sort(temp + i, temp + min(i + step, n));
		}
		if (flag == true) {
			cout(temp);
			return;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &origin[i]);
		temp[i] = origin[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &aim[i]);
	}
	if (insertSort()) {
		printf("Insertion Sort\n");
		cout(temp);
	}
	else {
		printf("Merge Sort\n");
		for (int i = 0; i < n; i++) {
			temp[i] = origin[i];
		}
		mergeSort();
	}
	return 0;
}
