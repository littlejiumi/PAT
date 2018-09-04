#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn = 100010;
bool hashTable[256];
char str[maxn];
int main() {
	fill(hashTable,hashTable+256, true);
	cin.getline(str,maxn);
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a';
		}
		hashTable[str[i]] = false;
	}
	cin.getline(str, maxn);
	len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			int low = str[i] - 'A' + 'a';
			if (hashTable[low] == true && hashTable['+'] == true) {
				cout << str[i];
			}
		}
		else if (hashTable[str[i]] == true) {
			cout << str[i];
		}
	}
	printf("\n");
	return 0;
}
