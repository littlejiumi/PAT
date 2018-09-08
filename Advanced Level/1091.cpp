#include<cstdio>
#include<queue>
using namespace std;
int N, M, L, T;
int s[1290][130][61];
bool inq[1290][130][61] = {false};
struct Node {
	int x, y, z;
}node;
int X[6] = { 0,0,0,0,1,-1 };
int Y[6] = { 0,0,1,-1,0,0 };
int Z[6] = { 1,-1,0,0,0,0 };
bool judge(int x, int y, int z) {
	if (s[x][y][z] == 0)return false;
	if (inq[x][y][z] == true)return false;
	if (x < 0 || x >= N || y < 0 || y >= M || z < 0 || z >= L)return false;
	return true;
}
int BFS(int x, int y, int z) {
	int num = 0;
	queue<Node> Q;
	node.x = x, node.y = y, node.z = z;
	Q.push(node);
	inq[x][y][z] = true;
	while (!Q.empty()) {
		Node top = Q.front();
		Q.pop();
		num++;
		for (int i = 0; i < 6;i++) {
			int newX = top.x + X[i];
			int newY = top.y + Y[i];
			int newZ = top.z + Z[i];
			if (judge(newX, newY, newZ)) {
				node.x = newX, node.y = newY, node.z = newZ;
				Q. push(node);
				inq[newX][newY][newZ] = true;
			}
		}
	}
	if (num >= T) {
		return num;
	}
	else return 0;
}
int main() {
	
	scanf("%d%d%d%d", &N, &M, &L, &T);
	int ans = 0;
	for (int z = 0; z < L; z++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				scanf("%d", &s[x][y][z]);
			}
		}
	}
	for (int z = 0; z < L; z++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (s[x][y][z] == 1 && inq[x][y][z] == false) {
					ans += BFS(x,y,z);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
