#include<iostream>
#include<list>
#include<map>
#include<queue>
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
	std::map<int,int> getSum(Node* root,int&& i){
		if(!root) return {};
		arr[i] += root->val;
		getSum(root->left,i-1);
		getSum(root->right,i+1);
		return arr;
	}	
	std::vector<int> verticalSum(Node* root){
		std::vector<int> vec;
		arr = getSum(root,0);
		std::map<int,int> :: iterator it = arr.begin();
		while(it!=arr.end()){
			vec.push_back(it->second);
			it++;
		}
		return vec;
	}
private:
	std::map<int,int> arr;
};
int main(){
	Node* tree = new Node(50,new Node(40,new Node(30,new Node(25),new Node(39,new Node(35),nullptr)),new Node(45)),new Node(70,new Node(60,nullptr,new Node(65)),new Node(78)));
	Node* Tree = new Node(5,new Node(2,new Node(1),new Node(4,new Node(3),nullptr)),new Node(8,new Node(6),new Node(9)));
	Solution l;
	for(int i : l.verticalSum(Tree)) {std::cout << i << ", ";} std::cout << std::endl;
	return 0;
}