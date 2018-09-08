#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100005;
const int TABLE = 1000010;
struct Node {
	int address, data, next;
	int order;
}node[maxn];
bool isExist[TABLE] = { false };
bool cmp(Node a, Node b) {
	return a.order < b.order;
}
int main() {
	fill(isExist, isExist + TABLE, false);
	for (int i = 0; i < maxn; i++) {
		node[i].order = 2 * maxn;
	}
	int n, begin, address;   
	scanf("%d%d", &begin, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &address);
		scanf("%d%d", &node[address].data, &node[address].next);
		node[address].address = address;
	}
	int p = begin,va=0,re=0;
	while (p != -1) {
		if (!isExist[abs(node[p].data)]) {
			isExist[abs(node[p].data)] = true;
			node[p].order=va++;
		}
		else {
			node[p].order = maxn+re++;
		}
		p = node[p].next;
	}
	sort(node, node + maxn, cmp);
	int count = va + re;
	for (int i = 0; i < count; i++) {
		if (i != va-1&&i != count-1) {
			printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
		}
		else {
			printf("%05d %d -1\n", node[i].address, node[i].data);
		}
	}
	return 0;
}
