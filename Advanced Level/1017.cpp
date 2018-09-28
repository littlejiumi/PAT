#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int early = 28800;
const int late = 61200;
int endtime[105];
struct Per {
	int come, pro;
}per[10010];
bool cmp(Per a, Per b) {
	return a.come < b.come;
}
int ans[10010];
int main() {
	int n, k;
	cin >> n >> k;
	int h, m, s;
	fill(ans, ans + 10010, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d:%d:%d", &h, &m, &s);
		int c = 3600 * h + 60 * m + s;
		per[i].come = c;
		scanf("%d", &per[i].pro);
		per[i].pro = per[i].pro * 60;
	}
	sort(per, per + n, cmp);
	for (int i = 0; i < k; i++) {
		endtime[i] = early;
	}
	for (int index = 0; index < n; index++) {
		if (per[index].come > late) {
			ans[index] = -1;
			continue;
		}
		int id = 0, mintime = endtime[0];
		for (int j = 0; j < k; j++) {
			if (endtime[j] < mintime) {
				id = j;
				mintime = endtime[j];
			}
		}
		if (endtime[id] <= per[index].come) {
			endtime[id] = per[index].come + per[index].pro;
		}
		else {
			ans[index] = endtime[id]- per[index].come;
			endtime[id] += per[index].pro;
		}

	}
	int sum = 0,cnt=0;
	for (int i = 0; i < n; i++) {
		if (ans[i] != -1) {
			cnt++;
			sum += ans[i];
		}
		cout << ans[i] << endl;
		
	}
	printf("%.1f", sum / 60.0 / cnt);
	cin >> n;
	return 0;
}
