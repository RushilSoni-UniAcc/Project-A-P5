#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Function_Module.h"
int main() {
	list L, p;
	p = readInputData("Trial excel sheet containing folders.csv",&L);
	L.Display();
	return 0;
}