#include <iostream>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head, *curr = head, *prev = curr, 
        *res = prev;
        int i = 0;
        while(i < n-1  ){
            cur = cur->next;
            i++;
        }
        //return cur;
        if(!cur){ // is cur is null, !cur = true
            return nullptr; // return if index n exceeds linked list nodeCount  
        }
        while(cur->next){
            prev = curr;
            curr = curr->next;
            cur = cur->next;
        }
        if(curr == head){
            return head->next; // deleting 1st node from beginining
        }else if(curr->next == NULL){
            prev->next = NULL; // deleting last node (i.e. 1st node from end)
        }else{ 
            prev->next = curr->next; // deleting a linking node
        }
        return res;
    }
};
int main(){
    Solution l;
    ListNode* ptr = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    //ListNode* ptr = new ListNode(1,new ListNode(2));
    //ListNode* ptr = new ListNode(1);
    ListNode* out = l.removeNthFromEnd(ptr,2);

    while(out){
        cout << out->val << ", ";
        out = out->next;
    }cout << endl;
    return 0;
}

/*
        if(cur->next==NULL && n == 1)
            return nullptr;
        int nodeCount = 1;
        while(cur->next){
            nodeCount++;
            cur = cur->next;
        }
        cout << nodeCount << endl;
        return head;
*/