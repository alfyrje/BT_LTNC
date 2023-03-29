#include <iostream>
#include <cmath>

using namespace std;

void sievePrime(int n, bool isPrime[])
{
    isPrime[0] = isPrime[1] = false;    //0 va 1 khong la so nguyen to
	for(int i = 2; i <= n; i++) isPrime[i] = true;
	for(int i = 2; i <= n; i++){
        //neu i la so nguyen to thi cac boi cua i la hop so
        if(isPrime[i]){
            for(int k = i * i; k <= n; k += i)
                isPrime[k] = false;
        }
	}
}

int main()
{
	int n; cin >> n;
	//isPrime[i] = true <=> i la so nguyen to
	bool isPrime[n+1];
	sievePrime(n, isPrime);
	for(int i = 0; i <= n; i++)
        if(isPrime[i]) cout << i << ' ';
    return 0;
}
