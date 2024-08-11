#include <iostream>
#include <map>

using namespace std;

int n,m,k,l,sum;
map<int,int> p;

int main(){
    scanf("%d%d",&n,&l);
    for(int i = 1;i <= n;i++){
        scanf("%d%d",&m,&k);
        p[m / k] += k;
    }
    // for(auto i = p.begin();i != p.end();i++){
    //     cout << i -> first << " ";
    // }
    for(auto i = --p.end();i != --p.begin();i--){
        if(l >= i -> second){
            l -= i -> second;
            sum += i -> second * i -> first;
        } else{
            sum += l * i -> first;
            l = 0;
            break;
        }
    }
    cout << sum;
    return 0;
}
