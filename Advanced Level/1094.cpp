#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 110;
int n, m;

vector<int> node[maxn];
int hashTable[maxn] = { 0 };
void DFS(int index, int layer) {
	hashTable[layer]++;
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
	int maxLayer = -1,maxValue=0;
	for (int i = 0; i < maxn; i++) {
		if (hashTable[i] > maxValue) {
			maxValue = hashTable[i];
			maxLayer = i;
		}
	}
	printf("%d %d\n", maxValue, maxLayer);
	return 0;
}
