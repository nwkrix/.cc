#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() :val(), next(nullptr) {} // 
    ListNode(int x) :val(x), next(nullptr) {}// last node uses this
    ListNode(int x, ListNode* a_node) : val(x), next(a_node) {} // non-last node can use this
};
class Solution {
public:
    ListNode* newNode(int data) {
        ListNode* node = new ListNode();
        node->val = data, node->next = nullptr;
        return node;
    }
    void append(int data, ListNode** root) {
        if (*root == nullptr) {
            *root = newNode(data);
            return;
        }
        ListNode* current = *root;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode(data);
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                this->append(l1->val, &head);
                l1 = l1->next;
            }else{
                this->append(l2->val,&head);
                l2 = l2->next;
            }
        }
        while (l1) {
            this->append(l1->val, &head); 
            l1 = l1->next;
        }
        while (l2) {
            this->append(l2->val,&head);
            l2 = l2->next;
        }
        return head;
    }
};
/*
int main() {
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4,new ListNode(8))));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    Solution l;
    ListNode* out = l.mergeTwoLists(l1, l2);
    while (out) {
        cout << out->val << ", ";
        out = out->next;
    }cout << endl;
    return 0;
}*/