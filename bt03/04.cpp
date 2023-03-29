#include <iostream>

int main()
{
    int m, n; std::cin >> m >> n;
    char a[m + 2][n + 2];
    for(int i = 0; i < m + 2; i++){
        for(int j = 0; j < n + 2; j++) a[i][j] = '.';
    }
    for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++) std::cin >> a[i][j];
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == '*') std::cout << '*' << ' ';
            else{
                int c = 0;
                if(a[i-1][j-1] == '*') c++;
                if(a[i-1][j] == '*') c++;
                if(a[i-1][j+1] == '*') c++;
                if(a[i][j-1] == '*') c++;
                if(a[i][j+1] == '*') c++;
                if(a[i+1][j-1] == '*') c++;
                if(a[i+1][j] == '*') c++;
                if(a[i+1][j+1] == '*') c++;
                std::cout << c << ' ';
            }
        }
        std::cout << '\n';
    }
    return 0;
}
