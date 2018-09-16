#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct node {
	int id;
	int layer;
};
vector<node> user_list[1010];
bool vis[1010] = {false};
int BFS(int qu, int L) {
	int numForward = 0;
	node start;
	start.id = qu;
	start.layer = 0;
	vis[start.id] = true;
	queue<node> q;
	q.push(start);
	while (!q.empty()) {
		node now = q.front();
		q.pop();
		int u = now.id;
		for (int i = 0; i < user_list[u].size(); i++) {
			node next = user_list[u][i];
			next.layer = now.layer + 1;
			if (vis[next.id] == false && next.layer <= L) {
				q.push(next);
				vis[next.id] = true;
				numForward++;
			}
		}
	}
	return numForward;
}

int main() {
	int N,L;
	node start;
	scanf("%d%d", &N, &L);
	for (int i = 1; i <= N; i++) {
		int num,idFollow;
		scanf("%d", &num);
		start.id = i;
		for (int j = 0; j < num; j++) {
			scanf("%d", &idFollow);
			user_list[idFollow].push_back(start);
		}
	}
	int k, qu;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &qu);
		fill(vis, vis + 1010, false);
		printf("%d\n", BFS(qu, L));
	}
	return 0;
}
