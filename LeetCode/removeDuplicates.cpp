#include<iostream>
#include<vector>
#include<map>
using namespace std;
int removeDuplicates(vector<int>& nums) {
    const int len = nums.size();
    int k = 0;
    map<int,bool> seen;
    for(int i = 0; i< len ; i++){
		if(!seen[nums[i]]){
			seen[nums[i]] = true;
			nums[k] = nums[i];
			k++;
		}
    }
    for(int i = k; i < len; i++){
    	nums.pop_back(); 
    }
    return k;
}

int main(){
	vector<int> nums {0,1,1,1,2,2,3,4};
	int k = removeDuplicates(nums);
	for(int i : nums){
		cout << i << ",";
	}cout << endl;
	cout << k << endl;
	return 0;
}