#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n;
const int maxn = 35;
int post[maxn], in[maxn];
struct node {
	int data;
	node* lchild;
	node* rchild;
};
node* create(int postl, int postr,int inl,int inr) { //根据后序和中序建树
	if (postl > postr) {
		return NULL;       //不是return
	}
	int k;
	for (int i = inl; i<=inr; i++) {
		if (in[i] == post[postr]) {
			k = i;
			break;
		}
	}
	int leftnum = k - inl;
	node* root = new node;       //根节点data是后续最后一个
	root->data = post[postr];
	root->lchild = create(postl, postl + leftnum - 1, inl, k - 1);
	root->rchild = create(postl + leftnum, postr-1, k + 1, inr);
	return root;
}
int num = 0;
void BFS(node* root) {       //建树后层序遍历，注意要计数加空格
	queue<node*> q;             //存地址
	q.push(root);
	while (!q.empty()) {
		node* front = q.front();
		printf("%d", front->data);
		num++;
		if (num < n) {
			printf(" ");
		}
		q.pop();
		if (front->lchild != NULL) {
			q.push(front->lchild);
		}
		if (front->rchild != NULL) {
			q.push(front->rchild);
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	node* root = create(0, n - 1, 0, n - 1); //起始和终了下标， 返回所得树的根结点
	BFS(root);
	return 0;
}
