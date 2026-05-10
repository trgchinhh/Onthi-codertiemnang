#include <bits/stdc++.h>
using namespace std;

void nhapmang(int a[], int n){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

int timmin(int a[], int n){
    int min = 1e9;
    for(int i = 0; i < n; i++){
        if(a[i] < min) min = a[i];
    }
    return min;
}

int timmax(int a[], int n){
    int max = -1e9;
    for(int i = 0; i < n; i++){
        if(a[i] > max) max = a[i];
    }
    return max;
}

int tongchan(int a[], int n){
    int rs = 0;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0) rs += a[i];
    }
    return rs;
}

int snt(int n){
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int demsnt(int a[], int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(snt(a[i])){
            cnt++;
        }
    }
    return cnt;
}

int timptxhnhieu(int a[], int n){
    int mang[n];
    fill(mang, mang+n, 0);
    for(int i = 0; i < n; i++){
        mang[a[i]]++;
    }
    int rs = timmax(mang, n);
    if(rs > 1) return rs;
    else return -1;
}

void xoa1pt(int a[], int& n, int k){
    for(int i = k; i < n - 1; i++){
        a[i] = a[i+1];
    }
    n--;
}

void xoaallptam(int a[], int& n){
    for(int i = 0; i < n; i++){
        if(a[i] < 0){
            xoa1pt(a, n, i);
        }
    }
    cout << "Danh sach sau khi xoa tat ca pt am: ";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void chenptvaovtK(int a[], int n, int pt, int k){
    for(int i = n; i > k; i--){
        a[i] = a[i-1];
    }
    a[k] = pt;
    n++;
    cout << "Danh sach sau khi chen " << pt << " vao vt so " << k << endl;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int n; cin >> n;
    int a[n];
    nhapmang(a, n);
    cout << "Min: " << timmin(a, n) << endl;
    cout << "Max: " << timmax(a, n) << endl;
    cout << "Tong chan: " << tongchan(a, n) << endl;
    cout << "Dem snt: " << demsnt(a, n) << endl;
    cout << "Tim pt xh nhieu: " << timptxhnhieu(a, n) << endl;
    xoaallptam(a, n);
    chenptvaovtK(a, n, 5, 3);
    return 0;
}
