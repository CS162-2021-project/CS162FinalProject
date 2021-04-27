#include <iostream>
#include <fstream>
#include <string.h>
#include "Class.h"

using namespace std;

void createNewClass(Class*& pClass, char* yearName, char* className, int add) {
	Class* cur = pClass;

	while (cur != nullptr) {
		if (strcmp(cur -> ClassName, className) == 0) {
			cout << "Failed to create a new class!!\n";
			cout << "The class you are about to create has already existed!!\n";
			system("pause");
			system("cls");
			return;
		}
		cur = cur -> classNext;
	}

	char dirD[] = "C:\\Github\\CS162FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, yearName);
	strcat(c, "\\Class.txt");

	ofstream fout;
	if (add)
		fout.open(c);

	cur = pClass;

	if (pClass == nullptr) {
		pClass = new Class;
		pClass -> ClassName = className;
		if (add)
			fout << pClass -> ClassName;
	}
	else {
		while (cur -> classNext != nullptr) {
			if (add)
				fout << cur -> ClassName << '\n';
			cur = cur -> classNext;
		}
		if (add)
			fout << cur -> ClassName << '\n';
		cur -> classNext = new Class;
		cur = cur -> classNext;
		cur -> ClassName = className;
		if (add)
			fout << cur -> ClassName;
	}
	if (add)
		fout.close();

	char d[500] = "mkdir ";
	strcat(d, dirD);
	strcat(d, yearName);
	strcat(d, "\\");
	strcat(d, className);
	system(d);
}