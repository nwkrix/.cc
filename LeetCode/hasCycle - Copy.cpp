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
    ListNode* curr = head, *ahead = curr; 
        if(head == NULL ){
            return false;
        }        
        if(head->next==NULL){
            return false;
        }

        while(curr){
            curr = curr->next;
            int i = 0;
            while(i < 2 && ahead){
                ahead = ahead->next;
                i++;
            }
            if(ahead == NULL){
                return false;
            }
            if(ahead == curr)
                return true;
        }
        return false;
    }   
    
};
int main(){
    Solution l;
    ListNode* ptr = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    ListNode* curr = ptr, *lag = ptr, *out = lag;
    int i = 0;
    while(i < 3 && curr){ 
        curr = curr->next;
        i++;
    }
    if(!curr){
        cout << curr->val << endl;
        cout << "-1" << endl;
        return 0;
    }
    while(lag->next){
        lag = lag->next;
        //curr = curr->next;
    }
    lag->next = curr;

    //bool out = l.hasCycle(ptr);
    //cout << out << endl;
 
    while(out){
        cout << out->val << ", ";
        out = out->next;
    }cout << endl;
    return 0;
}
