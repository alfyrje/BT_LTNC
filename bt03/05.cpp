#include <iostream>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int num = 1;
    int upLeft = 0;
    int a[m][n];
    int m1 = m, n1 = n;
    while(num <= m1 * n1){
        for(int j = upLeft; j < n; j++){
            a[upLeft][j] = num;
            num++;
        }
        if(m - 1 > upLeft){
            for(int i = upLeft + 1; i < m; i++){
                a[i][n - 1] = num;
                num++;
            }
            if(n - 1 > upLeft){
                for(int j = n - 2; j >= upLeft; j--){
                    a[m - 1][j] = num;
                    num++;
                }
                for(int i = m - 2; i > upLeft; i--){
                    a[i][upLeft] = num;
                    num++;
                }
            }
        }
        upLeft++;
        m--; n--;
    }

    for(int i = 0; i < m1; i++){
        for(int j = 0; j < n1; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
