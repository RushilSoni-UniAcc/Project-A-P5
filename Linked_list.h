#pragma once
#include<iostream>
#include<ctime>
using namespace std;
struct node {
	string folder;
	string name;
	time_t created_date;
	int access_count;
	node* next;

	node(const string& folder, const string& name, time_t created_date, int access_count)
		: folder(folder), name(name), created_date(created_date), access_count(access_count), next(nullptr) {}
};

typedef class Linkedlist {
private:
	node* Header;
	int size;
public:
	Linkedlist();
	int Size();
	void Insert(node * element);

} list;