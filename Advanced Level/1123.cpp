#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 25;
int n;
struct node {
	int data,h;
	node* lchild;
	node* rchild;
}*root;
node* newNode(int x) {
	node* Node = new node;
	Node->data = x;
	Node->h = 1;
	Node->lchild = Node->rchild = NULL;
	return Node;
}
int getHeight(node* root) {
	if (root == NULL)return 0;
	else {
		return root->h;
	}
}
void updateHeight(node* root) {
	root->h = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
int getBF(node* root) {
	return getHeight(root->lchild)- getHeight(root->rchild);
}
void L(node* &root) {
	node* temp = root->rchild;
	root->rchild = temp->lchild;
	temp->lchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void R(node* &root) {
	node* temp = root->lchild;
	root->lchild = temp->rchild;
	temp->rchild = root;
	updateHeight(root);
	updateHeight(temp);
	root = temp;
}
void insert(node* &root, int x) {
	if (root == NULL) {       //这样第一个数就是根结点了
		root = newNode(x);
		return;
	}
	if (x < root->data) {
		insert(root->lchild, x);
		updateHeight(root);
		if (getBF(root) == 2) {
			if (getBF(root->lchild) == 1) {
				R(root);
			}
			else if (getBF(root->lchild) == -1) {
				L(root->lchild);
				R(root);
			}
		}
	}
	else {
			insert(root->rchild, x);
			updateHeight(root);
			if (getBF(root) == -2) {
				if (getBF(root->rchild) == -1) {
					L(root);
				}
				else if (getBF(root->rchild) == 1) {
					R(root->rchild);
					L(root);

				}
			}
		}		
	}
bool flag = true, ans = true;
void BFS(node* root) {
	int num = 0;
	queue<node*> q;
	q.push(root);
	
	while (!q.empty()) {
		node* now = q.front();
		q.pop();
		printf("%d", now->data);
		num++;
		if (num < n)printf(" ");
		if (now->lchild != NULL) {
			q.push(now->lchild);
			if (flag == false) {
				ans = false;
			}
		}
		else {
			flag = false;
		}
		if (now->rchild != NULL) {
			q.push(now->rchild);
			if (flag == false) {
				ans = false;
			}
		}
		else {
			flag = false;
		}
	}
}
int main() {
	int x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		insert(root, x);
	}
	BFS(root);
	if (ans == false) {
		printf("\nNO");
	}
	else {
		printf("\nYES");
	}
	return 0;
}
