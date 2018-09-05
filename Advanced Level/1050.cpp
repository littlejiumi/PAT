#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int const maxn = 10005;
bool hashTable[128] = {false};
char a[maxn], b[maxn];
int main() {
	cin.getline(a, maxn);
	cin.getline(b,maxn);
	int lena = strlen(a);
	int lenb = strlen(b);
	for (int i = 0; i < lenb; i++) {
		hashTable[b[i]] = true;
	}
	for (int i = 0; i < lena; i++) {
		if (hashTable[a[i]] == false) {
			printf("%c", a[i]);
		}
	}
	return 0;
}
