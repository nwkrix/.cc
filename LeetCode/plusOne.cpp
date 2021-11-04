/*You are given a large long integer represented as an long integer array digits, where each digits[i]
is the ith digit of the long integer. The digits are ordered from most significant to least 
significant in left-to-right order. The large long integer does not contain any leading 0's.

Increment the large long integer by one and return the resulting array of digits.*/
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
auto Pow = [](long int base, long int exp){
	long int product = 1;
	for(long int i=0;i<exp;i++){
		product *= base;
	}
	return product;
};
class Solution {
public:
    vector<long int> plusOne(vector<long int>& digits) {
     auto len = digits.size();
     long int num = 0;
     for(long int i=0; i < len; i++){
     	num += digits[i] * ::Pow(10,len-1-i);
     }
     num++;
     long int n = num ;
     if(log10(num) == len){ // checking if **9 is such that increment digitsize
     	 len++;
     }
     vector<long int> v(len,0); long int i = 0; 
     while(num > 0){
     	v[(len-1-i)] = num % 10; num/=10;
     	i++;
     }
     return v;   
    }
};
int main(){
	Solution l; 
	vector<long int> u = {9,8,7,6,5,4,3,2,1,0}, v;
	v = l.plusOne(u);
	for(long int i : v){
        cout << i << ", ";
    }cout << endl;
	return 0;
}