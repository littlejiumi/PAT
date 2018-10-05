#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxc = 210;
const int maxn = 10010;
int HashTable[maxc];
int A[maxn], dp[maxn];
int main() {
  fill(HashTable,HashTable+maxc,-1);
	int n, m,x,L, num = 0, ans = 1;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		HashTable[x] = i;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> x;
		if (HashTable[x] >= 0) {
			A[num++] = HashTable[x];
		}
	}
	for (int i = 0; i < num; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[j]<=A[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}
