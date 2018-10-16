#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int k, n, p;
int maxFacSum = -1;
vector<int> ans, temp, fac;
int power(int x) {
	int ans = 1;
	for (int i = 0; i < p; i++) {
		ans = ans * x;
	}
	return ans;
}
void init() {
	int i = 0, temp = 0;
	while (temp <= n) {
		fac.push_back(temp);
		temp = power(++i);
	}
}

void DFS(int index, int nowK, int sum, int facSum) {
	if (sum == n && nowK == k) {
		if (facSum > maxFacSum) {
			ans = temp;
			maxFacSum = facSum;
		}
		return;
	}
	if (sum > n || nowK > k)return;
	if (index - 1 >= 0) {
		temp.push_back(index);
		DFS(index, nowK + 1, sum + fac[index], facSum + index);
		temp.pop_back();
		DFS(index -1, nowK, sum, facSum);
	}
}
int main() {
	scanf("%d%d%d", &n, &k, &p);
	init();
	DFS(fac.size() - 1, 0, 0, 0);
	if (maxFacSum == -1)printf("Impossible\n");
	else {
		printf("%d = %d^%d", n, ans[0], p);
		for (int i = 1; i < ans.size(); i++) {
			printf(" + %d^%d", ans[i], p);
		}
	}
	return 0;
}
