#include<iostream>
#include<memory>
using namespace std;
struct Node {
	int val;
	shared_ptr<Node> next;

	Node() : val(), next(nullptr) {}
	Node(int a) : val(a), next(nullptr) {}
	Node(int a, shared_ptr<Node> next ) : val(a), next(next) {} // assignment operator= exist for weak_ptr, comparators don't
	~Node() {
		//cout << "ptr deleted " << endl;
	}
	 //shared_ptr<Node>& is like Node** for raw pointer
	// shared_ptr<Node> is equivalent to Node* 
	void display(shared_ptr<Node> ptr)  { 
		if (!ptr)
			return;
		//auto ptr = make_shared<Node>(*head);// deferencing only nece if we parse in pointer-to-ref
		while (ptr) {
			//cout << head.get() << endl;
			cout << ptr->val << endl;
			ptr = ptr->next;
		}
	}

	unique_ptr<Node> newNode(int val) {
		unique_ptr<Node> node = make_unique<Node>();
		node->val = val; node->next = nullptr;
		return node;
	}

	void append(int val, shared_ptr<Node>& ptr) {
		//auto sharedPtr = weakPtr.lock();
		if (ptr == NULL) {
			ptr = newNode(val);
		}
		shared_ptr<Node> last = ptr;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = newNode(val);
	}
	void prepend(int val, shared_ptr<Node>& ptr) {
		if (!ptr) {
			ptr = newNode(val);
			return;
		}
		shared_ptr<Node> tmp = newNode(val);
		(*tmp).next = ptr; // equivalently, tmp->next = ptr;
		ptr = tmp;
	}
	/// <summary>
	/// Merges two sorted linked list. This actually uses the same merge 
	/// idea from mergesort
	/// </summary>
	void mergeTwoList(shared_ptr<Node> list1, shared_ptr<Node> list2, shared_ptr<Node>& result) {
		shared_ptr<Node> res = make_shared<Node>(-1); result = res;
		while (list1 && list2) {
			if (list1->val < list2->val)
				res->next = list1, list1 = list1->next;
			else
				res->next = list2, list2 = list2->next;
			res = res->next;
		}
		while (list1)
			res->next = list1, list1 = list1->next, res = res->next;
		while (list2)
			res->next = list2, list2 = list2->next, res = res->next;
	}
	/// <summary>
	/// Reverses a linked list, so 
	/// </summary>
	void reverse(shared_ptr<Node>& ptr) { // ptr will be changed outside the fcn (pointer-to-ref
		shared_ptr<Node> current = ptr; 
		shared_ptr<Node> previous = nullptr, ahead = nullptr;
		while (current!=nullptr) {
			ahead = (*current).next;
			current->next = previous;
			previous = current;
			current = ahead;
		}
		ptr = previous; // ptr changed in main where reversed is called
	}
	/// <summary>
	/// Removes a node from a singly linked list when the head
	/// pointer is not known. 
	/// </summary>
	void remove_node_without_head(Node node,shared_ptr<Node>& ptr) { 
		node.val = node.next->val;
		node.next = node.next->next;
	}
	void remove(int val, shared_ptr<Node>& ptr) {
		auto current = ptr; auto previous = ptr; //ptr = previous;
		while (current && val != current->val) {
			previous = current;
			current = current->next;
		}
		if (current == ptr) {
			ptr = ptr->next;
			return;
		}
		if (!current) {
			previous = nullptr; return;
		}
		else
			previous->next = current->next;
	}
	shared_ptr<Node> isPalindrome2(shared_ptr<Node> ptr) {
		shared_ptr<Node> curr = make_shared<Node>(*ptr);
		shared_ptr<Node> prev = nullptr; auto rev = prev;
		shared_ptr<Node>ahead = nullptr;
		while (curr) {
			ahead = curr->next;
			curr->next = prev;
			prev = curr;
			curr = ahead;
		}
		rev = prev;
		return ptr;
	}
	// pointer-to-ref not necessary since we dont need to change 
	// the list outside the fcn
	bool isPalindrome(shared_ptr<Node>& ptr) { 
		auto reversed = [&]() {
			shared_ptr<Node> curr = make_shared<Node>(*ptr), 
				ahead = nullptr, prev = nullptr;
			while (curr) {
				ahead = curr->next;
				curr->next = prev;
				prev = curr;
				curr = ahead;
			}
			return prev;
		};
		shared_ptr<Node> rev = reversed();
		auto cur = make_shared<Node>(*ptr);
		while (rev && cur) {
			if (cur->val != rev->val)
				return false;
			rev = rev->next;
			cur = cur->next;
		}
		return true;
	}
};
int main()
{
	//shared_ptr<Node> head = make_unique<Node>(1,make_unique<Node>(2,make_shared<Node>(3)));
	shared_ptr<Node> list1 = make_shared<Node>(1, make_shared<Node>(9, make_shared<Node>(10)));
	auto list2 = make_shared<Node>(8, make_shared<Node>(11, make_shared<Node>(13)));
	//auto list3 = make_shared<Node>(2,make_shared<Node>(3,make_shared<Node>(3,make_shared<Node>(1))));
	Node l;
	//l.append(14, list1); l.prepend(5, list2);

	//l.reverse(head);
	auto head = make_shared<Node>();
	l.mergeTwoList(list1,list2,head); head = head->next;
	//l.remove(14, head);
	//l.display(list3);
	//auto rev = l.isPalindrome2(list1);
	l.display(head);
	//cout << l.isPalindrome(head) << endl;
	return 0;
}