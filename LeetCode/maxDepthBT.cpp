#include <iostream>
#include<limits.h>
using namespace std;

//Definition for a binary tree node.
template <typename T> 
 struct TreeNode {
     T val;
     TreeNode *left;
     TreeNode *right;
     TreeNode<T>() : val(0), left(nullptr), right(nullptr) {}
     TreeNode<T>(T x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode<T>(T x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
	template <typename T>
    int maxDepth(TreeNode<T>* root) {
     	if(!root){
     		return 0;
     	}
     	return 1 + max(maxDepth(root->left),maxDepth(root->right));
     }
};
template <typename T>
	void Max(TreeNode<T>* root,T& max){
		if(root){
			if(max < root->val) max = root->val;
			Max(root->left, max);
			Max(root->right, max);
		}
	}
template <typename T>
	void Min(TreeNode<T>* root,T& min = 0){
		if(root){
			if(min > root->val) min = root->val;
			Min(root->left,min);
			Min(root->right,min);
		}
	}
template <typename T>
	bool isValidBST(TreeNode<T>* root){
		if(root){
			int max = INT_MIN, min = INT_MAX;
			Max(root->left, max);
			Min(root->right, min);
			if(root->val < max )
				return false;
			if(root->val > min){
				return false;
			}
			isValidBST(root->left);
			isValidBST(root->right);
		}
		return true;
	}



int main(){
	//Solution l;
	typedef int T;
	TreeNode<T> * root = new TreeNode<T>(3,new TreeNode<T>(2,new TreeNode<T>(4),new TreeNode<T>(8)),
		new TreeNode<T>(1,new TreeNode<T>(15),new TreeNode<T>(6)));

	typedef char T2;
	TreeNode<T2> * root2 = new TreeNode<T2>('A',new TreeNode<T2>('B',new TreeNode<T2>('D'),nullptr),
		new TreeNode<T2>('C',new TreeNode<T2>('E'),new TreeNode<T2>('F')));
	//int max = INT_MIN; Max(root->left,max); cout << max << endl;
	cout << isValidBST(root) << endl;
	return 0;
}