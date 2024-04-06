#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Function_Module.h"
int main() {
	list L, p;
	readInputData("Trial excel sheet containing folders.csv",&L,&p);
	L.Display();
	cout << "\033[31m";
	cout << "************************************************************************************************************************\n";
	p.Display();
	cout << "\033[0m";
	return 0;
}