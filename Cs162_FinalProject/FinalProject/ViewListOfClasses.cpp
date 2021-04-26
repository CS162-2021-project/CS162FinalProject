#include <string.h>
#include "Course.h"
#include "Header.h"
#include <iostream>

using namespace std;
void viewListOfCLasses(Year* pYear) {
	while (pYear) {
		cout <<"Year:"<< pYear->YearName << endl;
		while (pYear->pClass) {
			cout << pYear->pClass->ClassName << endl;
			pYear->pClass = pYear->pClass->classNext;
		}
		pYear = pYear->yearNext;
	}
}

