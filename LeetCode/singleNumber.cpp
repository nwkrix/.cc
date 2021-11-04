#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) { // determines if a certain num is unique
        map<int,bool>seen;
        map<int,int>count;
        for(int i : nums){
            if(seen[i]){
                count[i] += 1;
            }
            if(!seen[i]){
                seen[i] = true;
                count[i] = 1;
            }
        }
        for(int i : nums){
            if(count[i] == 1){
                return i;
            }
        }
        return -1;
    }
};
int main(){
    Solution l;
    vector<int> nums = {1,1,2,6,2,6,9,10,10,9};
    cout << l.singleNumber(nums) << endl;
    return 0;
}