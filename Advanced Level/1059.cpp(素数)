#include<iostream>
#include<cmath>
using namespace std;
const int maxn = 100010;
struct num{
	int p,k;
}Num[10];
bool isPrime(int n) {
	if (n <= 1)return false;
	int sqr = sqrt(n);
	for (int i = 2; i <= sqr; i++) {
		if (n%i == 0)return false;
	}
	return true;
}
int prime[maxn], pNum = 0;
void findPrime() {
	for (int i = 1; i < maxn; i++) {
		if (isPrime(i)) {
			prime[pNum++] = i;    //用pNum++计数
		}
	}
}
int main() {
	findPrime();
	int n, s = 0;
	cin >> n;
	if (n == 1) {
		cout << "1=1";
	}
	else {
		cout << n << "=";
		int ma = sqrt(n);
		for (int i = 0; i < pNum && prime[i]<= ma; i++) {
			if (n % prime[i] == 0) {
				Num[s].p = prime[i];
				Num[s].k = 0;
				while (n % prime[i] == 0) {
					Num[s].k++;
					n /= prime[i];
				}
				s++;
			}
			if (n == 1)break;
		}
		if (n != 1) {
			Num[s].p = n;
			Num[s++].k = 1;
		}
		for (int i = 0; i < s; i++) {
			if (i > 0)cout << "*";
			cout << Num[i].p;
			if (Num[i].k > 1) {
				cout << "^" << Num[i].k;
			}
		}
	}
	return 0;
}
