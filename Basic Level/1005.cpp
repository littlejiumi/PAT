#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int const maxn = 10005;
bool hashTable[10000] = {false};
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int n, m, a[100];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		m = a[i];
		while (m != 1) {
			if (m % 2 == 0) m= m / 2;
			else m=(3 * m + 1) / 2;
			hashTable[m] = true;
		}
	}
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (hashTable[a[i]] == false) {
			count++;
		}
	}
	sort(a, a + n,cmp);
	for (int i = 0; i < n; i++) {
		if (hashTable[a[i]] == false) {
			printf("%d", a[i]);
			count--;
			if (count > 0) printf(" ");
		}
	}
	return 0;
}
