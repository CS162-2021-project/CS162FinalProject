#include <iostream>
#include <fstream>
#include <string.h>
#include "Header.h"
#include "Class.h"
#include "Course.h"
#include "Staff.h"
#include "Student.h"
#include "System.h"

using namespace std;

int chooseRoleScreen() {
	cout << "Please input your choice: \n";
	cout << "0: Exit the programme\n";
	cout << "1: Access as a staff\n";
	cout << "2: Access as a student\n";
	cout << "Your input: ";
	int respond; cin >> respond;
	system("cls");
	return respond;
}

int yearScreen() {
	ifstream fIn("C:\\Github\\CS162FinalProject\\Data\\Year.txt");
	cout << "Please input your choice Staff: \n";
	cout << "0: Logout\n";
	cout << "1: Create a new school year\n";
	char *s = new char[51];
	int cnt = 2;
	while(fIn >> s)
		cout << cnt++ << ": Access year " << s << '\n';
	delete[] s;

	cout << "Your input: ";
	int respond; cin >> respond;
	system("cls");
	return respond;
}

void createYearScreen(Year *& pYear) {
	cout << "Please input the new school year name: \n";
	char *yearName = new char[101];
	cin >> yearName;
	createNewYear(pYear, yearName);
	system("cls");
	cout << "Successfully creating the year " << yearName << "!\n";
}

int classScreen(Year *& curYear, char* yearName) {
	char dir[101] = "C:\\Github\\CS162FinalProject\\Data\\";
	strcat(dir, yearName);
	ifstream fIn(dir);
	cout << "Please input your choice: \n";
	cout << "0: Go back\n";
	cout << "1: Create a new class\n";
	char *s = new char[51];
	int cnt = 2;
	while(fIn >> s)
		cout << cnt++ << ": Access class " << s << '\n';
	delete[] s;

	cout << "Your input: ";
	int respond; cin >> respond;
	system("cls");
	return respond;
}

void createClassScreen(Class *& pClass, char * yearName) {
	cout << "Please input the new class name: \n";
	char *className = new char[101];
	cin >> className;
	createNewClass(pClass, yearName, className);
	system("cls");
	cout << "Successfully creating the class " << className << "!\n";
}

