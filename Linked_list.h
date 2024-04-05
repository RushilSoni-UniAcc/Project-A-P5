#pragma once
#include<iostream>
using namespace std;
struct node {
	string name;
	string created_date;
	string last_accessed_date;
	string last_modificated_date;
	int access_count;
	node* next;

	node( const string& name, int access_count, string last_accessed_date, string last_modificated_date, string created_date)
		:  name(name), created_date(created_date), access_count(access_count), last_accessed_date(last_accessed_date), last_modificated_date(last_modificated_date), next(nullptr) {}
};

typedef class Linkedlist {
private:
	node* Header;
	int size;
public:
	Linkedlist();
	int Size();
	void Insert(node * element);
	void Display();
	~Linkedlist();

} list;