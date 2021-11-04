#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }

    int singleNumber2(vector<int>& nums) {
        map<int, bool>seen;
        map<int, int>count;
        for (int i : nums) {
            if (seen[i]) {
                count[i]++;
            }
            if (!seen[i]) {
                seen[i] = true;
                count[i] = 1;
            }

        }
        for (int i : nums) {
            if (count[i] == 1) {
                return i;
            }
        }
        return -999;
    }

};
/*
int main() {
    Solution l;
    vector<int> u = { 3,1,1,3,4,4,7,8,7 };
    int v = l.singleNumber(u);
    cout << v << endl;
    return 0;
}
*/