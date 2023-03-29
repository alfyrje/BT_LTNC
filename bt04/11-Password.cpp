#include <iostream>
using namespace std;

bool checkSym(string a, string b)
{
	int n = a.length();
	if(b.length() != n) return false;
	for(int i = 0; i < n; i++){
		if(a[i] != b[n - i - 1]) return false;
	}
	return true;
}

int main() {
	int num;
	cin >> num;
	string s[num];
	for(int i = 0; i < num; i++){
		cin >> s[i];
	}
	int length;
	for(int i = 0; i < num; i++){
		for(int j = i + 1; j < num; j++){
			if(checkSym(s[i], s[j])){
				length = s[i].length();
				cout << length << ' ' << s[i][length / 2];
				return 0;
			}
		}
	}
}
