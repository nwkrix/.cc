#include<iostream>
using namespace std;

 // Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
      ~ListNode(){
      	cout << endl << " :: deleted :: " << endl;
      }
  };
 
class Solution {
	ListNode* root;

public:
	Solution(): root(nullptr){}
	 void display(ListNode* ptr){
    	ListNode* p = ptr;
    	while(p){
    		cout << p->val << ", ";
    		p = p->next;
    	}cout << endl;
    }
    ListNode* copyList2(ListNode* ptr){
    	ListNode* result = new ListNode(-1);
    	ListNode* curr = ptr;
    	ListNode* node;
    	while(curr->next){
    		node = new ListNode();
    		node->val = curr->val; //node->next = nullptr;
    		result->next = node;
    		result = result->next;
    		curr = curr->next;
    	}
    	node->next = curr->next->next;
    	return result->next;
    }

    ListNode* copyList(ListNode* ptr){
    	ListNode* beg = nullptr, *tail = nullptr,
    			*curr = ptr;
    	while(curr){
    		if(!beg){
    			beg = new ListNode();
    			beg->val = curr->val;
    			beg->next = nullptr;
    			tail = beg;
    		}else{
    			tail->next = new ListNode();
    			tail = tail->next;
    			tail->val = curr->val;
    			tail->next = nullptr;	
    		}
    		curr = curr->next;
    	}
    	return beg;
    }
    ListNode* reversed(ListNode *ptr) {
        ListNode*  curr = copyList(ptr), *ahead = NULL, *prev = NULL; 
        while(curr){
            ahead = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ahead;
        }            
        return prev;
    }
    

    bool isPalindrome(ListNode* head) {
    	ListNode* rev = reversed(head);
    	ListNode* curr = head;
    	while(curr && rev){
    		if(curr->val!=rev->val)
    			return false;
    		curr = curr->next;
    		rev = rev->next;
    	}
        return true;
    }
   
};

int main(){
	ListNode *head = new ListNode(1,new ListNode(1,new ListNode(2,new ListNode(1))));
	Solution l;
	l.display(head);
	ListNode* cpy = l.copyList(head);
	l.display(cpy);
	ListNode* rev = l.reversed(head);
	l.display(rev);
	cout << l.isPalindrome(head) << endl;
	delete head;
	return 0;
}