#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size(); 
        int j = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i]!=0) {
                nums[j] = nums[i];
                j++;
            }
        }
        while (j < len) {
            nums[j] = 0;
            j++;
        }
    }
};
/*
int main() {
    Solution l;
    vector<int> u = { 0 };
    l.moveZeroes(u);
    for (int i : u) {
        cout << i << ", ";
    }cout << endl;
	return 0;
}
*/
