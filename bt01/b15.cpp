#include<bits/stdc++.h>
using namespace std;

string f[10];

int main() {
	f[0] = "a"; f[1] = "b";
	for(int i = 2; i < 10; i++) f[i] = f[i - 1] + f[i - 2];
	for(int i = 0; i < 10; i++) cout << f[i] << endl;
	return 0;
}
