#include<iostream>
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
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head, * cur, * tail, * ahead, * previous = NULL;
        int nodes = 1;
        while (curr) {
            ahead = curr->next;
            curr->next = previous;
            previous = curr;
            curr = ahead;
            nodes++;
        }
        tail = previous; nodes = nodes / 2;
        curr = head, cur = tail;
        ListNode* fast = NULL;
        while (nodes > 0) {
            if (curr->val!= cur->val)
                return false;
            nodes--;
            curr = curr->next;
            cur = cur->next;
        }
        return true;
    }

    bool isPalindrome2(ListNode* head) { // not passed
        if (head->next == nullptr)
            return true;
        ListNode* curr = head, * tail, * ahead, * previous = NULL;
        while (curr) {
            ahead = curr->next;
            curr->next = previous;
            previous = curr;
            curr = ahead;
        }
        tail = previous;
        while (head && tail) {
            if (head->val != tail->val)
                return false;
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
};
/*
int main() {
    Solution l;
    ListNode* a = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    bool t = l.isPalindrome2(a);
    cout << t << endl;
	return 0;
}
*/