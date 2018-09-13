#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int maxn = 100010;
vector<int> child[maxn];
double p, r;
int n, num = 0, maxd = 0;

void DFS(int index, int de) {
	if (child[index].size() == 0) {
		if (de > maxd) {
			num = 1;
			maxd = de;
		}
		else if (de == maxd) {
			num++;
		}
		return;
	}
	for (int i = 0; i < child[index].size(); i++) {
		DFS(child[index][i], de + 1);
	}

}
int main() {
	int fa, root;
	scanf("%d%lf%lf", &n, &p, &r);
	r /= 100;
	for (int i = 0; i < n; i++) {
		scanf("%d", &fa);
		if (fa != -1) {
			child[fa].push_back(i);

		}
		else {
			root = i;
		}
	}
	DFS(root, 0);
	printf("%.2f %d\n", p*pow(1 + r, maxd), num);
	return 0;
}
