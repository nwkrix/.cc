/*
HASH TABLE CLASS IMPLEMENTATION BASED ON LINEAR PROBING (AN OPEN ADDRESSING METHOD);
SEP 4, 2021 CDMX 
AUTHOR: CHRISTIAN NWACHIOMA

*/

#include<iostream>
#include<string>
#include<cstring> // STRLEN(CONST CHAR* STR)
using namespace std;
#define TSIZE 5
#define EMAILSIZE 255
#define NAME_SIZE 255
struct club{ // data for hash table
	unsigned int id;
	const char name[NAME_SIZE];
	const char email[EMAILSIZE];
};
class Hasht{
	club *H_Table[TSIZE];
	public:
	Hasht(){for(int i = 0; i < TSIZE; i++){H_Table[i] = NULL;}} // can easily use if comparison// 
	bool isEmpty(){for(int i = 0; i < TSIZE; i++){if(this->H_Table[i] != NULL) return false;} return true; }
	unsigned int hashfcn(const char* email){
		unsigned int hashvalue = 0; 
		size_t len = strnlen(email,EMAILSIZE); 
		for(int i=0;i< len;i++){
			hashvalue += email[i]; 
			hashvalue = hashvalue * email[i]-1;
		} 
	return hashvalue % TSIZE;
	}
	bool insert(club *member){
		unsigned int key = hashfcn(member->email);
		for(int i = 0; i < TSIZE; i++){
			if( H_Table[(key + i) % TSIZE] == NULL ){
				H_Table[(key + i)%TSIZE] = member;
				return true;
			}
		}
		return false;
	}
	bool search(const char* email){
		unsigned int key = hashfcn(email);
		for (int i = 0; i < TSIZE; i++){
			if( H_Table[(i+key) % TSIZE] != NULL && strcmp(H_Table[(i+key) % TSIZE]->email,email)==0){
				return true;
			}
		}
		return false;
	}
	bool remove(club *member){
		unsigned int key = hashfcn(member->email);
		for(int i = 0; i < TSIZE; i++)
		{
			if(H_Table[(i + key) % TSIZE] != NULL && strcmp(H_Table[(i + key)%TSIZE]->email,member->email)==0){
				H_Table[ (key + i) % TSIZE] = NULL;
				return true;
			}
		}
		return false;
	}
	
	void print(){
		for(int i = 0; i < TSIZE; i++){
			if( H_Table[i] != NULL)
				cout << "\t" << i << "\t\t" << this->H_Table[i]->id << "\t" << this->H_Table[i]->name << "\t\t" << this->H_Table[i]->email << "\t\n";
			else
				cout << "\t" << i << "\t\t" << " _____ " << "\t" << " _____ " << "\t\t" << " _____ " << "\t\n";
		}
	}
};
int main()
{
	Hasht t;
	club member1 = {20216,"Matthew Oka", "oka@amazon.com"}, member2 = {11123, "Ken Camer", "ken@ipn.mx"}, member3 = {10012,"Yessica Susana Siordia VEga", "funky_princess@gmail.com"},
	member4 = {902939,"Godswill Ndukauba","zooboy@fct.abuja.ng"}, member5 = {943843,"Joyce Airemu Akhigbe","jaakyn@ymail.com"};
	t.insert(&member1); t.insert(&member2); t.insert(&member3); t.insert(&member4); t.insert(&member5);
	t.print();
	cout << t.search("ken@ipn.mx") << "\n";
	t.remove(&member2);
	t.print();
	cout << t.search("ken@ipn.mx") << "\n";
	return 0;
}