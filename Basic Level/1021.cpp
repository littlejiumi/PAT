#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main() {
	char str[1000];
	cin>>str;
	int len = strlen(str);
	int count[10] = {0};
	for(int i = 0; i < len; i++) {
		count[str[i] - '0']++;			//将str[i]对应的数字的count值加1 
	}
	for(int i = 0; i< 10; i++) {
		if(count[i] != 0){
			printf("%d:%d\n", i, count[i]);	
		}

	}
	return 0;
}
