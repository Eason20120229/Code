#include<bits/stdc++.h>
using namespace std;

double a,b,c,d;
double f(double x){
    return a * x * x * x + b * x * x + c * x + d;
}

int main(){
    double l,r,m,f1,f2;
    int s = 0;
    for(int i = -100;i <= 100;i++){
        l = i;
        r = i + 1;
        f1 = f(l);
        f2 = f(r);
        if(!f1){
            printf("%.3f ",l);
            s++;
        }
        if(f1 * f2 < 0){
            while(r - l >= 0.001){
                m = (l + r) / 2;
                if(f(m) * f(r) <= 0) l = m;
                else r = m;
            }
        }
        printf("%.3f ",r);
        s++;
        if(s == 3) break;
    }
    return 0;
}