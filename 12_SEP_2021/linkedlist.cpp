#include<iostream>
#include<string>
#include<cstring>
#define EMAX 200
#define T_SIZE 17
using namespace std;

struct Info{
	int id{};
	int age{};
	char name[100]{};
	string address;
	char email[EMAX];
};
struct Node{
	Info info;
	Node* next = NULL;
};
class linkedlist{
	Node* rootptr;
	Node* newNode(Info a){
		Node* node = new Node(); node->info = a; node->next = NULL;
		return node;
	}
public:
	linkedlist(){
		rootptr = NULL;
	}
	bool isEmpty(){
		return (rootptr == NULL);
	}
	unsigned int hashfcn(char* email){
		size_t len = strnlen(email,EMAX); 
		unsigned int hashval = 0;
		for(int i=0;i<len;i++){
			hashval += email[i];
			hashval *= email[i];
		}
		return hashval;
	}
	void Append(Info& info){ // Append(Node** root, Info& info)
		if(this->isEmpty()){
			info.id = hashfcn(info.email) % T_SIZE;
			rootptr = newNode(info);
			return;
		}
		Node* last = rootptr;
		while(last->next != NULL){
			last = last->next;
		}
		last->next = newNode(info);
	}
	void Prepend(Info& info){
		if(this->isEmpty()){
			rootptr = newNode(info);
			return;
		}
		Node* n = newNode(info);
		n->next = rootptr;
		rootptr = n;
	}
	//void remov()
	void display(){
		Node* current = rootptr;
		while(current != NULL){
			cout << current->info.id << "\t" << current->info.name << "\t" << current->info.age << "\t" << current->info.address << "\t" 
				 << current->info.email<< endl;
			current = current->next;
		}
	}
};
int main(){
	linkedlist obj = linkedlist();
	//int id;int age;char name[100];string address;
	Info a = {0,21,"Okere Yanni","1002 Classic Avenue, IA 5432, MA, USA","yanni@dats.mu"}, 
		 b =  {1,34,"Melissa Obama","989 Presidential White Whale, W. DC 1092, Columbia District, USA","melissa.whitehouse.us"},
		 c = {3,27,"Come First Matthew","709 Awolowo Street Agege, LA 900421, AB, NG","matthew.first@yahoo.com.ng"};
	obj.Append(a);
	obj.Append(b);
	obj.Prepend(c);
	//obj.display();
	return 0;
}