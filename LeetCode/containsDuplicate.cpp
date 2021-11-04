#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool> seen;
        for(int i : nums){
            if(seen[i]){
                return true;  // the order is crucial.
            }
            if(!seen[i]){
                seen[i] = true; // if this comes 1st, it gives misleading result
            }
        }
        return false;
    }
};
int main(){
    Solution l;
    vector<int> nums = {1,2,3,4,5,6,2,8,9,10};
    cout << l.containsDuplicate(nums) << endl;
    return 0;
}