#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> twoSum(vector<int> nums, int target) {
	vector<int> res;
	int len = nums.size() - 1;
	sort(nums.begin(), nums.begin() + len);
	for (int i = 0; i <= len; i++) {
		//if(nums[i])
	}
	return res;
}

/*
int main() {
	vector<int> u = { 3,1,5,4,9,7,8 };
	vector<int> v = twoSum(u,9);
	for (int i : u) { cout << i << ", "; } cout << endl;
	return 0;
}*/