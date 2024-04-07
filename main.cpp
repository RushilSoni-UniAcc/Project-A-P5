#include "Function_Module.h"

char x;

int main() {
	list L, bin;
	string file_location;

	/*/while (bin.Size() == 0 && L.Size() == 0) {
		cout << "\033[0m";
		cout << "Please input the file path in the formate of \\directory\\filename.extention :\n";
		cin >> file_location;
		ifstream file(file_location);
		if (!file.is_open()) {
			const string msg = "Failed to open file: " + file_location + "\n";
			string description = "File not found or file was unreachable.Please try again\nHere are the files in the present directory:\n";
			displayErrorMessage(msg, &description);
			cout << "\033[32m";
			system("dir");
			cout << "\033[0m\n";
		}
		else {
			file.close();
			cout << "Are you sure you want to open " << file_location << " file (\033[32mY\033[0m/\033[31mN\033[0m) : ";
			cin >> x;
			if (x == 'y' || x == 'Y') break;
			else if (x == 'n' || x == 'N') continue;
		}
	}*/

	sepratedata_by_access_count("sample\\sample.csv", &L, &bin, 60);

	L.writeCSV("remaining_files");
	bin.writeCSV("bin");
	//L.Display();
	//bin.Display();
	cout << "\033[32m";
	system("dir sample\\");
	cout << "\033[0m\n";
	remove_list(&bin);
	//bin.Display();
	//L.Display();
	cout << "\033[32m";
	system("dir sample\\");
	cout << "\033[0m\n";



	cout << "press X to exit...\n";
	cin >> x;
	if (x == 'x')
		return 0;
	else return 0;
}