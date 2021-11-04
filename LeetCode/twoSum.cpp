#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map< int, int > visited;
        for (int i = 0; i < nums.size(); i++) {
            if (visited.find(target - nums[i]) != visited.end()) {
                return { visited[target - nums[i]], i };
            }
            visited[nums[i]] = i;
        }
        return {};
    }
};
/*
int main() {
    Solution l;
    vector<int> u = { 3,1,3,4,9,7,8 };
    vector<int> v = l.twoSum(u, 8);
    for (int i : v) { cout << i << ", "; } cout << endl;
    return 0;
}
*/