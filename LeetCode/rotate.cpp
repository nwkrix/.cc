#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/*
		this program shifts (or rotates) an array k unit forward
		and in sequence and it returns the overflow to the 
		beginning also in sequence 
	*/
    void rotate(int nums[], int len, int k) {  // 40 ms
    	int * arr = new int[len];
    	for(int i=0;i<len;i++){
    		*(arr+i) = nums[i];
    	}
    	for(int i = 0; i < len; i++){
    		nums[(i+k) % len] = arr[i];
    	}


    }

    void rotate2(vector<int>& nums, int k) { // faster runtime 8 ms
        int size=nums.size();
        if(size<=1)return;
        k%=size;
        auto s=nums.begin(),e=nums.end();
        std::reverse(s,e-k); //O(n)
        std::reverse(e-k,e);
        std::reverse(s,e);
    }



};
int main(){
	Solution l;
	int nums[] = {1,2,3,4,5,6,7}, len = *(&nums+1)-nums;
	l.rotate(nums,len,k);
	for(int i: nums){cout << i << ", ";}cout << endl;
	return 0;
}