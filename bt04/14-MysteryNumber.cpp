#include <iostream>
#include <cmath>

using namespace std;

//tra ve vi tri dung cho gia tri high
//be hon nam ben trai high, lon hon nam ben phai high
int partion(int a[], int low, int high);
//sap xep mang a tu low den high
void quickSort(int a[], int low, int high);
//tim so bi an
int mysteryNum(int a[], int b[], int n)
{
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) return b[i];
    }
    return b[n];
}

int main()
{
	int n; cin >> n;
	int a[n], b[n + 1];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i <= n; i++) cin >> b[i];
	quickSort(a, 0, n - 1);
	quickSort(b, 0, n);
	cout << mysteryNum(a, b, n);
    return 0;
}

int partion(int a[], int low, int high)
{
    int pivot = a[high];    //chon khoa de sap xep la phan tu cuoi
    int i = low - 1;    //vi tri xuat phat cua phan tu be hon pivot
    for(int j = low; j < high; j++){
        //dua cac phan tu be hon pivot don ve dau
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);  //dua phan tu cuoi ve dung vi tri
    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if(low < high){
        int pi = partion(a, low, high);
        quickSort(a, low, pi - 1);  //sort mang truoc pi
        quickSort(a, pi + 1, high); //sort mang sau pi
    }
}
