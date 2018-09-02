//排序
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct Stu {
	char id[10];
	int de, cai, sum;
	int flag;
}stu[100010];

bool cmp(Stu a, Stu b) {
	if (a.flag != b.flag) {
		return a.flag < b.flag;
	}
	else if (a.sum != b.sum) {
		return a.sum > b.sum;
	}
	else if (a.de != b.de) {
		return a.de > b.de;
	}
	else {
		return strcmp(a.id, b.id)<0;
	}
}

int main() {
	int n, m, L, H;
	scanf("%d %d %d", &n, &L, &H);
	m = n;
	for (int i = 0; i < n; i++) {
		scanf("%s%d%d", stu[i].id, &stu[i].de, &stu[i].cai);
		stu[i].sum = stu[i].de + stu[i].cai;
		if (stu[i].de < L || stu[i].cai < L) {
			m--;
			stu[i].flag = 5;
		}
		else if (stu[i].de >= H && stu[i].cai >= H) {
			stu[i].flag = 1;
		}
		else if (stu[i].de >= H) {
			stu[i].flag = 2;
		}
		else if (stu[i].de >= stu[i].cai) {
			stu[i].flag = 3;
		}
		else {
			stu[i].flag = 4;
		}
	}

	sort(stu, stu + n, cmp);

	printf("%d\n", m);
	for (int i = 0; i < m; i++) {
		printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
	}
	return 0;
}
