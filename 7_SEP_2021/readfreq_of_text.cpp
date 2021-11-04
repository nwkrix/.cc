#include<iostream>
#include<fstream>
#define ARRSIZE 26
using namespace std;

void readfile(int *arr){
	ifstream t;
	t.open("file_sample");
	char i = t.get();
	if(t){
		while(i !=EOF){ // t.peek()!=EOF
			i = toupper(i);
			++arr[int(i)-int('A')];
			i = t.get();
		}
	}
	t.close();
}

void display(int *arr){
	for (char i = 'A'; i <= 'Z'; i++){
		cout << i << " => " << arr[int(i)-int('A')] << ", " ;
	}cout << endl;
}

int main(){
	int arr[ARRSIZE]{0};
	readfile(arr);
	display(arr);
	return 0;
}