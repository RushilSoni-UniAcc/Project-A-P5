void writeCSV(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Error: Unable to open file " << filename << endl;
            return;
        }

        file << "Name,Time,Count,Length" << endl;
        Node* temp = head;
        while (temp != nullptr) {
            file << temp->name << "," << temp->time << "," << temp->count << "," << temp->length << endl;
            temp = temp->next;
        }
        file.close();
    }