#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 50;
struct node {
	int data;
	node* lchild;
	node* rchild;
};
int pre[maxn], post[maxn];
int n;        //结点个数
bool isUnique = true;
node* create(int preL, int preR, int postL, int postR) {
	if (preL > preR) {
		return NULL;
	}
	node* root = new node;
	root->data = pre[preL];
	int k, numLeft = 0;
	for (k = postL; k < postR; k++) {
		numLeft++;
		if (post[k] == pre[preL + 1]) {
			break;
		}
	}
	if (k == postR - 1)isUnique = false;
	root->lchild = create(preL + 1, preL + numLeft, postL, k);
	root->rchild = create(preL + numLeft + 1, preR, k + 1, postR - 1);
	return root;
}
vector<int> in;//可以.size()知大小
void inOrder(node* root) {
	if (root == NULL)return;
	inOrder(root->lchild);
	in.push_back(root->data);
	inOrder(root->rchild);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	node* root = create(0, n - 1, 0, n - 1);
	inOrder(root);
	printf(isUnique ? "Yes\n" : "No\n");
	for (int i = 0; i < in.size(); i++) {
		printf("%d", in[i]);
		printf((i + 1 < in.size()) ? " " : "\n");//输出空格或回车的方法
	}
	return 0;
}
