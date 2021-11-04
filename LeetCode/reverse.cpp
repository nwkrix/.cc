#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int n = x;
        if( n < 0) n = -n;
        int reversed = 0, i = log10(n);
        while(n > 0){
            reversed  +=  (n % 10) * ceil(pow(10,i));
            n /= 10;
            i--;
        }
        return (x < 0) ? -reversed : reversed;
    }
};

int main(){
	Solution l;
	cout << l.reverse(1534236469) << endl;
	return 0;
}