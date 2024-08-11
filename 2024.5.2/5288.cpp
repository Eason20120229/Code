#include <bits/stdc++.h>

using namespace std;

string a,b;
string n[6][2];
int i = 0;

struct node{
    string s;
    int step;
};

queue<node> q;
map<string,int> m;

int main(){
    cin >> a >> b;
    while(cin >> n[i][0] >> n[i][1]) i++;
    q.push({a,0});
    m[a] = 1;
    int f = 1;
    while(q.size()){
        node h = q.front();
        q.pop();
        if(h.step > 10) continue;
        if(h.s == b){
            f = 0;
            cout << h.step;
            break;
        }
        for(int j = 0;j < i;j++){
            int l;
            for(int k = 0;k < h.s.size() && l != -1;k = l){
                l = h.s.find(n[j][0],k);
                if(l < 0) continue;
                string c = h.s;
                c.replace(l,n[j][0].size(),n[j][1]);
                if(m[c]) continue;
                m[c] = 1;
                q.push({c,h.step + 1});
            }
        }
    }
    if(f) cout << "NO ANSWER!";
    return 0;
}
