#include<cstdio>
#include<cstring>
struct Person {
	char name[20];
	char password[20];
	bool isChanged;
}person[1010];

void ifChange(Person& p, int& count) {
	int len = strlen(p.password);
	for (int i = 0; i < len; i++) {
		if (p.password[i] == '1') {
			p.password[i] = '@';
			p.isChanged = true;
		}
		else if (p.password[i] == '0') {
			p.password[i] = '%';
			p.isChanged = true;
		}
		else if (p.password[i] == 'l') {
			p.password[i] = 'L';
			p.isChanged = true;
		}
		else if (p.password[i] == 'O') {
			p.password[i] = 'o';
			p.isChanged = true;
		}
	}
	if (p.isChanged ==true) {
		count++;
	}
}

int main() {
	int n, count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %s", person[i].name, person[i].password);
		person[i].isChanged = false;

	}
	for (int i = 0; i < n; i++) {
		ifChange(person[i], count);
	}
	if (count == 0) {
		if (n == 1) {
			printf("There is %d account and no account is modified", 1);
		}
		else {
			printf("There are %d accounts and no account is modified", n);
		}
	}
	else {
		printf("%d\n", count);
		for (int i = 0; i < n; i++) {
			if (person[i].isChanged) {
				printf("%s %s\n", person[i].name, person[i].password);
			}
		}
	}
	return 0;
}
