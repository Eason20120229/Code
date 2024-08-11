#include <iostream>

using namespace std;

int main(){
    char c;
    int i = 0,j = 0,f = 0;
    do{
        cin >> c;
        if(c == 'T') i++;
        else if(c == 'M') j++;
        if(i == 10 && i == j) f = 1;
        if((i - f >= 11 || j - f >= 11)){
            cout << i << ":" << j << endl;
            i = 0;
            j = 0;
            f = 0;
        }
    }while(c != '#');
    if(i != 0 || j != 0) cout << i << ":" << j << endl;
    return 0;
}

