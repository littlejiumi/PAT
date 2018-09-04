#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int manx = 100010;


int main() {
	int n, k;
	int hashTable[105];
	fill(hashTable, hashTable + 105, 0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int score;
		scanf("%d", &score);
		hashTable[score]++;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int what;
		scanf("%d", &what);
		printf("%d", hashTable[what]);
		if (i < k - 1)printf(" ");
	}
	return 0;
}
