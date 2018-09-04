#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 1010;
char str[maxn];
int hashTable[30] = { 0 };
int main() {
	cin.getline(str, maxn);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'a'&&str[i] <= 'z') {
			hashTable[str[i] - 'a']++;
		}
		else if (str[i] >= 'A'&&str[i] <= 'Z') {
			hashTable[str[i] - 'A']++;
		}
	}
	int k = 0;
	for (int i = 0; i < 26; i++) {
		if (hashTable[i] > hashTable[k]) {
			k = i;
		}
	}
	printf("%c %d\n", 'a' + k, hashTable[k]);
	return 0;
}
