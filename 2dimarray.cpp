#include <bits/stdc++.h>
using namespace std;

void nhapmang(int a[10][10], int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
}

int tinhtongcheochinh(int a[][10], int n, int m){
    int rs = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == j) rs += a[i][j];
        }
    }
    return rs;
}

int tinhtongcheophu(int a[][10], int n, int m){
    int rs = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i + j == n - 1){
                rs += a[i][j];
            }
        }
    }
    return rs;
}

int tinhtongtamgiac(int a[][10], int n, int m, int loai){
    int rs = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // 1 tren trai
            if(loai == 1 && i + j <= n - 1)
                rs += a[i][j];
            // 2. tren phai
            if(loai == 2 && j >= i)
                rs += a[i][j];

            // 3. duoi trai
            if(loai == 3 && j <= i)
                rs += a[i][j];

            // 4. duoi phai
            if(loai == 4 && i + j >= n - 1)
                rs += a[i][j];
        }
    }
    return rs;
}

int timdongtongmax(int a[][10], int n, int m){
    int max = -1e9;
    int tong = 0;
    int id = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tong += a[i][j];
            if(tong > max){
                max = tong; id = i;
            }
        }
    }
    return id;
}

int snt(int n){
    if(n < 2) return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int timcotnhieusnt(int a[][10], int n, int m){
    int max = -1e9;
    int id = -1;
    for(int j = 0; j < m; j++){
        int dem = 0;
        for(int i = 0; i < n; i++){
            if(snt(a[i][j])){
                dem++;
            }
        }
        if(dem > max){
            max = dem;
            id = j;
        }
    }
    return id;
}

int main(){
    int n, m; cin >> n >> m;
    int a[10][10];
    nhapmang(a, n, m);

    cout << "Tong cheo chinh: " << tinhtongcheochinh(a, n, m) << endl; 
    cout << "Tong cheo phu: " << tinhtongcheophu(a, n, m) << endl;
    cout << "Tong tam giac tren trai: " << tinhtongtamgiac(a, n, m, 1) << endl;
    cout << "Tong tam giac tren phai: " << tinhtongtamgiac(a, n, m, 2) << endl;
    cout << "Tong tam giac duoi trai: " << tinhtongtamgiac(a, n, m, 3) << endl;
    cout << "Tong tam giac duoi phai: " << tinhtongtamgiac(a, n, m, 4) << endl;
    cout << "Dong co tong max: " << timdongtongmax(a, n, m) << endl;
    cout << "Cot co nhieu snt: " << timcotnhieusnt(a, n, m) << endl;

    return 0;
}
