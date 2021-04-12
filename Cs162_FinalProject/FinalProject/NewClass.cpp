#include <bits/stdc++.h>
#include "Class.h"

using namespace std;

void createNewClass(Class*& pClass, char* yearName, char* className) {
	char dirD[] = "C:\\Github\\CS162FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, yearName);
	strcat(c, "\\class.txt");

	ofstream fout;
	fout.open(c);

	Class* cur = pClass;

	if (pClass == nullptr) {
		pClass = new Class;
		pClass -> ClassName = className;
		pClass -> classNext = nullptr;
		fout << pClass -> ClassName;
	}
	else {
		while (cur -> classNext != nullptr) {
			fout << cur -> ClassName << endl;
			cur = cur -> classNext;
		}
		cur -> classNext = new Class;
		cur = cur -> classNext;
		cur -> ClassName = className;
		fout << cur -> ClassName;
		cur -> classNext = nullptr;
	}
	fout.close();

	char d[500] = "mkdir ";
	strcat(d, dirD);
	strcat(d, yearName);
	strcat(d, "\\");
	strcat(d, className);
	system(d);
}