#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int pro[1010];
struct win {
	int popTime, endTime;
	queue<int> q;
}Win[1010];
int ans[1010];
int main() {
	int n, m, k, q;
	int index = 0;
	cin >> n >> m >> k >> q;
	for (int i = 0; i < k; i++) {
		cin >> pro[i];
	}
	for (int i = 0; i < n; i++) {
		Win[i].popTime = Win[i].endTime = 8 * 60 + 0;
	}
	for (int i = 0; i < min(n*m, k); i++) {
		Win[index%n].q.push(index);
		Win[index%n].endTime += pro[index];
		ans[index] = Win[index%n].endTime;
		if (i < n) {
			Win[index%n].popTime = pro[index];
		}
		index++;
	}
	while (index < k) {
		int minPop = 1000000000;
		int m=-1;
		for (int i = 0; i < n; i++) {
			if (Win[i].popTime < minPop) {
				minPop = Win[i].popTime;
				m = i;
			}
		}
		Win[m].q.pop();
		Win[m].q.push(index);
		Win[m].popTime += pro[Win[m].q.front()];
		Win[m].endTime += pro[index];
		ans[index] = Win[m].endTime;
		index++;
	}
	for (int i = 0; i < q; i++) {
		int per;
		cin >> per;
		if (ans[per - 1] - pro[per - 1] >= 17 * 60 + 0) {
			cout << "Sorry" << endl;
		}
		else {
			printf("%02d:%02d\n", ans[per - 1] / 60, ans[per - 1] % 60);
		}
	}
	return 0;
}
