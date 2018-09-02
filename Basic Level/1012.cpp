//排序，二维数组
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

struct Stu {
	int id;
	int grade[4];
}stu[2010];

char course[4] = {
	'A', 'C','M','E'
};

int Rank[10000000][4] = { 0 };
int now;

bool cmp(Stu a, Stu b) {
	return a.grade[now] > b.grade[now];
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3];
	}
	for (now = 0; now < 4; now++) {
		sort(stu, stu + n, cmp);//分别每个科目的排序，分数从高到低
		Rank[stu[0].id][now] = 1;//stu[0].id排在该科目的第一位，rank值该科目为1
		for (int i = 1; i < n; i++) {
			if (stu[i].grade[now] == stu[i - 1].grade[now]) {
				Rank[stu[i].id][now] = Rank[stu[i - 1].id][now];//并列情况排名相同
			}
			else {
				Rank[stu[i].id][now] = i + 1;//排名等于人数
			}
		}
	}
	int q;
	for (int i = 0; i < m; i++) {
		scanf("%d", &q);
		if (Rank[q][0] == 0) {//如果没这个人
			printf("N/A\n");
		}
		else {
			int k = 0;
			for (int j = 0; j < 4; j++) {
				if (Rank[q][j] < Rank[q][k]) {//取这个人排名最靠前的一科
					k = j;
				}
			}
			printf("%d %c\n", Rank[q][k], course[k]);
		}
	}
	return 0;
}
