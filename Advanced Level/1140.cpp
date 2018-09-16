#include <iostream>
#include <string>
using namespace std;
int main() {
	string str;
	int n, j;
	cin >> str >> n;
	for (int time = 1; time < n; time++) {
	  string temp;
		for (int i = 0; i < str.length(); i = j) {
			for (j = i; j < str.length() && str[j] == str[i]; j++);
			temp += to_string((str[i] - '0')) + to_string(j - i);
		}
		str = temp;
	}
	cout << str;
	return 0;
}
