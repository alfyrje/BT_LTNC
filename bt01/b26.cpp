#include<bits/stdc++.h>
using namespace std;

int a[10005];

int main() {
	int n, mn = LONG_MAX, mx = LONG_MIN;
	double sum;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	cout << "Mean: " << sum / n << endl;
	cout << "Max: " << mx << endl;
	cout << "Min: " << mn;

	return 0;
}
