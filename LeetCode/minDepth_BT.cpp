#include<iostream>

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {  // alternative to breadth first search
        vector<vector<int>> v;
        levelNeigbor = getLevelOrder(root,0);
        map<int,vector<int>> :: iterator it = levelNeigbor.begin();
        while(it!=levelNeigbor.end()){
            v.push_back(it->second);
            it++;
        }
        return v;
    }
    int minDepth(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        if(!root)   return 0;
        if(root->left==nullptr)
            return 1 + minDepth(root->right);
        if(root->right==nullptr)
            return 1 + minDepth(root->left);
        int ans = min(minDepth(root->left),minDepth(root->right))+1;
        root->left=NULL;
        return ans;
    }
    int minDepth2(TreeNode* root) {
       if(!root) return 0;
        int l=minDepth(root->left);
        int r=minDepth(root->right);
        if(min(l,r)==0) return max(l,r)+1;
        return min(l,r)+1;
    }

    int minDepth3(TreeNode* root) { // my solution
        if(!root)
            return 0;
        return (!root->left||!root->right) ? 1 + max(minDepth(root->left),minDepth(root->right)) : 1 + min( minDepth(root->left), minDepth(root->right));
    }

     int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + std::max(maxDepth(root->left),maxDepth(root->right));
        
    }

    /*
			Given a binary tree, determine if it is height-balanced. For this problem, a height-balanced binary tree is defined as:
			a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
    */
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(abs(heightSubTree(root->left) - heightSubTree(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
private:
	// Utility functions
    int heightSubTree(TreeNode* root){
        if (!root)
            return 0;
        return 1 + max(heightSubTree(root->left),heightSubTree(root->right));
    }

    map<int,vector<int>> levelNeigbor;
    map<int,vector<int>> getLevelOrder(TreeNode* r, int&& level){
        if(!r)
            return {};
        levelNeigbor[level].push_back(r->val);
        getLevelOrder(r->left,level+1);
        getLevelOrder(r->right,level+1);
        return levelNeigbor;
    }
};

int main(){
	return 0;
}