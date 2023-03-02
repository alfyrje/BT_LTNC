#include<bits/stdc++.h>
using namespace std;

int main() {
	for(int i = 0; i < 24; i++) {
		if(i == 0) cout << "12 midnight";
		else if(i > 0 && i < 12) cout << i << "am";
		else if(i == 12) cout << "12 noon";
		else cout << i - 12 << "pm";
		cout << endl;
	}
	return 0;
}
