#include<iostream>
using namespace std;
int main(){
	int x = 31;
	cout << ((2 << (x-1))== 1 << x) << endl;
	
	cout << -(2 << (x-1)) << endl;
	
	cout << (4 >> 3) << endl;
	return 0;
}