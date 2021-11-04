#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> fcn(vector<vector<int>>& in){
	return in[0];
}



void display(vector<int>& in){
	for_each(in.begin(), in.end(),[](int i ){
		if(i != 0){
			cout << i << ", ";
		}
	 });
	cout << endl;
}
int main() {
	vector<vector<int>> in = {
			{0,2,3,0},
			{5,6,0,8},
			{9,0,11,12}
	};
	vector<int> o = fcn(in);
	display(o);
	return 0;
}
