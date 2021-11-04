#include<iostream>
#include<unordered_map>
#include<map>
#include<utility>
using namespace std;
struct Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
    Node() : val(), next(nullptr), random(nullptr){}
};

class Solution {
public:
    void print(Node* head) {
        Node* ptr = head;
        while (ptr) {
            std::cout << ptr->val << ", ";
            ptr = ptr->next;
        }cout << endl;
    }
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        map<Node*, Node*> V;
        Node* n, *copy = nullptr, *copied = nullptr; 
        while (curr) {
            n = new Node(curr->val);
            if (!copy) {
                copy = n;
                copied = copy;
            }
            else {
                copy->next = n; 
                copy = n;
            }
            curr = curr->next;
        }
        curr = head; Node* go = copied;
        while (false) {
           
        }
        //go = copied;
        
        return copied;
    }
};
int main() {
    Solution l;
    Node* n0 = new Node(7);
    Node* n1 = new Node(13);
    Node* n2 = new Node(11);
    Node* n3 = new Node(10);
    Node* n4 = new Node(1);
    n0->next = n1; n0->random = nullptr;
    n1->next = n2; n1->random = n0;
    n2->next = n3; n2->random = n4;
    n3->next = n4; n3->random = n2;
    n4->next = nullptr; n4->random = n0;
    //[[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]
    l.print(n0);
    Node* copy = l.copyRandomList(n0);
    l.print(copy);
    //Node* a = n0->next;
    int b = n2->random->val;
    //cout << a << endl;
    //cout << b << endl;
    return 0;
}