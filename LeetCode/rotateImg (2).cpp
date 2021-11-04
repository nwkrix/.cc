#include<iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;
auto Transpose = [](int& a, int& b) {int tmp = a; a = b, b = tmp; };
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) { // 90 deg rotation is simply Transposition, then mirroring
        // TRANSPOSE THE MATRIX
        size_t len = matrix[0].size(); map<std::pair<int, int>, bool> Transposed;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                if (i == j) continue;
                if (!Transposed[{i, j}] && !Transposed[{j, i}]) {
                    ::Transpose(matrix[i][j], matrix[j][i]);
                    Transposed[{i, j}] = true;
                }
            }
        }

        // MIRROR THE MATRIX
        for (int row = 0; row < len; row++) {
            int i = 0, j = len - 1;
            while (i < j) {
                ::Transpose(matrix[row][i], matrix[row][j]); // row-wise
                i++, j--;
            }
        }
    }
    void display(vector<vector<int>> m, int len) {
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                cout << m[i][j] << ", ";
            }cout << endl;
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    }, matrix2 = { {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };

    Solution l;
    l.rotate(matrix2);
    l.display(matrix2, 4);
    return 0;
}
