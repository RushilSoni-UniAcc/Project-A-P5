#include "Function_Module.h"

string x;
int loopon ;
int get_choise(string question) {
	cout << question;
	cin >> x;
	if (x.length() > 0) {
		char X = x[0];
		if (X == 'y' || X == 'Y') {
			return  0;
		}
		else if (X == 'n' || X == 'N') {
			return -1;
		}
	}
	return 1;
}

int main() {
	cout << "\033[0m";
	list remain, bin;
	string file_location;

Input:
	{

		int i = 0;
		if (!i) cout << "Please input the file path in the formate of \\directory\\filename.extention :\n";
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
				loopon = 1;
				string question = "Are you sure you want to open " + file_location + " file (\033[32mY\033[0m/\033[31mN\033[0m) : ";
				while (loopon) {
					loopon = get_choise(question);
					if (loopon == 0) goto selection;
					else if (loopon == -1) {
						cout << "\033[32m";
						system("dir");
						cout << "\033[0m\n\n";
						break;
					}
				}

			}
		}
	}
selection:
	{

		system("cls");
		loopon = 1;
		while (loopon != 0) {
			loopon = get_choise("Do you want to go back to Input your file once again?(\033[32mY\033[0m/\033[31mN\033[0m) : ");
			if (loopon == 0) {
				goto Input;
			}
			else if (loopon == -1) break;
		}

	start:
		cout << "On which basis do you want to clean your file :\n";
		cout << "1) remove Redundant files \n";
		cout << "2) remove old files \n";
		cout << "3) remove empty files \n";
		cout << "4) remove low access files \n";
		cout << "5) according to all of the above  \n";
		cout << "now select according to any of the above :\n";
		cout << "(Note : you can make two choices later on so don't worry about it)\n";

		int i = 0;int min_acc = 0;string date_str;
		cin >> i;
		if (i > 5 || i < 1) goto start;
		switch (i) {
		case 5: {
			cout << "Give the minimun nmber of access :\n(Note: anything which has less access count than minimum access count will be removed)\n";
			cin >> min_acc;
			cout << "Plese enter the date from before you want to delete files(in dd-mm-yyyy) : ";
			cin >> date_str;
			int dd, mm, yyyy;
			long date;

			sscanf_s(date_str.c_str(), "%d-%d-%d", &dd, &mm, &yyyy);

			date = (yyyy * 10000) + (mm * 100) + dd;
			sepratedata_by_all(file_location, &remain, &bin, min_acc, date, "By creation date");
			break;
		}


		case 2: {
			cout << "Plese enter the date from before you want to delete files(in dd-mm-yyyy) : ";
			cin >> date_str;
			int dd, mm, yyyy;
			long date;

			sscanf_s(date_str.c_str(), "%d-%d-%d", &dd, &mm, &yyyy);

			date = (yyyy * 10000) + (mm * 100) + dd;
			sepratedata_by_date(file_location, &remain, &bin, date, "By creation date");
			break;
		}
		case 4: {
			cout << "Give the minimun nmber of access :\n(Note: anything which has less access count than minimum access count will be removed)\n";
			cin >> min_acc;
			sepratedata_by_access_count(file_location, &remain, &bin, min_acc);
			break;
		}
		case 3: {
			sepratedata_by_empty(file_location, &remain, &bin);
			break;
		}

		case 1: {
			sepratedata_by_empty(file_location, &remain, &bin);
			break;
		}
		}


	}


correction:
	{
		system("cls");
		loopon = 1;
		while (loopon != 0) {
			loopon = get_choise("Do you want to go back to Selection Display once again?(\033[32mY\033[0m/\033[31mN\033[0m) : ");
			if (loopon == 0) {
				goto selection;
			}
			else if (loopon == -1) break;
			else continue;
		}
		cout << "\033[31m";
		bin.ls();
		cout << "\033[0m \n\n";
		if (bin.gethead() == nullptr) {
			cout << "there are no files which are empty in " + file_location + "\n";
			cout << "terminating the programme";
			clock_t start_time = clock();
			while ((clock() - start_time) / CLOCKS_PER_SEC < 3);
			exit(0);
		}
		else {
			cout << "The above files are the ones which will be deleted after this step :\n";
			loopon = 1;
			while (loopon != 0) {
				loopon = get_choise("Do you want to make changes in this bin file?(\033[32mY\033[0m/\033[31mN\033[0m) : ");
				if (loopon == 0) {
					cout << "Please enter the name of the file which you want to restore : ";
					string file_name;
					cin >> file_name;
					correction(file_name, &bin, &remain);
				}
				else if (loopon == -1) break;
			};
			goto confirmation;
		}
	}
	confirmation:
		{
		system("cls");
		loopon = 1;
		while (loopon != 0) {
			loopon = get_choise("Do you want to go back to give input once again? If yes then you will be sent to Selection Display? (Y/N) : ");
			if (loopon == 0) {
				goto Input;
			}
			else if (loopon == -1) break;
			else continue;
		}

			cout << "\033[31m";
			bin.ls();
			cout << "\033[0m \n\n";
			string question = "Are you sure you want to remove all the files in " + file_location + " file which are mentioned above? (Y/N) : ";
			loopon = get_choise(question);
			if (loopon == 0) {
				remove_list(&bin);
				cout << "\033[32m";
				cout << "Successfully removed all the files that you have asked for.";
				system("dir");
				cout << "\033[0m\n\n";
				clock_t start_time = clock();
				while ((clock() - start_time) / CLOCKS_PER_SEC < 3);
			}
		}

		system("cls");
		loopon = 1;
		while (loopon != 0) {
		loopon = get_choise("Do you want to continue to delete or finished? (Y/N) : ");
			if (loopon == 0) {
				goto Input;
			}
			else if (loopon == -1) break;
			else break;
		}
		cout << "\033[32m";
		cout << "memory saved from this execution is equal to : ";
		cout << get_saved_memory();
		cout << "\033[0m\n\n";
		bin.writeCSV("Previously_Deleted_File");
		remove("currant_folder");
		remain.writeCSV("currant_folder");
	cout << "Press any letter to exit the program...\n";
	char c;cin >> c;
	return 0;
}