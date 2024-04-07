#include "Function_Module.h"
int main() {
	list L, p;
	sepratedata_by_all("Trial excel sheet containing folders.csv",&L,&p,40,244554, "By creation date");

	/*L.ls();
	cout << "\033[31";
	cout << "************************************************************************************************************************\n";
	cout << "\033[31;40m";
	p.ls();
	cout << "\033[0m\n";*/

	L.writeCSV("remaining_files");
	p.writeCSV("files_that_shiuld_be_deleted");
	openfile("files_that_shiuld_be_deleted");

	char x;
	cout << "press X to exit...\n\n";
	cin >> x;
	if (x == 'x')
		return 0;
	else return 0;
}