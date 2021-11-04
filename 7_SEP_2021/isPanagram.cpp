/*
	A panagram is a sentence that contains all 
	the Alphabets of a Language. In this case, 
	English Lang.

	Author: C. Nwachioma
*/

#include<iostream>
#define ARRSIZE 26
using namespace std;
bool isPanagram(std::string s) {
	int arr[ARRSIZE]{ 0 };
	int len = s.size(); 
	char ch;
	for (int i = 0; i < len; i++) {
		ch = toupper(s[i]);
		ch = char(ch);
		++arr[int(ch) - int('A')];
	}
	auto display = [](int* arr) {
		for (int i = 0; i < ARRSIZE; i++) {
			cout << arr[i] << ", ";
		}cout << endl;
	};
	//display(arr);
	for (int i = 0; i < ARRSIZE; i++) {
		if (arr[i] == 0) return false;
	}
	return true;
}

int main() {
	std::string s = "The quick brown dog jumps over the lazy fox"; // returns true, a panagram
	//std::string s = "I love programming"; // returns false, not a panagram
	cout << isPanagram(s) << endl;
	return 0;
}