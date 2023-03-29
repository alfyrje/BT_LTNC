#include <iostream>

bool checkSymmetry(std::string s)
{
    int i = 0, j = s.length() - 1;
    while(i < j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

bool checkMirror(int n)
{
    std::string s_n = "";
    while(n > 0){
        int x = n % 10;
        s_n += char(x);
        n /= 10;
    }
    return checkSymmetry(s_n);
}

int main()
{
    int t; std::cin >> t;   //test cases
    for(int i = 0; i < t; i++){
        int a, b, c = 0;
        std::cin >> a >> b;
        for(int i = a; i <= b; i++){
            if(checkMirror(i)) c++;
        }
        std::cout << c << std::endl;
    }
    return 0;
}
