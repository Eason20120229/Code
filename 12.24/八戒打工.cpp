#include <iostream>

using namespace std;

int p[7];

int main(){
    int sum = 0;
    for(int i = 1;i <= 6;i++){
        cin >> p[i];
    }
    sum = p[6] + p[5] + p[4];
    sum += ceil(p[3]/4.0);
    p[3] %= 4;
    p[1] -= min(p[1],p[5] * 11);
    if(p[2] < p[4] * 5){
        p[1] -= min(p[1],(p[4] * 5 - p[2]) * 4);
    }
    p2 -= min(p[2],p[4] * 5);
    if(p[3] == 3){
        if(!p2) p1
    }
    return 0;
}