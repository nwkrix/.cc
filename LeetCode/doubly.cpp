#include<iostream>
//Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};
// Definition for Doubly - linked list.
struct Doubly {
    int data; Doubly* prev, * next;
    Doubly(int data) : data(data), prev(nullptr), next(nullptr) {}
};
class Solution {
public:
    template <typename T>
    void destroy(T* ptr) // destroys dynamically created objects
    { // this->destroy<ListNode>(head) or (*this).destroy<Doubly>(Head);
        int count = 0;
        T* tmp;
        while (ptr) {
            tmp = ptr;
            ptr = ptr->next;
            delete tmp;
            count++;
        }
        std::cout << count << " nodes deallocated " << std::endl;
    }
    // creates a doubly linked list from the given singly linked list
    void Dlist(ListNode* Ptr, Doubly** Head, Doubly** Tail) {
        ListNode* ptr = Ptr;
        Doubly* headtmp = *Head, * tailtmp = *Tail, * n;
        while (ptr) {
            n = new Doubly(ptr->val);
            if (headtmp == NULL) {
                headtmp = n; tailtmp = n;
            }
            else {
                n->prev = tailtmp; tailtmp->next = n; tailtmp = n;
            }
            ptr = ptr->next;
        }
        // update && output Head and Tail
        *Head = headtmp;
        *Tail = tailtmp;
    }
    // Iterate from both ends in equal steps & compare data
    bool isPalindrome(ListNode* head) {
        Doubly* Head = NULL, * Tail = NULL;
        Dlist(head, &Head, &Tail);
        while (Head && Tail) {
            if (Head->data != Tail->data)
                return false;
            Head = Head->next;
            Tail = Tail->prev;
        }
        //this->destroy<Doubly>(Head); // if not called in main(), call here
        return true;
    }
    // displays Doubly linked list, 'F' for forward iteration
    void display(Doubly* ptr, char direction = 'F') {
        Doubly* curr = ptr;
        direction = toupper(direction);
        while (curr) {
            std::cout << curr->data << ", ";
            if (direction != 'F')
                curr = curr->prev;
            else
                curr = curr->next;
        }std::cout << std::endl;
    }
};
/*
int main() {
    Solution l;
    ListNode* head = new ListNode(1, new ListNode(7, new ListNode(2, new ListNode(3))));
    std::cout << l.isPalindrome(head) << std::endl;

   /* Doubly* Head = NULL, * Tail = NULL;
    l.Dlist(head, &Head, &Tail);
    l.display(Head,'F');
    l.display(Tail, 'R');*/

    /* The destroy method needs to be applied correctly, or you can use
    smart pointers (unique_ptr<type> name = make_unique<type>(someVal), shared_ptr,
    weak_ptr)*/
    /*
        l.destroy<ListNode>(head);
        //l.destroy<Doubly>(Head);
        return 0;
    }
    */