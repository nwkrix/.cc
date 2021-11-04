#include<iostream>
#include<vector>
using namespace std;
std::vector<int> merge(vector<int>& a,vector<int>& b){
	int i = 0, j = 0, k = 0;
	vector<int> o(a.size()+b.size(),0);
	while(i<a.size() && j<b.size()){
		if(a[i] < b[j])
			o[k] = a[i], i++;
		else
			o[k] = b[j], j++;
		k++;
	}
	while(i<a.size())
		o[k] = a[i], i++, k++;
	while(j<b.size())
		o[k] = b[j], j++, k++;
	return o;
}

int main(){
	vector<int> a = {2,6,8,9,30}, b = {4,7,7,17,19,21}, o = merge(a,b);
	for(int i : o) {cout << i << ", ";}; cout << endl;
	return 0;
}