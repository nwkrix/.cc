#include<iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;
class Solution{
public:
	void pixels_rotate90deg(vector<vector<int>>& mat){
		/*Transposition*/
		int tmp; map<std::pair<int,int>,bool> Transposed;
		for(int i=0; i<mat.size(); i++){
			for(int j= 0;j<mat.size();j++){
				if(i==j) continue;
				if(!Transposed[{i,j}] && !Transposed[std::make_pair(j,i)]){
					tmp = mat[i][j], mat[i][j] = mat[j][i], mat[j][i] = tmp; 
					Transposed[std::make_pair(i,j)] = true;
				}
			}
		}

		/*Vertical Mirroring */
		int col_s = 0, col_n = mat.size()-1;
		while(col_s < col_n){
			for(int row = 0; row < mat.size(); row++){
				swap(mat[row][col_s],mat[row][col_n]);
			}
			col_s++, col_n--;
		}
	}

};

int main(){
	vector<vector<int>> mat = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	Solution l;
	l.pixels_rotate90deg(mat);
	for(vector<int> v : mat){
		for(int i : v){
			cout << i << ", ";
		}cout << endl;
	} 
	return 0;
}