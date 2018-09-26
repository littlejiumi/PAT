#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 10010;
int hashTable[maxn] = { false };

bool isPrime(int n) {
	if (n <= 1)return false;
	int sqr = (int)sqrt(1.0*n);
	for (int i = 2; i <= sqr; i++) {
		if (n%i == 0)return false;
	}
	return true;
}
int main() {
	int m, n,a;
	scanf("%d%d", &m,&n);
	while(isPrime(m) == false) {
		m++;
	}
	for (int i = 0; i < n; i++) {
		
		scanf("%d", &a);
		if (hashTable[a%m] == false) {
			hashTable[a%m] = true;
			if(i==0)printf("%d",a%m);
			else printf(" %d",a%m);
		}
		else {
			int step;
			for (step = 1; step < m; step++) {
			  
			 int x = (a + step*step)%m;
				if (hashTable[x] == false) {
					hashTable[x] = true;
					if (i == 0) {
						printf("%d", x);
					}
					else {
						printf(" %d", x);
					}
					break;
				}
			}
			if(step>=m){
			  if (i != 0) {
				printf(" -");
			}
			else {
				printf("-");
			}
			}
			
		}

	}
	return 0;
}
