#include<iostream>
using namespace std;
char first_nonrepeating_char(string& s) {
	size_t len = s.size();
	int* arr = new int[len] {0};
	for (char k : s) {
		++arr[k - 'a'];
	}
	int sum = 0;
	for (int i = 0; i < len; i++) {
		if (arr[i] == 1)
			return toupper(s[sum]);
		sum += arr[i];
	}
	return '_';
}
int main()
{
	string s = "aaabbcccdeeef";
	cout << first_nonrepeating_char(s) << endl;
	return 0;
}