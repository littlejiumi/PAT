//二分法
#include<cstdio>
int a[100010];
int upper_bound(int l, int r, int m) {
	int left=l,right=r;
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (a[mid] > m) {     //得到的是大于m的j
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int near = 1000000000;
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(i, 1 + n, a[i-1] + m);
		if (a[j - 1] - a[i - 1] == m) {     //存在j-1对应值为a[i-1]+m
			near = m;
			break;
		}
		else if (j <= n && a[j] - a[i - 1] < near) {
			near = a[j] - a[i - 1];        //不存在求多的最少的值
		}
	}
	for (int i = 1; i <= n; i++) {
		int j = upper_bound(i, n + 1, a[i - 1] + near);
		if (a[j - 1] - a[i - 1] == near) {
			printf("%d-%d\n", i, j - 1);
		}
	}
	return 0;
}
