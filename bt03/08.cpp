#include <iostream>
#include <algorithm>

using namespace std;
//tra ve vi tri dung cho gia tri high
//be hon nam ben trai high, lon hon nam ben phai high
int partion(int a[], int low, int high);
//sap xep mang a tu low den high
void quickSort(int a[], int low, int high);
//tinh tong thoi gian cac khach hang phai cho
int sumWaitingTime(int a[], int n);

int main()
{
    int n; cin >> n;
    int t[n];
    for(int i = 0; i < n; i++) cin >> t[i];
    quickSort(t, 0, n - 1);

    for(int i = 0; i < n; i++) cout << t[i];
    cout << endl;
    cout << sumWaitingTime(t, n);
    return 0;
}

int sumWaitingTime(int a[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        //a[i] vao kham thi a[i+1], ..., a[n-1] cho
        sum += (n - i - 1) * a[i];
    }
    return sum;
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
