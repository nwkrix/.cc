#include<iostream>
#include<limits.h>
struct Node{
    int val;
    Node* left, * right;
    Node() : val(), left(nullptr), right(nullptr) {}
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
    Node(int val, Node* left, Node* right) : val(val), left(left), right(right) {}
};

class Solution{
public:
	bool isBST(Node* root){
		int Min = INT_MIN, Max = INT_MAX;
		return isBST(root,Min,Max);
	}
private:
	bool isBST(Node* root, int Min, int Max){
		if(!root)
			return true;
		if(root->val < Min || root->val > Max)
			return false;
		return isBST(root->left, Min, root->val) && isBST(root->right, root->val, Max);
	}
};
int main(){
	Node* Tree = new Node(5,new Node(2,new Node(1),new Node(4,new Node(3),nullptr)),new Node(8,new Node(6),new Node(9)));
	Node* t = new Node(5,new Node(6),new Node(5));
	Solution l;
	std::cout << l.isBST(t) << std::endl;
	return 0;
}