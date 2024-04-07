#include "Function_Module.h"

string x;bool goback;

int main() {
	cout << "\033[0m";
	list remain, bin;
	string file_location;

Input:

	int i = 0;
	cout << "Please input the file path in the formate of \\directory\\filename.extention :\n";
	while (bin.Size() == 0 && remain.Size() == 0) {

		if (i++) {
			cout << "Please input the file path :\n";
		}
		cout << "\033[0m";

		cin >> file_location;
		ifstream file(file_location);

		if (!file.is_open()) {
			const string msg = "Failed to open file: " + file_location + "\n";
			string description = "File not found.Please try again\nHere are the files in the present directory:\n";

			if (file_location == "." || file_location == "..") {
				description = "File not reachable.Please try not to go back in directory tree.\nHere are the files in the present directory:\n";
			}
			else {
				description = "File not found.Please try again\nHere are the files in the present directory:\n";
			}

			displayErrorMessage(msg, &description);
			cout << "\033[32m";
			system("dir");
			cout << "\033[0m\n\n";

		}
		else {

			file.close();
			int loopon = 1;
			string question= "Are you sure you want to open " + file_location + " file (\033[32mY\033[0m/\033[31mN\033[0m) : ";
			while (loopon) {
				loopon = get_choise(question);
				if (loopon == 0) goto selection;
				if(loopon==-1){
					cout << "\033[32m";
					system("dir");
					cout << "\033[0m\n\n";
					break;
				}
			}

		}
	}

selection:
	goback = false;


	
	
	
	
	
	
	sepratedata_by_access_count("sample\\sample.csv", &remain, &bin, 60);

	remain.writeCSV("remaining_files");
	bin.writeCSV("bin");
	//L.Display();
	//bin.Display();
	cout << "\033[32m";
	system("dir sample\\");
	cout << "\033[0m\n";
	remove_list(&bin, "sample");
	//bin.Display();
	//L.Display();
	cout << "\033[32m";
	system("dir sample\\");
	cout << "\033[0m\n";



	cout << "press X to exit...\n";
	cin >> x;
	if (x == "X")
		return 0;
	else return 0;
}