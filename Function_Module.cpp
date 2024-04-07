#include "Function_Module.h"

long saved_memory = 0;


void displayErrorMessage(const string& message, const string* description) {//function for error mesages.

    cout << "\n\n\033[91m";
    cout <<  message;
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

void Linkedlist::ls() {
    node* currant = Header;
    if (currant == nullptr) {
        return;
    }
        cout << "\n     last access time\taccessed               length\tName of the file\n";
        cout << "\n     ----------------\t--------               ------\t--------------------------------\n";
    while (currant != nullptr) {
        cout << "     "<< * currant->last_accessed_date << "\t  " << currant->access_count << "     \t       " << currant->size_of_file << "\t" << *currant->name<< "\n";
        currant = currant->next;
    }
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
int Linkedlist::Size() { return size ;}

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
node* Linkedlist::remove(string name){
    node* currant = Header->next;
    node* previous = currant;
    if (*previous->name == name) {
        size--;
        Header = currant;
        return previous;
    }

    while (previous!= nullptr) {
        if (*currant->name == name) {
            size--;
            previous->next = currant->next;
            return currant;
        }
        previous = currant;
        currant = currant->next;
    }
    return nullptr;
}
bool Linkedlist::Find_redundant(int key) {
    node* currant = Header;
    while (currant != nullptr) {
        if (currant->size_of_file == key) break;
        currant = currant->next;
    }
    if (currant!=nullptr) return true;
    else return false;
}
bool Linkedlist::search(string name ) {
    node* currant = Header;
    while (currant != nullptr) {
        if (*(currant->name) == name) {
            return true;
        }
        currant = currant->next;
    }
    return false;
}
node* Linkedlist::gethead() {
    return Header;
}
void Linkedlist::writeCSV(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        const string msg = "Error: Unable to open file " + filename;
        string description = "There was an error in creating the CSV file it may have to do with system settings.Please check the settings after that run the program";
        displayErrorMessage(msg, &description);
        return;
    }

      cout   << "----------------------------------------" << "\n\n";
    node* currant = Header;
    while (currant != nullptr) {
        file << "\nName of the file                  : " << *currant->name << "\n"
         << "number of Times accessed          : " << currant->access_count << "\n"
         << "Last date of access               : " << *currant->last_accessed_date << "\n"
         << "Last date of modification         : " << *currant->last_modificated_date << "\n"
         << "created file on                   : " << *currant->created_date << "\n"
         << "size of the file                  : " << currant->size_of_file << "\n"
         << "file location                     : " << *currant->URL << "\n\n"
         << "----------------------------------------" << "\n\n";
        currant = currant->next;
    }
    file.close();
}

long formatted_createdate(node* file)
{
    int dd, mm, yyyy;
    long x;

    sscanf_s((*file->created_date).c_str(), "%d-%d-%d", &dd, &mm, &yyyy);

    x = (yyyy * 10000) + (mm * 100) + dd;
    return x;
}

long formatted_lastaccesseddate(node* file)
{
    int dd, mm, yyyy;
    long x;

    sscanf_s((*file->last_accessed_date).c_str(), "%d-%d-%d", &dd, &mm, &yyyy);
    
    x = (yyyy * 10000) + (mm * 100) + dd;
    return x;
}

long formatted_lastmodificateddate(node* file)
{
    int dd, mm, yyyy;
    long x;

    sscanf_s((*file->last_modificated_date).c_str(), "%d-%d-%d", &dd, &mm, &yyyy);

    x = (yyyy * 10000) + (mm * 100) + dd;
    return x;
}

void remove_redundant(node * file,list* list) {
    node* currant = list->gethead();
    while (currant != nullptr) {
        if (list->Find_redundant(file->size_of_file)) {
            if (remove(file->name->c_str()) != 0) {
                string description = "Error deleting a file: In the File " + (*file->URL) + "\nPlease check that the file.";
                displayErrorMessage("Error deleting a file", &description);
                exit(0);
            }
            else {
                saved_memory += file->size_of_file;
            }
        }
        currant = currant->next;
    }
    return ;
}

bool is_old(node* file,long date,string methode) {

    if (methode == "By creation date") {
        if (formatted_createdate(file) < date) {
            return true;
        }
        else return false;
    }

    if (methode == "By modification date") {
        if (formatted_lastmodificateddate(file) < date) {
            return true;
        }
        else return false;
    }

    if (methode == "By access date") {
        if (formatted_lastaccesseddate(file) < date) {
            return true;
        }
        else return false;
    }

    return false;
}
bool is_empty__(node* file) {

    if (file->size_of_file == 0) return true;

    return false;
}
bool is_low_accessed(node *file,int acc) {

    if (file->access_count < acc) return true;

        
    return false;
}
bool IsValid(node* file, int acc,long date, string methode) {
        if ( is_old(file,date, methode) )return false;

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

void sepratedata_by_all(const string& file_path,list* validfiles,list* binfiles,int min_acc,long min_date, string methode) {
    
    int filenumber = 0;


    ifstream file(file_path);
    if (!file.is_open()) {
        const string msg = "Failed to open file: " + file_path + "\n";
        string description = "File not found.";
        displayErrorMessage(msg, &description);exit(0);
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
            binfiles->Make_Empty();exit(0);
            break;
        }

        node* file_element = new node(name, access_count, date_accessed, date_modified, date_created,size__,URL);
        if (!IsValid(file_element, min_acc,min_date,methode)) {
            binfiles->Insert(file_element);
        }
        else {
            validfiles->Insert(file_element);
        }
    }
    
    file.close();
}
void sepratedata_by_empty(const string& file_path, list* validfiles, list* binfiles) {

    int filenumber = 0;


    ifstream file(file_path);
    if (!file.is_open()) {
        const string msg = "Failed to open file: " + file_path + "\n";
        string description = "File not found.";
        displayErrorMessage(msg, &description);exit(0);
        return;
    }

    string line;
    getline(file, line);


    while (getline(file, line)) {

        filenumber++;
        stringstream ss(line);
        string name, access_count_str, date_accessed, date_modified, date_created, size_str, URL;


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
            binfiles->Make_Empty();exit(0);
            break;
        }

        node* file_element = new node(name, access_count, date_accessed, date_modified, date_created, size__, URL);
        if (is_empty__(file_element)) {
            binfiles->Insert(file_element);
        }
        else {
            validfiles->Insert(file_element);
        }
    }

    file.close();
}
void sepratedata_by_date(const string& file_path, list* validfiles, list* binfiles,long date,string methode) {

    int filenumber = 0;


    ifstream file(file_path);
    if (!file.is_open()) {
        const string msg = "Failed to open file: " + file_path + "\n";
        string description = "File not found.";
        displayErrorMessage(msg, &description);
        exit(0);
        return;
    }

    string line;
    getline(file, line);


    while (getline(file, line)) {

        filenumber++;
        stringstream ss(line);
        string name, access_count_str, date_accessed, date_modified, date_created, size_str, URL;


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
            exit(0);
            break;
        }

        node* file_element = new node(name, access_count, date_accessed, date_modified, date_created, size__, URL);
        if (is_old(file_element,date,methode)) {
            binfiles->Insert(file_element);
        }
        else {
            validfiles->Insert(file_element);
        }
    }

    file.close();
}
void sepratedata_by_access_count(const string& file_path, list* validfiles, list* binfiles, int min_acc) {

    int filenumber = 0;


    ifstream file(file_path);
    if (!file.is_open()) {
        const string msg = "Failed to open file: " + file_path + "\n";
        string description = "File not found.";
        displayErrorMessage(msg, &description);
        exit(0);
        return;
    }

    string line;
    getline(file, line);


    while (getline(file, line)) {

        filenumber++;
        stringstream ss(line);
        string name, access_count_str, date_accessed, date_modified, date_created, size_str, URL;


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
            exit(0);
            break;
        }

        node* file_element = new node(name, access_count, date_accessed, date_modified, date_created, size__, URL);
        if (is_low_accessed(file_element, min_acc)) {
            binfiles->Insert(file_element);
        }
        else {
            validfiles->Insert(file_element);
        }
    }

    file.close();
}

long get_saved_memory() {
    return saved_memory;
}

void correction(string file_name, list* bin, list* valid)
{
    cout << bin->remove(file_name);
    node* file_node = bin->remove(file_name);
    if (file_node != nullptr) {
        cout << *file_node->name;
        valid->Insert(file_node);
    }
    else {
        string description = "Invalid File name : The file " + file_name + " is not in the bin list.Please make sure that you give correct File name in the input.";
        displayErrorMessage("Invalid File name", &description);
    }
}




void remove_list(list* bin,string directory) {
    node* currant = bin->gethead();
    while (currant != nullptr) {
        saved_memory+=currant->size_of_file;
        string element = directory+"\\" + *currant->name;
        remove(element.c_str());
        currant = currant->next;
    }
}

void remove_list(list* bin) {
    node* currant = bin->gethead();
    while (currant != nullptr) {
        saved_memory += currant->size_of_file;
        string element =   *currant->name;
        remove(element.c_str());
        currant = currant->next;
    }
}