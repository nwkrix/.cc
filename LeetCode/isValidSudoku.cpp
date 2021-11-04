#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<string>>& board) {
    	unordered_map<string,bool>seen_in_subsq;
    	/*
    	SEEING DUPLICATE IN ROW
		for this, the right index (or j in board[i][j]) is the fastest, i.e. 
		for each  row i, the col (or j) is more  quickly scanned horizontally.
		*/
		auto checkRow = [&board](int rowLength, int colLength,int rowStart, int colStart){
			for(int row = rowStart; row < rowLength; row++){
	    		unordered_map<string,bool>seen_in_axis;
	    		for(int col = colStart; col < colLength; col++){
	    			if(board[row][col] == ".") continue;  
	    			if( seen_in_axis.find(board[row][col] )!= seen_in_axis.end() ) 
	    				return false;
	    			seen_in_axis[ board[row][col] ] = true;  
	    		}
    		}
    		return true;	
		};
    	
		
    	/*
    		SEEEING DUPLICATE IN COL
			To see dublicate while scanning vertically, the internal index or left index 
			will be faster than the right index. That is, given board[i][j], i should be 
			faster
    	*/
    	auto checkCol = [&board](int rowLength, int colLength, int rowStart, int colStart){
    		for(int row = rowStart; row < rowLength; row++){
	    		unordered_map<string,bool>seen_in_axis;
	    		for(int col = colStart; col < colLength; col++){
	    			if(board[col][row] == ".") continue;
	    			if( seen_in_axis.find(board[col][row] )!= seen_in_axis.end() )
	    				return false;
	    			seen_in_axis[ board[col][row] ] = true; 
	    		}
    		}
    		return true;
    	};


    	/*
			SEEING DUBPLICATE IN THE SUB-BOXES
    	*/
    	for(int row = 0; row < 3; row++){
    		for(int col = 0; col < 3; col++){
    			if ( !checkRow(3*row+3,3*col+3,3*row,3*col) or !checkCol(3*row+3,3*col+3,3*row,3*col) )
    				return false;
    		}
    	}
        

    	if (!checkRow(9,9,0,0) or !checkCol(9,9,0,0)){
    		return false;
    	}

        return true;
    }
};
int main(){
	vector<vector<string>> board = 
	{
		{"5","3",".",".","7",".",".",".","."},
		{"6",".",".","1","9","5",".",".","."},
		{".","9","8",".",".",".",".","6","."},
		{"8",".",".",".","6",".",".",".","3"},
		{"4",".",".","8",".","3",".",".","1"},
		{"7",".",".",".","2",".",".",".","6"},
		{".","6",".",".",".",".","2","8","."},
		{".",".",".","4","1","9",".",".","5"},
		{".",".",".",".","8",".",".","7","9"}
	}, board2 = 
	{
		{".",".",".",".","5",".",".","1","."},
		{".","4",".","3",".",".",".",".","."},
		{".",".",".",".",".","3",".",".","1"},
		{"8",".",".",".",".",".",".","2","."},
		{".",".","2",".","7",".",".",".","."},
		{".","1","5",".",".",".",".",".","."},
		{".",".",".",".",".","2",".",".","."},
		{".","2",".","9",".",".",".",".","."},
		{".",".","4",".",".",".",".",".","."}
	};
	Solution l;
	cout << l.isValidSudoku(board2)  << endl; 
	cout << board.size() << endl;
	return 0;
}