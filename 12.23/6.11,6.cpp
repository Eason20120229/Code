#include<iostream>

using namespace std;

int main(){
	int a,b,c,d;
	for(int A = 0;A <= 1;A++){
		for(int B = 0;B <= 1;B++){
			for(int C = 0;C <= 1;C++){
				for(int D = 0;D <= 1;D++){
					a = (B + C + D == 1);
					b = (!B && C);
					c = (A + D == 1);
					d = b;
					if(a + b + c + d == 2 && A + B + C + D == 1){
						cout << A << " " << B << " " << C << " " << D << endl;
					}
				}
			}
		}
	}
	return 0;
}
