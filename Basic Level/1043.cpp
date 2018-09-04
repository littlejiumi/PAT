#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

char dict[6] = { 'P','A','T','e','s','t' };
int hashTable[6] = { 0 };
int main() {
	char str[10010];
	cin.getline(str, 10010);
	int len = strlen(str),sum=0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 6; j++) {
			if (str[i] == dict[j]) {
				hashTable[j]++;
				sum++;
			}
		}
	}
	while (sum) {
		for (int i = 0; i < 6;i++) {
			if (hashTable[i] != 0) {
				printf("%c", dict[i]);
				hashTable[i]--;
				sum--;
			}
		}
	}
	return 0;
}
