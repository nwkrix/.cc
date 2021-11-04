#include<iostream>
#include<cstring>
#include<fstream>
#define ARRSIZE 26
using namespace std;
auto display = [](int a[], int len){
	for(int i = 0; i < len; i++){
		cout << a[i] << " ";
	}
};
char read(){
	fstream file("file_sample",ios::in);
	if(!file.is_open()){
		cout << "Failed to open file" << endl;
		exit(1);
	}
	int arr[ARRSIZE]{0};
	char ch;
	while(file >> ch){
		ch = toupper(ch);
		++arr[int(ch)-int('A')];
	}
	int idx = 0;
	for(int i = 1; i < ARRSIZE; i++){
		if(arr[i] > arr[idx]) idx = i;
	}
	::display(arr, ARRSIZE);
	cout << endl;
	for(char ch =  'A'; ch <='Z'; ch++){
		if((int(ch)-'A') == idx){
			return ch;
		}
	}
}
int main(){
	char ch = read();
	cout << "Most frequent letter is " << ch << endl;
	return 0;
}