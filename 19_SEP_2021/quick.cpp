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
      	//cout << endl << " :: deleted :: " << endl;
      }
  };
 
class Solution {
public:
    void display(ListNode* ptr)  { 
        if (!ptr)
            return;
        while (ptr) {
            cout << ptr->val << ", ";
            ptr = ptr->next;
        }cout << endl;
    }
    ListNode* reversed(ListNode* Ptr){
        ListNode * ptr = Ptr;
        if(!ptr)
            return nullptr;
        ListNode* prev = nullptr, *ahead = nullptr;
        while(ptr){
          ahead = ptr->next;
          ptr->next = prev;
          prev = ptr;
          ptr = ahead;  
        }
        return prev;
    }
	
   
};

int main(){
    Solution l;
	ListNode *head = new ListNode(1,new ListNode(1,new ListNode(2,new ListNode(1))));
	ListNode *rev = l.reversed(head);
    l.display(head);
    l.display(rev);
	delete head;
	return 0;
}