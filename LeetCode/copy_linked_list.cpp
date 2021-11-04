#include<iostream>
#include<unordered_map>
#include<map>
#include<utility>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(-99999), next(nullptr) {}
	ListNode(int val) : val(val), next(nullptr) {}
	ListNode(int val, ListNode* next) : val(val), next(next) {}
};
class Solution {
public:
	void copylist(ListNode* source, ListNode** output) {
		if (!source) return;
		ListNode* ptr = source, * n;
		ListNode* copy = nullptr;
		while (ptr) {
			n = new ListNode(ptr->val);
			if (!copy) {
				copy = n;
				*output = copy; // take the head here before it's updated in the else block
			}
			else {
				copy->next = n;
				copy = n;
			}
			ptr = ptr->next;
		}
	}
	void display(ListNode* head) {
		ListNode* ptr = head;
		while (ptr) {
			cout << ptr->val << ", ";
			ptr = ptr->next;
		}cout << endl;
	}
};
/*
int main() {
	ListNode* head = new ListNode(-1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	ListNode* copy = nullptr;
	Solution l;
	l.copylist(head, &copy);
	l.display(copy);
	l.display(head);
	return 0;
}
*/