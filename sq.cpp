#include <bits/stdc++.h>
using namespace std;

void nhapmang(int a[], int n){
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

// tro choi vong xoay loai tru 
void vongxoayloaitru(int a[], int n, int k){
    queue<int> q;
    for(int i = 0; i < n; i++){
        q.push(a[i]);
    }
    while(q.size()>1){
        for(int i = 1; i < k; i++){
            q.push(q.front());
            q.pop();
        }
        cout << "Loai: " << q.front() << endl;
        q.pop();
    }
    cout << "Nguoi song: " << q.front() << endl;
}

// kiem tra ngoac 
bool kiemtrangoac(string s){
    stack<char> st;
    for(char c : s){
        if(c == '(' || c == '{' || c == '['){
            st.push(c);
        } else {
            if(st.empty()) return false;
            else {
                char top = st.top();
                if((c == ')' && top == '(') ||
                    (c == '}' && top == '{') || 
                    (c == ']' && top == '[')){
                    st.pop();
                } else return false;
            }
        }
    }
    return st.empty();
}

int main(){
    int n; cin >> n;
    int a[n];
    nhapmang(a, n);
    vongxoayloaitru(a, n, 3);

    string s = "{[()[[]]}";
    cout << boolalpha << "Ngoac " + s + " hop le: " << kiemtrangoac(s) << endl;
    return 0;
}