#include <iostream>

int main()
{
    int n; std::cin >> n;
    int a[n];
    bool seen[10001];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        if(!seen[a[i]]) seen[a[i]] = true;
        else{
            std::cout << "Yes";
            return 0;
        }
    }
    std::cout << "No";
    return 0;
}
