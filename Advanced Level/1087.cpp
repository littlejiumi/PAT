#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
using namespace std;
const int maxn = 205;
const int INF = 1000000000;
int n, k;
int G[maxn][maxn];
int d[maxn], w[maxn],weight[maxn], num[maxn],pre[maxn],pren[maxn];
bool vis[maxn] = { false };
map<string, int> strToInt;
map<int, string> intToStr;

void Dijkstra(int s) {
	fill(d, d + maxn, INF);
	fill(w, w + maxn, 0);
	fill(pren, pren + maxn, 0);
	fill(num, num + maxn, 0);
	for (int i = 0; i < n; i++)pre[i] = i;
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
	for (int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j <= n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int v = 0; v < n; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[u] + G[u][v] < d[v]) {
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
					pren[v] = pren[u] + 1;
					pre[v] = u;
				}
				else if (d[u] + G[u][v] == d[v]) {
				  	num[v] += num[u];
					if (w[v] < w[u] + weight[v]) {
						w[v] = w[u] + weight[v];
					
						pren[v] = pren[u] + 1;
						pre[v] = u;
					}
					else if (w[v] == w[u] + weight[v]) {
						double uavg = 1.0 * (w[u] + weight[v]) / (pren[u] + 1);
						double vavg = 1.0 * w[v] / pren[v];
						if (uavg > vavg) {
							
							pren[v] = pren[u] + 1;
							pre[v] = u;
						}
					}
				  }
			}
		}
	}
}

void DFS(int v) {
	if (v == 0) {
		cout << intToStr[v];
		return;
	}
	DFS(pre[v]);
	cout << "->" << intToStr[v];
}
int main() {
	string start, city1, city2;
	cin >> n >> k >> start;
	strToInt[start] = 0;
	intToStr[0] = start;
	for (int i = 1; i <= n - 1; i++) {
		cin >> city1 >> weight[i];
		strToInt[city1] = i;
		intToStr[i] = city1;
	}
	fill(G[0], G[0] + maxn*maxn, INF);
	for (int i = 0; i < k; i++) {
		cin >> city1 >> city2;
		int c1 = strToInt[city1];
		int c2 = strToInt[city2];
		cin >> G[c1][c2];
		G[c2][c1] = G[c1][c2];
	}
	Dijkstra(0);
	int ed = strToInt["ROM"];
	printf("%d %d %d %d\n", num[ed], d[ed], w[ed], w[ed] / pren[ed]);
	DFS(ed);
	return 0;
}
