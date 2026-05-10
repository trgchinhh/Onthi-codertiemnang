// dùng string 
// #include <bits/stdc++.h>
// using namespace std;

// void nhapchuoi(string& s){
//     do {
//         cout << "Nhap chuoi: ";
//         getline(cin, s);
//     } while(s.empty());
// }

// int demsokytu(string s){
//     int cnt = 0;
//     for(char c : s){
//         cnt++;
//     }
//     return cnt;
// }

// int demsotu(string s){
//     int cnt = 0;
//     if(s.empty()) return 0;
//     else cnt++;
//     for(char c : s){
//         if(c == ' ') cnt++;
//     }
//     return cnt;
// }

// void xoakhoangtrangthua(string& s){
//     while(s[0] == ' '){
//         s.erase(0, 1);
//     }
//     while(s[s.length() -1] == ' '){
//         s.erase(s.length() - 1, 1);
//     }
//     for(int i = 0; i < s.length(); i++){
//         if(s[i] == ' ' && s[i+1] == ' '){
//             s.erase(i, 1);
//             i--;
//         }
//     }
//     cout << "Sau khi xoa khoang trang thua: " << s << endl;
// }

// void chuyensanginhoa(string s){
//     string m = "";
//     for(char c : s){
//         m += (char)toupper(c);
//     }
//     cout << "Chuoi sau khi in hoa: " << m << endl;
// }

// void chuyenhoadautu(string s){
//     string m = "";
//     for(int i = 0; i < s.length(); i++){
//         if(i == 0){
//             s[i] = (char)toupper(s[i]);
//         }
//         if(s[i] != ' ' && s[i-1] == ' '){
//             s[i] = (char)toupper(s[i]);
//         }
//         m += s[i];
//     }
//     cout << "Chuoi sau khi in hoa dau tu: " << m << endl;
// }

// void daonguocchuoi(string& s){
//     cout << "Chuoi sau khi dao nguoc: ";
//     for(int i = s.length() - 1; i >= 0; i--){
//         cout << s[i];
//     }
//     cout << endl;
// }

// int main(){
//     string s;
//     nhapchuoi(s);
//     cout << "So ky tu: " << demsokytu(s) << endl;
//     cout << "So tu: " << demsotu(s) << endl;
//     xoakhoangtrangthua(s);
//     chuyensanginhoa(s);
//     chuyenhoadautu(s);
//     daonguocchuoi(s);
//     return 0;
// }

// dùng mảng char
#include <bits/stdc++.h>
using namespace std;

void nhapchuoi(char s[], int n){
    do {
        cout << "Nhap chuoi: ";
        cin.getline(s, n);
    } while(s[0] =='\0');
}

int demsokytuchucai(char s[], int n){
    int cnt = 0;
    for(int i = 0; s[i] != '\0'; i++){
        if(isalpha(s[i])){
            cnt++;
        }
    }
    return cnt;
}

int demsotu(char s[], int n){
    int cnt = 0;
    if(s[0] == '\0') return 0;
    cnt++;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == ' ') cnt++;
    }
    return cnt;
}

void xoakhoangtrangthua(char s[], int n){
    while(s[0] == ' '){
        for(int i = 0; s[i] != '\0'; i++){
            s[i] = s[i+1];
        }
    }
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == ' ' && s[i+1] == ' '){
            for(int j = i; s[j] != '\0'; j++){
                s[j] = s[j+1];
            }
            i--;
        }
    }
    int len = strlen(s);
    while(s[len - 1] == ' '){
        s[len - 1] = '\0';
        len--;
    }
    cout << "Xoa khoang trang thua: " << s << endl;
}

void chuyensanginhoa(char s[], int n){
    for(int i = 0; s[i] != '\0'; i++){
        s[i] = (char)toupper(s[i]);
    }
    cout << "Chuyen sang in hoa: " << s << endl;
}

void inhoachucaidau(char s[], int n){
    s[0] = (char)toupper(s[0]);
    for(int i = 1; s[i] != '\0'; i++){
        if(s[i] != ' ' && s[i-1] == ' '){
            s[i] = (char)toupper(s[i]);
        } else s[i] = (char)tolower(s[i]);
    }    
    cout << "Chuoi sau khi in hoa dau tu: " << s << endl;
}

void daonguocchuoi(char s[], int n){
    int len = strlen(s);
    cout << "Chuoi sau khi dao nguoc la: ";
    for(int i = len -1; i >= 0; i--){
        cout << s[i];
    }
}

int main(){
    int n = 100;
    char s[n];
    nhapchuoi(s, n);
    cout << "So ky tu chu cai: " << demsokytuchucai(s, n) << endl;
    cout << "So tu: " << demsotu(s, n) << endl;
    xoakhoangtrangthua(s, n);
    chuyensanginhoa(s, n);
    inhoachucaidau(s, n);
    daonguocchuoi(s, n);
    return 0;
}