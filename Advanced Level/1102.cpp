#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 110;
struct node {
	int lchild, rchild;
}Node[maxn];

bool notRoot[maxn] = { false };

int n, num = 0;

void print(int id) {
	printf("%d", id);
	num++;
	if (num < n)printf(" ");
	else printf("\n");
}

void inorder(int root) {
	if (root == -1) {
		return;
	}
	inorder(Node[root].lchild);
	print(root);
	inorder(Node[root].rchild);
}

void BFS(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int front = q.front();
		q.pop();
		print(front);
		if (Node[front].lchild != -1) q.push(Node[front].lchild);
		if (Node[front].rchild != -1) q.push(Node[front].rchild);
	}
}

void postorder(int root) {
	if (root == -1) return;
	postorder(Node[root].lchild);
	postorder(Node[root].rchild);
	swap(Node[root].lchild, Node[root].rchild);
}

int strToNum(char c) {
	if (c == '-')return - 1;
	else {
		notRoot[c - '0'] = true;
		return c - '0';
	}
}

int findRoot() {
	for (int i = 0; i < n; i++) {
		if (notRoot[i] == false) {
			return i;
		}
	}
}

int main() {
	char lchild, rchild;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		scanf("%c %c", &lchild, &rchild);
		Node[i].lchild = strToNum(lchild);
		Node[i].rchild = strToNum(rchild);
	}
	int root = findRoot();
	postorder(root);
	BFS(root);
	num = 0;
	inorder(root);
	return 0;
}
