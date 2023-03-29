#include <iostream>

using namespace std;

int main()
{
    int n; cin >> n;
    int a[n][n];
    bool check_a[n][n];
    int i = 0, j = n / 2;
    a[i][j] = 1;
    check_a[i][j] = true;
    int num = 2;
    while(num <= n * n){
        int y = j + 1;
        int x = i - 1;
        if(x < 0) x = n - 1;
        if(y > n - 1) y = 0;
        if(!check_a[x][y]){
            i = x; j = y;
            a[i][j] = num;
            check_a[i][j] = true;
        }
        else{
            i++;
            if(i < 0) i = n - 1;
            if(j > n - 1) j = 0;
            a[i][j] = num;
            check_a[i][j] = true;
        }
        num++;
    }

    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++)
            cout << a[x][y] << ' ';
        cout << '\n';
    }
    return 0;
}
