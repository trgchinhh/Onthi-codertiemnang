#include <bits/stdc++.h>
using namespace std;

int demtongle(int a[], int n, int i){
    if(i >=n) return 0;
    if(a[i] % 2 != 0){
        return a[i] + demtongle(a, n, i+1);
    }
    return demtongle(a, n, i+1);
}

int tinhtongmang(int a[], int n, int i){
    if(i >= n) return 0;
    return a[i] + tinhtongmang(a, n, i+1);
}

int demsochan(int a[], int n, int i){
    if(i >= n) return 0;
    if(a[i] % 2 == 0){
        return 1 + demsochan(a, n, i+1);
    }
    return demsochan(a, n, i+1);
}

int timmax(int a[], int n, int i){
    if(i == n - 1) return a[i];
    int max = timmax(a, n, i + 1);
    if(a[i] > max) return a[i];
    return max;
}

int timvtdautiencuaX(int a[], int n, int i, int x){
    if(i >= n) return 0;
    if(a[i] == x) return i;
    return timvtdautiencuaX(a, n, i+1, x);
}

bool kiemtramangtangdan(int a[], int n, int i){
    if(i == n - 1) return true;
    if(a[i] > a[i+1]) return false;
    return kiemtramangtangdan(a, n, i + 1);
}

int snt(int n){
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int demsnt(int a[], int n, int i){
    if(i >= n) return 0;
    if(snt(a[i])) {
        return 1 + demsnt(a, n, i + 1);
    }
    return demsnt(a, n, i+1);
}

void innguocchuoi(string s, int i){
    if(i < 0) return;
    cout << s[i];
    innguocchuoi(s, i-1);
}

int demkytuinhoa(string s, int i){
    if(i >= s.length()) return 0;
    if(s[i] == toupper(s[i])){
        return 1 + demkytuinhoa(s, i+1);
    } 
    return demkytuinhoa(s, i+1);
}

int tinhtongchuso(int n){
    if(n < 10) return n;
    return (n % 10) + tinhtongchuso(n / 10);
}

int demsochuso(int n){
    if(n < 10) return 1;
    return 1 + demsochuso(n / 10);
}

void innguocso(int n){
    if(n == 0) return;
    cout << n % 10;
    innguocso(n / 10);
}

int tinhgiaithua(int n){
    if(n == 1) return 1;
    if(n == 0) return 0;
    return n * tinhgiaithua(n - 1);
}

int tinhfibonacci(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return tinhfibonacci(n - 1) + tinhfibonacci(n - 2);
}

int tinhluythua(int a, int n){
    if(n == 0) return 1;
    return a * tinhluythua(a, n - 1);
}

int main(){
    int a[5] = {1, 2, 3, 4, 5};
    string s = "Chinh";

    cout << "Tong le: " << demtongle(a, 5, 0) << endl;
    cout << "Tong mang: " << tinhtongmang(a, 5, 0) << endl;
    cout << "Dem so chan: " << demsochan(a, 5, 0) << endl;
    cout << "Max: " << timmax(a, 5, 0) << endl;
    cout << "Vi tri dau tien cua 2: " << timvtdautiencuaX(a, 5, 0, 2) << endl;
    cout << boolalpha << "Mang tang dan: " << kiemtramangtangdan(a, 5, 0) << endl;
    cout << "Dem snt: " << demsnt(a, 5, 0) << endl;
    cout << "Dao nguoc chuoi: "; innguocchuoi(s, 4); cout << endl;
    cout << "Dem ky tu in hoa: " << demkytuinhoa(s, 0) << endl;
    cout << "Tinh tong chu so: " << tinhtongchuso(12345) << endl;
    cout << "Dem chu so: " << demsochuso(12345) << endl;
    cout << "In nguoc so: " ; innguocso(12345); cout << endl;
    cout << "Tinh giai thua: " << tinhgiaithua(5) << endl;
    cout << "Tinh fibonacci: " << tinhfibonacci(12) << endl;
    cout << "Tinh luy thua: " << tinhluythua(5, 4) << endl;

    return 0;
}
