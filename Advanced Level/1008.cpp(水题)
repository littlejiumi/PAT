#include<cstdio>
int main() {
	int n,ans=0;
	int a[105];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			ans += (a[i] - 0) * 6;
		}
		if (i > 0 && i < n ) {
			if (a[i] > a[i - 1]) {
				ans += (a[i] - a[i - 1]) * 6;
			}
			else {
				ans += (a[i-1] - a[i]) * 4;
			}
		}
	}
	printf("%d", ans + n * 5);
	return 0;
}
