#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* link;
};
class linkedlist{
    Node *head;
    Node* newnode(int data)
    {
        Node* new_node = new Node(); new_node->data = data; new_node->link = NULL;
        return new_node;
    }
    public:
    linkedlist(){
        head = NULL;
    }
    ~linkedlist(){}//delete this
    void Append(int data)
    {
        if(head == NULL)
        {
            head = newnode(data);
            return;
        }
        Node* tmp = head;
        while(tmp->link != NULL)
        {
            tmp = tmp->link;
        }
        tmp->link = newnode(data);
    }
    void print()
    {
        if(head == NULL)
        {
            cout << "List Empty\n";
            return;
        }
        Node *tmp = head; 
        while(tmp != NULL)
        {
            cout << tmp->data << ", ";
            tmp = tmp->link;
        }
        cout << endl;
    }
};

int main()
{
    linkedlist *h = new linkedlist();
    h->print(); 
    h->Append(5); h->Append(6); h->Append(8);
    h->print();
    return 0;
}