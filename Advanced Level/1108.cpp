#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
bool isLegal(string input) {
	if (input[0] == '-') {
		input.erase(input.begin());
	}
	if (input.length() == 0) {
		return false;
	}
	int dotPos = -1;
	for (int i = 0; i < input.length(); i++) {
		if (!(input[i] == '.' || (input[i] >= '0'&&input[i] <= '9')) ){
			return false;
		}
		if (input[i] == '.') {
			if (dotPos != -1) {
				return false;
			}
			else {
				dotPos = i;//找到小数点的位置
			}
		}
	}
	if (dotPos != -1 && dotPos + 3 < input.length()) {//小数点后不超过2位
		return false;
	}
	double tempNumber;
	sscanf(input.c_str(), "%lf", &tempNumber);//重要
	return tempNumber <= 1000;
}
int main() {
	int n, num = 0;
	cin >> n;
	double sum = 0, tempNumber;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (isLegal(input)) {
			sscanf(input.c_str(), "%lf", &tempNumber);
			sum += tempNumber;
			num++;
		}
		else {
			printf("ERROR: %s is not a legal number\n", input.c_str());
		}
	}
	if (num == 0) {
		printf("The average of 0 numbers is Undefined\n");
	}
	else if (num == 1) {
		printf("The average of 1 number is %.2f\n", sum);
	}
	else {
		printf("The average of %d numbers is %.2f\n", num, sum / num);
	}
	return 0;
}
