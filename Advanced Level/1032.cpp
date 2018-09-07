#include<cstdio>
const int maxn = 100010;
struct Node {
	char data;
	int next;
	bool flag;
}node[maxn];
int main() {
	int begin1, begin2, n;
	for (int i = 0; i < maxn; i++) {
		node[i].flag = false;
	}
	scanf("%d%d%d", &begin1, &begin2, &n);
	int address, next;
	char data;
	for (int i = 0; i < n; i++) {
		scanf("%d %c %d", &address, &data, &next);
		node[address].data = data;
		node[address].next = next;
	}
	int p;
	for (p = begin1; p != -1; p= node[p].next) {
		node[p].flag = true;
	}
	for (p = begin2; p != -1; p = node[p].next) {
		if (node[p].flag == true) break;
	}
	if (p != -1) {
		printf("%05d\n", p);
	}
	else {
		printf("-1\n");
	}
	return 0;
}
