#include "Linked_list.h"

Linkedlist::Linkedlist() {
    size = 0;
    Header = NULL;
}


Linkedlist::~Linkedlist() {
    node* current = Header;
    while (current != nullptr) {
        node* temp = current;
        current = current->next;
        delete temp;
    }
}

void Linkedlist::Display() {
    node* currant = Header;
    if (currant == nullptr) {
        cout << "Empty list";
    }
    while (currant != nullptr) {
        cout << "Name of the file\t\t: " << currant->name<< "\n";
        cout << "number of Times accessed\t: " << currant->access_count << "\n";
        cout << "Last date of access\t\t: " << currant->last_accessed_date << "\n";
        cout << "Last date of modification\t: " << currant->last_modificated_date << "\n";
        cout << "created file on\t\t\t: " << currant->created_date << "\n\n";
        cout << "----------------------------------------" << "\n\n";
        currant = currant->next;
    }
}

int Linkedlist::Size() {
    return size;
}

void Linkedlist::Insert(node* element) {
    size++;
    if (Header == NULL) {
        Header = element;
    }
    else{
        node* currant = Header;
        while (currant->next != nullptr) {
            currant = currant->next;
        }
        currant->next = element;
    }
}