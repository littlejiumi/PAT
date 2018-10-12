#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 110;
struct Node {
	int weight;
	vector<int> child;
}node[maxn];
int n, m, s;
bool cmp(int a, int b) {
	return node[a].weight > node[b].weight;
}
int path[maxn];    //记录每一次路径，用数组可以一遍遍覆盖，最后输出num长度的结果
void DFS(int index, int num,int w) {              //树的遍历常用参数哦~index, num, w
	if (w < s) {
		for (int i = 0; i < node[index].child.size(); i++) {
			int child = node[index].child[i];
			path[num] = child;
			DFS(node[index].child[i],num+1, w + node[node[index].child[i]].weight);
		}
	}
	else if (w > s) {
		return;
	}
	else if (w == s) {
		if (node[index].child.size() != 0) {
			return;
		}
		else {		
			for (int j = 0; j < num; j++) {
				printf("%d", node[path[j]].weight);
				if (j < num - 1) {
					printf(" ");
				}
				else {
					printf("\n");
				}
			}
			return;
		}
	}
}
int main() {
	int w, id, k,cid;
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &w);
		node[i].weight = w;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &id, &k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &cid);
			node[id].child.push_back(cid);
		}
		sort(node[id].child.begin(), node[id].child.end(), cmp);
	}
	path[0] = 0;
	DFS(0,1,node[0].weight);
	return 0;
}
