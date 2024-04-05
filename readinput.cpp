#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

//https://www.youtube.com/watch?v=wRj9PZ2wyZI&t=57s 

using namespace std;

void readInputData(const string& file_path,) {
    ifstream file(file_path);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << file_path << endl;
        return;
    }

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string name, access_count, date_accessed,temp;
        
        
        getline(ss, name, ',');
        getline(ss, access_count, ',');
        getline(ss, date_accessed, ',');
        getline(ss, temp, ',');
        getline(ss, temp, ',');
        getline(ss, temp);

        cout << "Name of the file : " <<"\t\t"<< name << endl;
        cout << "number of Times accessed : " <<"\t"<< access_count << endl;
        cout << "Last date of access  : " << "\t\t"<<date_accessed << endl;
        cout<<endl<<"----------------------------------------"<<"\n\n";

    }

    file.close();
}

int main() {
    readInputData("Trial excel sheet containing folders.csv");
    return 0;
}
