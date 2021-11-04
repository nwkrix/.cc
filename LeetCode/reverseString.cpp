#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t len = s.size();
        int i = 0, j = len-1; char tmp;
        while(i<j)
        {
        	tmp = s[i], s[i] = s[j], s[j] = tmp, i++, j--; 
        }
    }
};


int main(){
	vector<char> v {'h','e','l','l','o','n'};
	Solution l;
	l.reverseString(v);
	for(char i : v){
		cout << i << ", ";
	}cout << endl;
	return 0;
}