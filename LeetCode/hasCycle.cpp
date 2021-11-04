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
    bool hasCycle(ListNode* head) {
    ListNode* curr = head, *ahead = head; 
        if(head == NULL ){
            return false;
        }        
        if(head->next==NULL){
            return false;
        }   
    
        while(curr && ahead){
            curr = curr->next;
            ahead = ahead->next->next;
            if(curr == ahead){
                return true;
            }
        }
        return false;
    }
};
int main(){
    Solution l;
    ListNode* ptr = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    cout << l.hasCycle(ptr) << endl;
    return 0;
}

//[-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5], -1