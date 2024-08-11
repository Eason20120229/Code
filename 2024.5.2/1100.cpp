#include <iostream>
#include <string>

using namespace std;

int main(){
    unsigned int n;
    cin >> n;
    string s;
    while(n){
        s = char(n % 2 + '0') + s;
        n /= 2;
    }
    while(s.size() < 32){
        s = '0' + s;
    }
    s = s.substr(16,16) + s.substr(0,16);
    unsigned int ans = 0,two = 1;
    for(int i = 31;i >= 0;i--){
        ans += (s[i] - '0') * two;
        two *= 2;
    }
    cout << ans;
    return 0;
}
