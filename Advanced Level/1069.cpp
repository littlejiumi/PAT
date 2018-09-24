#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
void intToArr(int n, int num[]) {
	for (int i = 0; i < 4; i++) {
		num[i] = n % 10;
		n /= 10;
	}
}
int arrToInt(int num[]) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum = sum * 10 + num[i];
	}
	return sum;
}
int main() {
	int n, MIN, MAX;
	scanf("%d", &n);
	int num[5];
	while (1) {
		intToArr(n, num);
		sort(num, num + 4, cmp);
		MAX = arrToInt(num);
		sort(num, num + 4);
		MIN = arrToInt(num);
		n = MAX - MIN;
		printf("%04d - %04d = %04d\n", MAX, MIN, n);
		if (n == 0 || n == 6174) break;
	}
	return 0;
}
