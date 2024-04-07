#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Function_Module.h"
int main() {
	list L, p;
	readInputData("Trial excel sheet containing folders.csv",&L,&p);
	L.ls();
	cout << "\033[31";
	cout << "************************************************************************************************************************\n";
	cout << "\033[31;40m";
	p.ls();
	cout << "\033[0m\n";
	return 0;
}