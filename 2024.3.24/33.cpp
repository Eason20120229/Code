#include<bits/stdc++.h>
using namespace std;
queue<char> q;
int main() {
    string s = "";
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '(') q.push(s[i]);
        else if(s[i] == ')'){
            if(q.back() == '(') q.pop();
            else{
                cout << "Wrong";
                return 0;
            }
        }else if(s[i] == '[') q.push(s[i]);
        else if(s[i] == ']'){
            if(q.back() == '[') q.pop();
            else{
                cout << "Wrong";
                return 0;
            }
        }
    }
    if(!q.empty()) cout << "Wrong";
    else cout << "OK";
    return 0;
}
