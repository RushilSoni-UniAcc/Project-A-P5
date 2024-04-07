#pragma once
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void displayErrorMessage(const string& message, const string* description);

struct node {
    string* name;
    string* created_date;
    string* last_accessed_date;
    string* last_modificated_date;
    int access_count;
    long size_of_file;
    string* URL;
    node* next;

    node(const string& name, int access_count, const string& last_accessed_date, const string& last_modificated_date, const string& created_date, long size_of_file, const string& URL)
        : access_count(access_count), size_of_file(size_of_file), next(nullptr) {
        this->name = new string(name);
        this->created_date = new string(created_date);
        this->last_accessed_date = new string(last_accessed_date);
        this->last_modificated_date = new string(last_modificated_date);
        this->URL = new string(URL);
    }

    ~node() {
        delete name;
        delete created_date;
        delete last_accessed_date;
        delete last_modificated_date;
        delete URL;
    }
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
	void ls();
	node* gethead();
	void Make_Empty();
    void writeCSV(const string& filename);
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

void readInputData(const string& file_path,list* validfile,list* binfile);

