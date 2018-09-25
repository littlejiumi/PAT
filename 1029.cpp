#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n1, n2;
	int a[2000010];
	scanf("%d", &n1);
	for (int i = 0; i < n1; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &n2);
	for (int i = n1; i < n1+n2; i++) {
		scanf("%d", &a[i]);
	}
	sort(a,a+n1+n2);
	printf("%d", a[(n1 + n2 - 1) / 2]);
	return 0;
}
