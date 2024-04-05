#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Linked_list.h"


using namespace std;
static int filenumber = 0;
void readInputData(const string& file_path ,Linkedlist* list) {
    ifstream file(file_path);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << "\n";
        return;
    }
    string line;
    getline(file, line);
    while (getline(file, line)) {
        filenumber++;
        stringstream ss(line);
        string name, access_count_str, date_accessed, date_modified, date_created, temp;


        getline(ss, name, ',');
        getline(ss, access_count_str, ',');
        int access_count;
        try {
            access_count = stoi(access_count_str);
        }
        catch (const std::invalid_argument& e) {
            cerr << "Invalid access count : In the File "<< filenumber <<" From top.\n"<<"Please check that the file name is as required.";
            delete list;
            continue;
        }
        getline(ss, date_accessed, ',');
        getline(ss, date_modified, ',');
        getline(ss, date_created, ',');
        getline(ss, temp);


        node* X = new node(name,access_count,date_accessed,date_modified,date_created);
        list->Insert(X);
        
        

    }

    file.close();
}

int main() {
    Linkedlist list;
    readInputData("Trial excel sheet containing folders.csv",&list);
    list.Display();
    return 0;
}