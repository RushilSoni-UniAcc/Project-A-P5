#pragma once
#include<iostream>
struct node {
	std::string FileName;
	int NO_Timeaccess = 0;
	int date;/* create it in date class later*/
	int precedance;
	node* Link = (node*)malloc(sizeof(node));
};

typedef class Linkedlist {
private:
	node* Header;
	int size;
public:
	Linkedlist();
	Linkedlist(int size, int arr[]);
	int Size();
	void Displaylist();
	void Insert(int position, double element);
	void Delete(int position);
	int Find(int key);

} list;