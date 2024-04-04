#include "Linked_list.h"

Linkedlist::Linkedlist() {
    size = 0;
    Header = NULL;
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