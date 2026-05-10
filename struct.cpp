#include <bits/stdc++.h>
using namespace std;

struct SinhVien {
    string ten; 
    float diem;   
};

bool cmp(SinhVien a, SinhVien b){
    if(a.diem != b.diem){
        return a.diem > b.diem;
    } 
    return a.ten < b.ten;
}

void bubble_sort(SinhVien a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n - i - 1; j++){
            if(cmp(a[j], a[j+1])) swap(a[j], a[j+1]);
        }
    }
}

void selection_sort(SinhVien a[], int n){
    for(int i = 0; i < n - 1; i++){
        int minindex = i;
        for(int j = i + 1; j < n; j++){
            if(cmp(a[j], a[minindex])){
                minindex = j;
            }
        }
        swap(a[i], a[minindex]); 
    }
}

int main(){
    int n = 15;
    SinhVien a[15] = {
        {"Chinh", 9},
        {"Bao", 10},
        {"Cuong", 9},
        {"An", 5},
        {"Minh", 7},
        {"Dung", 8},
        {"Huy", 6},
        {"Khanh", 9},
        {"Linh", 10},
        {"Nam", 7},
        {"Phuc", 8},
        {"Quang", 6},
        {"Son", 5},
        {"Tai", 9},
        {"Vy", 8}
    };

    //sort(a, a+n, cmp);
    //bubble_sort(a, n);
    selection_sort(a, n);

    for(int i = 0; i < n; i++){
        cout << a[i].ten << " " << a[i].diem << endl;
    }

    return 0;
}