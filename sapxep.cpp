#include <bits/stdc++.h>
using namespace std;

void nhapmang(int a[], int n){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void duyetmang(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
    cout << "Mang sau khi sap xep noi bot: ";
    duyetmang(a, n);
}

void selection_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int minindex = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[minindex]){
                minindex = j;
            }
        }
        swap(a[i], a[minindex]);
    }
    cout << "Mang sau khi sap xep chon: ";
    duyetmang(a, n);
}

void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
    cout << "Mang sau khi sap xep chen: ";
    duyetmang(a, n);
}

int main(){
    int n; cin >> n;
    int a[n];
    nhapmang(a, n);
    bubble_sort(a, n);
    selection_sort(a, n);
    insertion_sort(a, n);
    return 0;
}