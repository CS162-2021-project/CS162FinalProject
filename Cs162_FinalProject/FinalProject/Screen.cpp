#include <cassert>
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

void loadData(Year *& pYear) {
	ifstream yearIn("C:\\Github\\CS162FinalProject\\Data\\Year.txt");
	char *yearName = new char[51];
	while (yearIn >> yearName) {
		createNewYear(pYear, yearName, 0);

		Year* curYear = pYear;
		while(strcmp(curYear -> YearName, yearName) != 0)
			curYear = curYear -> yearNext;

		char dir[501] = "C:\\Github\\CS162FinalProject\\Data\\";
		strcat(dir, yearName);
		strcat(dir, "\\Class.txt");

 		ifstream classIn(dir);
		char *className = new char[51];
 		while (classIn >> className) {                                
 			createNewClass(curYear -> pClass, yearName, className, 0);
		
		    Class* curClass = curYear -> pClass;
		    while(strcmp(curClass -> ClassName, className) != 0)
		    	curClass = curClass -> classNext;
		    	        
			char dir_1[501] = "C:\\Github\\CS162FinalProject\\Data\\";
			strcat(dir_1, yearName);
			strcat(dir_1, "\\");
			strcat(dir_1, className);
			strcat(dir_1, "\\Student.txt");
 			ifstream studentIn(dir_1);

			char *s = new char[505];
			int t = 0;

			while(studentIn.getline(s, 505)) {
				Student * newStu = new Student;
              	int t = 0, n = strlen(s);
              	int pos = 0;
              	char *cur = new char[505];
              	for (int i = 0; i < n; i++) {
              		if (i == n - 1 || s[i] == ',') {
              			if (t == 0) {
              				newStu -> studentID = new char[pos + 10];
              				for (int j = 0 ; j < pos; j++)
              					newStu -> studentID[j] = cur[j];
              				newStu -> studentID[pos] = '\0';					
              			} 
              			else if (t == 1) {
              				newStu -> Name = new char[pos + 10];
              				for (int j = 0 ; j < pos; j++)
              					newStu -> Name[j] = cur[j];
              				newStu -> Name[pos] = '\0';
              			}
              			else if (t == 2) {
              				newStu -> DOB.year = (cur[0] - '0') * 1000 + (cur[1] - '0') * 100 + (cur[2] - '0') * 10 + (cur[3] - '0');
              				if (cur[6] != '-') {
	              				newStu -> DOB.month = (cur[5] - '0') * 10 + (cur[6] - '0');
	              				if (pos != 9)
		              				newStu -> DOB.day = (cur[8] - '0') * 10 + (cur[9] - '0');
		              			else
		              				newStu -> DOB.day = (cur[8] - '0');
							}
							else {
	              				newStu -> DOB.month = (cur[5] - '0');
	              				if (pos != 8)
		              				newStu -> DOB.day = (cur[7] - '0') * 10 + (cur[8] - '0');
		              			else
		              				newStu -> DOB.day = (cur[7] - '0');								
							}
              			}
              			else if (t == 3) {
							newStu -> gender = s[i] - '0';
              			}
              			t++;
              			pos = 0;
              		}
              		else 
              			cur[pos++] = s[i];
              	}
				addStudent(curClass -> pStudent, yearName, className, newStu, 0);
			}
 		}
	}
}

int chooseRoleScreen() {
	while(1) {
		cout << "Please input your choice: \n";
		cout << "0: Exit the programme\n";
		cout << "1: Access as a staff\n";
		cout << "2: Access as a student\n";

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}

		return respond[0] - '0';
	}
}

int yearScreen() {
	while(1) {
		cout << "Please input your choice Staff: \n";
		cout << "0: Logout\n";
		cout << "1: Create a new school year\n";
		char *s = new char[51];
		int cnt = 2;
		ifstream fIn("C:\\Github\\CS162FinalProject\\Data\\Year.txt");
		while(fIn >> s)
			cout << cnt++ << ": Access year " << s << '\n';
		delete[] s;
	
		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}

		return respond[0] - '0';
	}
}

void createYearScreen(Year *& pYear) {
	cout << "Please input the new school year name: \n";
	char *yearName = new char[101];
	cin >> yearName;
	createNewYear(pYear, yearName, 1);
	system("cls");
}

int classScreen(char* yearName) {
	char dir[101] = "C:\\Github\\CS162FinalProject\\Data\\";
	strcat(dir, yearName);
	strcat(dir, "\\Class.txt");
	while(1) {
		cout << "Year: " << yearName << "\n\n";

		cout << "Please input your choice: \n";
		cout << "0: Go back\n";
		cout << "1: Create a new class\n";
		char *s = new char[51];
		int cnt = 2;
		ifstream fIn(dir);
		while(fIn >> s)
			cout << cnt++ << ": Access class " << s << '\n';
		delete[] s;
	
		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}

		return respond[0] - '0';
	}
}

void createClassScreen(Class *& pClass, char * yearName) {
	cout << "Please input the new class name: \n";
	char *className = new char[101];
	cin >> className;
	createNewClass(pClass, yearName, className, 1);
	system("cls");
}

int studentScreen(Student * pStudent, char* yearName, char* className) {
	while(1) {
		char *s = new char[51];
		int cnt = 1, t = 0;
	
		cout << "Class: " << className << "\n\n";

		Student * curStudent = pStudent;
		while (curStudent != nullptr) {
			cout << cnt++ << ' ' << curStudent -> studentID << ' ' << curStudent -> Name << ' ' << ((curStudent -> gender) ? "Female" : "Male") << ' ' << 
					curStudent -> DOB.month << '/' << curStudent -> DOB.day << '/' << curStudent ->DOB.year << '\n';
			curStudent = curStudent -> studentNext;
		}	

		cout << "Please input your choice: \n";
		cout << "0: Go back\n";
		cout << "1: Create a new student\n";
		cout << "2: Add students through .csv file\n";
		cout << "3: View scoreboard of the class\n";
	
		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		return respond[0] - '0';
	}
}

void createStudentScreen(Student *& pStudent, char* yearName, char* className) {
	Student *newStu = new Student;
	inputStudent(newStu);
	addStudent(pStudent, yearName, className, newStu, 1);
}

void createStudentCSVScreen(Student *& pStudent, char* yearName, char* className) {
	cout << "Please drag the .csv file you wish to import into the directory CS162FinalProject\\Data\\File_csv\n";
	cout << "Also, please input the name of the file: ";
	char *csvFile = new char[101];
	cin >> csvFile;
	addStudentCSV(pStudent, csvFile, yearName, className, 1);
}                                                      