#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 110;
int n, m;
int maxl = 1;
vector<int> node[maxn];
int hashTable[maxn] = { 0 };
void DFS(int index, int layer) {
	maxl = max(layer, maxl);
	if (node[index].size() == 0) {
		hashTable[layer]++;
		return;
	}
	for (int i = 0; i < node[index].size(); i++) {
		DFS(node[index][i], layer + 1);
	}
}
int main() {
	int id, child, k;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &id,&k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &child);
			node[id].push_back(child);
		}
	}
	DFS(1, 1);
	for (int i = 1; i <= maxl; i++) {
		printf("%d", hashTable[i]);
		if (i < maxl)printf(" ");
	}

	return 0;
}
