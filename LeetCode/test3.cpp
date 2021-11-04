#include<iostream>
#include<list>
#include<string> // stoull
using namespace std;
class Solution{
public:
	long long unsigned int fibo_naive(int n){
		if(n==1 || n==0){
			return 1;
		}
		return fibo_naive(n-1) + fibo_naive(n-2); 
	}
	long long unsigned int fibo_memoize(int n, long long int memo[]){
		if(memo[n]){
			return memo[n];
		}
		if(n==1 || n==0){
			return 1;
		}
		memo[n] = fibo_memoize(n-1,memo) + fibo_memoize(n-2,memo);
		return memo[n]; 
	}

	unsigned int long long fibo_bottom_up(int n){
		unsigned int long long* bottom_up = new unsigned int long long[n];
		bottom_up[0] = 1;
		bottom_up[1] = 1;
		for(int i = 2; i <= n; i++){
			bottom_up[i] = bottom_up[i-1] + bottom_up[i-2];
		}
		return bottom_up[n];
	}

private:
	int result;
	string strResult = "";
};

int main(){
	Solution l;
	int n = 2000;
	long long int memo[n+1] {};
	memo[4] = 5; // memoization
	//cout << l.fibo_naive(n) << endl; //Naive solution: as n gets to say, 40 - 45, uncomment this line.
	cout << l.fibo_memoize(n,memo) << endl;
	cout << l.fibo_bottom_up(n) << endl;	 
}