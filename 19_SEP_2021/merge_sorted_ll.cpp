#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode():val(),next(nullptr) {} // 
	ListNode(int x):val(x),next(nullptr){}// last node uses this
	ListNode(int x,ListNode* a_node) : val(x), next(a_node){} // non-last node can use this
};
class Solution {
public:
    
};
int main(){
	ListNode* l3 = new ListNode(1,new ListNode(2,new ListNode(4))); 
	ListNode* l2 = new ListNode(1,new ListNode(3,new ListNode(4))); 
	ListNode * l1 = new ListNode(-3);
	//l1 = l1->next;
	l1->next = new ListNode(3); 

	Solution l;
	//ListNode* out = l.mergeTwoLists(l1,l2);
	while(l1){
		cout << l1->val << ", ";
		l1 = l1->next;
	}cout << endl;
	return 0;
}