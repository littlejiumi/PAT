#include <iostream>
#include <cmath>
using namespace std;
typedef long long  ll;
ll num;
ll first=0, len=0;
int main() {
	cin >> num;
	ll maxn = sqrt(num);
	for (ll i = 2; i <= maxn; i++) {
		ll j = i;
		ll temp = 1;
		while (1) {
			temp *= j;
			if (num%temp != 0) {
				break;
			}
			if (j - i +1> len) {
				len = j - i+1;
				first = i;
			}
			j++;
		}
	}
	if (len == 0) {
		cout << 1 << endl << num ;
	}
	else {
		cout << len << endl;
		for (int i = 0; i < len; i++) {
			cout << first + i;
			if (i < len - 1) {
				cout << "*";
			}
		}
	}
	return 0;
}
