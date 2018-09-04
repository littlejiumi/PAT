#include<cstdio>
#include<cstring>
int main() {
	int n;
	int hashTable[1005];
	memset(hashTable, 0, sizeof(hashTable));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int team, player, score;
		scanf("%d-%d %d", &team, &player, &score);
		hashTable[team] += score;
	}
	int k = 0;
	for (int i = 0; i < 1005; i++) {
		if (hashTable[i] > hashTable[k]) {
			k = i;
		}
	}
	printf("%d %d\n", k, hashTable[k]);
	return 0;
}
