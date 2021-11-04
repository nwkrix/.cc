#include<iostream>
using namespace std;
char first_nonrepeating_char(string& s){
	size_t len = s.size();
	int arr[len]{};
	for(char k : s){
		++arr[k-'a'];
		//cout << k-'a' << ",";
	}//cout << endl;
	for(int i : arr){
		cout << i << ", ";
	}cout << endl;
	for(int i = 0; i < len; i++){
		cout << arr[i] << ", ";
	}cout << endl;
}
int main()
{
	string s = "aaabcccdeeef";
	first_nonrepeating_char(s);
	return 0;
}