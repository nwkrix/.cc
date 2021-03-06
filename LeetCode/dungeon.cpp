#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<limits.h>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int M = dungeon.size();
        int N = dungeon[0].size();
        vector<vector<int>> hp(M+1, vector<int>(N+1, INT_MAX));
        hp[M][N-1] = 1;
        hp[M-1][N] = 1;
        for (int i=M-1; i>=0; --i){
            for (int j=N-1; j>=0; --j){
                hp[i][j] = max(1, min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j]);
            }
        }
        return hp[0][0];
    }
};
int main(){
     vector<vector<int>> dungeon = {
        {1,-3,3},
        {0,-2,0},
        {-3,-3,-3}
    };
    Solution l;
    cout << l.calculateMinimumHP(dungeon) << endl;
    return 0;
}