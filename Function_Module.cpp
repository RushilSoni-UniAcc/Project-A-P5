#include "Function_Module.h"

void displayErrorMessage(const string& message, const string* description) {
    string padding(20, ' ');

    cout << "\033[31m";
    cout << padding << message << "\n";
    cout << *description << "\n";
    cout << "\033[0m";
}

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

node* list::gethead() {
    return Header;
}

void Linkedlist::Display() {
    node* currant = Header;
    if (currant == nullptr) {
        return;
    }
    while (currant != nullptr) {
        cout << "\nName of the file                  : " << *currant->name<< "\n";
        cout << "number of Times accessed          : " << currant->access_count << "\n";
        cout << "Last date of access               : " << *currant->last_accessed_date << "\n";
        cout << "Last date of modification         : " << *currant->last_modificated_date << "\n";
        cout << "created file on                   : " << *currant->created_date << "\n";
        cout << "size of the file                  : " << currant->size_of_file << "\n";
        cout << "file location                     : " << *currant->URL << "\n\n";
        cout << "----------------------------------------" << "\n\n";
        currant = currant->next;
    }
}

int Linkedlist::Size() {
    return size;
}

void Linkedlist::Make_Empty() {
    node* current = Header;
    node* nextNode;

    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }

    Header = nullptr;
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

long formatted_createdate(node* file)
{
    int dd, mm, yyyy;
    long x;

    sscanf((*file->created_date).c_str(), "%d-%d-%d", &dd, &mm, &yyyy);

    x = (yyyy * 10000) + (mm * 100) + dd;
    return x;
}

long formatted_lastaccesseddate(node* file)
{
    int dd, mm, yyyy;
    long x;

    sscanf((*file->last_accessed_date).c_str(), "%d-%d-%d", &dd, &mm, &yyyy);
    
    x = (yyyy * 10000) + (mm * 100) + dd;
    return x;
}

long formatted_lastmodificateddate(node* file)
{
    int dd, mm, yyyy;
    long x;

    sscanf((*file->last_modificated_date).c_str(), "%d-%d-%d", &dd, &mm, &yyyy);

    x = (yyyy * 10000) + (mm * 100) + dd;
    return x;
}


bool is_redudant(node* file) {

    return 0;
}

bool is_old(node* file) {


    return 0;
}

bool is_empty__(node* file) {

    

    return 0;
}

bool is_low_accessed(node* file, int acc ) {

    if (file->access_count <= acc)
    {
        return true;
    }

    else {
        return false;
    }
}


bool IsValid(node* file, int acc) {

    if (is_redudant(file)) return false;

    else {
        if ( is_old(file) )return false;

        else {
            if (is_empty__(file)) return false;

            else {
                if (is_low_accessed(file,acc)) return false;

                else {
                    return true;
                }
            }
        }
    }

    return 0;

}

void readInputData(const string& file_path,list* validfiles,list* binfiles) {
    
    int filenumber = 0;


    ifstream file(file_path);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << "\n";
        const string msg = "Failed to open file: " + file_path + "\n";
        string description = "File not found.";
        displayErrorMessage(msg, &description);
        return;
    }

    string line;
    getline(file, line);


    while (getline(file, line)) {

        filenumber++;
        stringstream ss(line);
        string name, access_count_str, date_accessed, date_modified, date_created, size_str,URL;


        getline(ss, name, ',');
        getline(ss, access_count_str, ',');
        getline(ss, date_accessed, ',');
        getline(ss, date_modified, ',');
        getline(ss, date_created, ',');
        getline(ss, size_str, ',');
        getline(ss, URL);

        int access_count;
        long size__;
        try {
            access_count = stoi(access_count_str);
            size__ = stol(size_str);
        }
        catch (const invalid_argument& e) {
            string description = "Invalid File name : In the File " + to_string(filenumber) + " From top.\nPlease check that the file name is as required.";
            displayErrorMessage("Invalid File name", &description);
            validfiles->Make_Empty();
            binfiles->Make_Empty();
            break;
        }

        node* file_element = new node(name, access_count, date_accessed, date_modified, date_created,size__,URL);
        if (!IsValid(file_element,20)) {
            binfiles->Insert(file_element);
        }
        else {
            validfiles->Insert(file_element);
        }
    }
    
    file.close();
}