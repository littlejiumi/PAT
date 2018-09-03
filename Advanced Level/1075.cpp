#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 10010;
struct Student {
	int id;
	int score[6];
	bool flag;
	int sum;
	int perfect;
}stu[maxn];

int n, k, m;
int full[6];
bool cmp(Student a, Student b) {
	if (a.sum != b.sum) {
		return a.sum > b.sum;
	}
	else if (a.perfect != b.perfect) {
		return a.perfect > b.perfect;
	}
	else {
		return a.id < b.id;
	}
}
void init() {
	for (int i = 1; i <= n; i++) {
		stu[i].id = i;
		stu[i].flag = false;
		stu[i].sum = 0;
		stu[i].perfect = 0;
		memset(stu[i].score, -1, sizeof(stu[i].score));
	}
}
int main() {
	scanf("%d%d%d", &n, &k, &m);
	init();
	for (int i = 1; i <= k; i++) {
		scanf("%d", &full[i]);
	}
	int u_id, p_id, partial;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u_id, &p_id, &partial);
		if (partial != -1) {
			stu[u_id].flag = true;
		}
		if (partial == -1 && stu[u_id].score[p_id] == -1) {
			stu[u_id].score[p_id] = 0;
		}
		if (partial == full[p_id] && stu[u_id].score[p_id] != full[p_id]) {
			stu[u_id].perfect++;
		}
		if (partial > stu[u_id].score[p_id]) {
			stu[u_id].score[p_id] = partial;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (stu[i].score[j] != -1) {
				stu[i].sum += stu[i].score[j];
			}
		}
	}
	sort(stu + 1, stu + n + 1, cmp);
	int r = 1;
	for (int i = 1; i <= n&&stu[i].flag == true; i++) {
		if (i > 1 && stu[i].sum != stu[i - 1].sum) {
			r = i;
		}
		printf("%d %05d %d", r, stu[i].id, stu[i].sum);
		for (int j = 1; j <= k; j++) {
			if (stu[i].score[j] == -1) {
				printf(" -");
			}
			else {
				printf(" %d", stu[i].score[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
