#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;
    int i = 0, j = s.length() - 1;
    while(i < j){
        if(s[i] != s[j]){
            std::cout << "No";
            return 0;
        }
        i++;
        j--;
    }
    std::cout << "Yes";
    return 0;
}
