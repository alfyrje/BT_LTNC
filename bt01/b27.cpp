#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(1) {
		cin >> n;
		if(n == -1) {
			cout << "Bye";
			break;
		}
		cout << ((n >= 0 && n % 5 == 0)? (n / 5) : (-1)) << endl;
	}
	return 0;
}
