#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map< int, int > visited;
        for (int i = 0; i < nums.size(); i++) {
			 if (visited.find(target-nums[i])!=visited.end()) {
                return { visited[target-nums[i]], i };				
            }
            visited[nums[i]] = i;
        }
        return {};
    }
};
int main() {
    Solution l;
    vector<int> u = { 3,1,5,4,9,6,8 };
    vector<int> v = l.twoSum(u, 8);
    for (int i : v) { cout << i << ", "; } cout << endl;
    return 0;
}