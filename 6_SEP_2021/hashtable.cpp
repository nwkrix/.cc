#include<iostream>
#include<cstring>
#define EMAX 255
#define T_SIZE 10
using namespace std;
// data to store in hash table
struct amazon_employee{
	unsigned int id;
	const char name[100];
	const char email[EMAX];
};
class Hasht{
	amazon_employee* Table[T_SIZE];
public:
	Hasht(){
		for(int i = 0; i < T_SIZE; i++){
			Table[i] = NULL;
		}
	}
	bool isEmpty(){
		for(int i = 0; i < T_SIZE; i++){
			if(Table[i] != NULL) return true;
		}
		return false;
	}
	unsigned int hashfcn(const char* email){
		size_t len = strnlen(email,EMAX); 
		unsigned int hashNum = 0;
		for(int i = 0; i < len; i++){
			hashNum += email[i];
			hashNum *= email[i]; 
		}
		return hashNum % T_SIZE;
	}
	void insert(amazon_employee* s){
		unsigned int key = hashfcn(s->email);
		for(int i = 0; i < T_SIZE; i++){
			if(Table[(i+key)%T_SIZE] == NULL){
				Table[(i+key)] = s;
				return;
			}
		}
		cout << "No room for insertion. Increase T_SIZE";
	}
	bool search(const char* email){
		unsigned int key = hashfcn(email);
		for(int i = 0; i < T_SIZE; i++){
			if(Table[(key+i)%T_SIZE] != NULL && strncmp(Table[(i+key)%T_SIZE]->email,email,EMAX)==0){
				cout << "Found in slot " << (i+key) << endl;
				return true;
			}
		}
		return false;
	}
	void remove(const char* email){
		int key = hashfcn(email);
		for(int i = 0; i < T_SIZE; i++){
			if(Table[(i+key)%T_SIZE]!=NULL&&strncmp(Table[(i+key)%T_SIZE]->email,email,EMAX)==0){
				Table[(i+key)%T_SIZE] = NULL;
				return;
			}
		}
	}
	// utility function for displaying hashtable
	void display(){
		for(int i=0; i<T_SIZE; i++){
			if(Table[i] == NULL){
				printf("\t%i\t%s\t%s\n",i,"___","___");
			}else{
				printf("\t%i\t%s\t%s\n ",i, Table[i]->name,Table[i]->email);
			}
		}
	}
};

int main()
{
	Hasht t;
	amazon_employee e1 = {231, "Bushpie Daniel","dav@amazon.com"};
	amazon_employee e2 = {231, "George Fence Wood","dav@amazon.com"};
	amazon_employee e3 = {231, "Fernadi Jeng","Fernadi@tent.com"};
	t.insert(&e1);
	t.insert(&e2);
	t.insert(&e3);
	t.display();
	t.remove(e1.email);
	cout << "Display at deleting "<< e1.name << endl;
	t.display();
	cout << t.search(e1.email) << endl;
	return 0;
}