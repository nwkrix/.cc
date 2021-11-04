#include<iostream>

struct ListNode{
	int val;
	ListNode* next;
	ListNode() : val(-111111),next(nullptr) {}
	ListNode(int val) : val(val), next(nullptr) {}
	ListNode(int val, ListNode* next) : val(val), next(next) {}
};
class Solution{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* ahead = ahead, * prev = nullptr, * curr = head;
		//ListNode* Res;
		int i = 1;
		while(i <= n){
			ahead = ahead->next;
			i++;
		}
		//if(!ahead) return nullptr;
		while(ahead){
			ahead = ahead->next;
			prev = curr;
			curr = curr->next;
		}
		if(curr == head){
			return head->next;
		}else{
			prev->next = curr->next;
		}
		return head;
	}
	void display(ListNode* ptr){
		ListNode* p = ptr;
		while(p){
			std::cout << p->val << ", ";
			p = p->next;
		}std::cout << std::endl;
	}
};
int main(){
	Solution l;
	ListNode* head = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
	l.removeNthFromEnd(head,5);
	l.display(head);
	return 0;
}