#include "Linked_list.h"

Linkedlist::Linkedlist() {
    size = 0;
    Header = NULL;
}


Linkedlist::~Linkedlist() {
    FileNode* current = head;
    while (current != nullptr) {
        FileNode* temp = current;
        current = current->next;
        delete temp;
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