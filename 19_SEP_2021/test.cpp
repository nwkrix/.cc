#include<iostream>
using namespace std;
int main(){
	int a = 6;
	int* b = &a;
	a = 9;
	cout << *b << endl;
	*b = 11;
	cout << a << endl;
	cout << b << ", " << &a << endl;
	b = new int[4]{}; // on heap
	cout << b << ", " << *b << endl;
	delete b;
	b = &a;
	cout << *b << endl;
	delete b, b = NULL;
	return 0;
}