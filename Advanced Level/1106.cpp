#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int maxn = 100010;
int n;
double p, r;
vector<int>node[maxn];
int minDepth = 100000;
int num = 0;
void DFS(int index, int depth) {
	if (node[index].size() == 0) {
		if (depth < minDepth) {
			minDepth = depth;
			num = 1;
		}else if(depth == minDepth){
		  num++;
		}
		return;
	}
		for (int i = 0; i < node[index].size(); i++) {
			DFS(node[index][i], depth + 1);
		}
	
}
int main() {
	scanf("%d%lf%lf", &n, &p, &r);
	int k, child;
	r /= 100;
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k != 0) {
			for (int j = 0; j < k; j++) {
				scanf("%d", &child);
				node[i].push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.4f %d\n", p*pow(1 + r, minDepth),num);
	return 0;
}
