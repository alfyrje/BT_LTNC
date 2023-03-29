#include <iostream>
#include <cmath>

using namespace std;

string balancedSums(int arr[], int n)
{
    //sumFromLeft[i]: tong tu arr[0] den arr[i]
    //sumFromRight[i]: tong tu arr[n - 1] den arr[i]
    int sumFromLeft[n], sumFromRight[n];
    for(int i = 0; i < n; i++){
        sumFromLeft[i] = sumFromRight[i] = 0;
    }
    sumFromLeft[0] = arr[0];
    sumFromRight[n - 1] = arr[n - 1];
    for(int i = 0; i < n; i++){
        sumFromLeft[i + 1] = sumFromLeft[i] + arr[i + 1];
        sumFromRight[n - i - 2] = sumFromRight[n - i - 1] + arr[n - i - 2];
    }
    //neu chon pivot la so dau hoac so cuoi
    if(sumFromLeft[n - 1] == 0 || sumFromRight[0] == 0) return "YES";
    //chon pivot o giua
    for(int i = 1; i < n - 1; i++){
        if(sumFromLeft[i - 1] == sumFromRight[i + 1]) return "YES";
    }
    return "NO";
}

int main()
{
	int q; cin >> q;
	for(int j = 0; j < q; j++){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        cout << balancedSums(arr, n) << endl;
	}
    return 0;
}
