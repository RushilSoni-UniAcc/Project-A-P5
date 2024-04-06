#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void displayErrorMessage(const string& message, const string* description);

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
	void Make_Empty();
	~Linkedlist();

} list;

long formatted_createdate(node* file);
long formatted_lastaccesseddate(node* file);
long formatted_lastmodificateddate(node* file);

bool is_redudant(node* file);
bool is_old(node* file);
bool is_empty__(node* file);
bool is_low_accessed(node* file, int acc);

bool IsValid(node* file, int acc);




list readInputData(const string& file_path,list* validfile);

