#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

int num = 0;
string a,b;
string x[11],y[11];

struct node{
    string s;
    int step;
};

map<string,bool> m;
queue<node> q;

int main(){
    cin >> a >> b;
    while(cin >> x[++num] >> y[num]);
    q.push({a,0});
    while(q.size()){
        node h = q.front();
        q.pop();
        if(h.step > 10) continue;
        if(h.s == b){
            cout << h.step;
            return 0;
        }
        for(int i = 1;i <= num;i++){
            int l = 0;
            for(int j = 0;j < h.s.size();j++){
                l = h.s.find(x[i],j);
                if(l == -1) break;
                string c = h.s;
                c.replace(l,x[i].size(),y[i]);
                if(m[c]) continue;
                m[c] = 1;
                q.push({c,h.step + 1});
            }
        }
    }
    cout << "NO ANSWER!";
    return 0;
}
