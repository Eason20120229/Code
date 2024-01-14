#include<iostream>

using namespace std;

int main(){
	for(int A = 0;A <= 100;A++){
		for(int B = 0;B <= 100;B++){
			for(int C = 0;C <= 100;C++){
				for(int D = 0;D <= 100;D++){
					for(int E = 0;E <= 100;E++){
						if(!(A && C) && (B || C)
							&& (C && (D && !E || E && !D) || !C) &&
							!(B && C && D) && B && (!(D && E)) || !B){
								cout << A << "	" << B << "	" << C << "	" << D << "	" << E << endl;
							}
					}
				}
			}
		}
	}
	return 0;
}
