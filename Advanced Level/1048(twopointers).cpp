#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, p;
	cin >> n>> p;
	int a[100005];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int i = 0; int j = n-1;
	while (i < j) {
		if (a[i] + a[j] == p) {

			break;
		}
		else if (a[i] + a[j] < p) {
			i++;
		}
		else {
			j--;
		}
	}
	if (i <j) {
		cout << a[i]<<" "<<a[j]<<endl;
	}else{
	  cout<<"No Solution\n";
	}
	return 0;
}
