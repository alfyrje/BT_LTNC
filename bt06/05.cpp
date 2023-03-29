#include <iostream>
#include <vector>

using namespace std;

int n, sum = 0;
vector<int> a;

void print()
{
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
}

void tong(int x)
{
    for(int k = x; k >= 1; k--){
        sum += k;
        a.push_back(k);
        if(sum == n) print();
        else if(sum < n) tong(k);

        sum -= k;
        a.pop_back();
    }
}

int main()
{
    cin >> n;
    tong(n);
    return 0;
}

/*
4

4
3 1
2 2
2 1 1
1 1 1 1
*/