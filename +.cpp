#include<bits/stdc++.h>
using namespace std;

int shu(string s){
    int i = s.size() - 1;
    int shi = 1;
    int sum = 0;
    while(i >= 0){
        sum += shi * (s[i] - '0');
        shi *= 10;
        i--;
    }
    return sum;
}

int len(int k){
    int c = 0;
    if(k <= 0) c++;
    while(k){
        c++;
        k /= 10;
    }
    return c;
}

int main(){
    int n;
    cin >> n;
    string c;
    int a,b;
    string l;
    while(n--){
        cin >> c;
        if(c == "a"){
            cin >> a >> b;
            int t = a + b;
            cout << a << "+" << b << "=" << t << endl;
            cout << len(a) + len(b) + len(t) + 2 << endl;
            l = c;
        }else if(c == "b"){
            cin >> a >> b;
            int t = a - b;
            cout << a << "-" << b << "=" << t << endl;
            cout << len(a) + len(b) + len(t) + 2 << endl;
            l = c;
        }else if(c == "c"){
            cin >> a >> b;
            int t = a * b;
            cout << a << "*" << b << "=" << t << endl;
            cout << len(a) + len(b) + len(t) + 2 << endl;
            l = c;
        }else{
            a = shu(c);
            cin >> b;
            c = l;
            if(c == "a"){
                int t = a + b;
                cout << a << "+" << b << "=" << t << endl;
                cout << len(a) + len(b) + len(t) + 2 << endl;
                l = c;
            }else if(c == "b"){
                int t = a - b;
                cout << a << "-" << b << "=" << t << endl;
                cout << len(a) + len(b) + len(t) + 2 << endl;
                l = c;
            }else if(c == "c"){
                int t = a * b;
                cout << a << "*" << b << "=" << t << endl;
                cout << len(a) + len(b) + len(t) + 2 << endl;
                l = c;
            }
        }
    }
    return 0;
}