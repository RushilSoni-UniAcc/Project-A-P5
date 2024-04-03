#include "Linked_list.h"

Linkedlist::Linkedlist() {
    size = 0;
    Header->Link = nullptr;
}

Linkedlist::Linkedlist(int size, int arr[]) {
    this->size = size;
    Header->Link = new node;

    node* currant = Header->Link;
    for (int i = 0; i < size; i++) {
        if (i < size - 1) {
            currant->Link = new node;
            currant->Data = arr[i];
            currant = currant->Link;
        }
        else {
            currant->Data = arr[i];
            currant->Link = nullptr;
        }
    }
}

void Linkedlist::Displaylist() {
    if (Header->Link == nullptr) {
        std::cout << "The List is Empty";
    }
    else {
        node* currant = Header->Link;
        while (currant != NULL) {
            std::cout << currant->Data << " ";
            currant = currant->Link;
        }
    }
    std::cout << std::endl;
}

int Linkedlist::Size() {
    return size;
}

void Linkedlist::Insert(int position, double element) {
    if (position <= size + 1) {
        node* New = new node;
        New->Data = element;
        size++;
        node* previous = Header;
        for (int i = 1;i < position;i++) {
            previous = previous->Link;
        }
        New->Link = previous->Link;
        previous->Link = New;
    }
    else {
        std::cout << "Invalid position to insert the element into the list" << std::endl;
    }
}

void Linkedlist::Delete(int position) {
    if (position <= size) {
        node* currant = Header->Link;
        node* previous = Header;
        if (currant == nullptr) {
            std::cout << "List is empty.Cannot remove any element" << std::endl;
        }
        else {
            for (int i = 1;i < position;i++) {
                previous = previous->Link;
                currant = currant->Link;
            }
            previous->Link = currant->Link;
            delete currant;
            size--;
        }
    }
    else {
        std::cout << "Invalid position to Delete the element into the list" << std::endl;
    }
}

int Linkedlist::Find(int key) {
    node* currant = Header->Link;int index = 0;
    while (currant != NULL) {
        if (currant->Data == key) break;
        currant = currant->Link;
        index++;
    }
    if (index != size) return index + 1;
    else return -1;
}