#include <sstream>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include "Header.h"
#include "Class.h"
#include "Course.h"
#include "Staff.h"
#include "Student.h"
#include "System.h"

using namespace std;

int chooseRoleScreen() {
	while(1) {
		cout << "Welcome to the HCMUS Course Registration system\n\n";

		cout << "Please input your choice: \n\n";
		cout << "0: Exit the programme\n\n";
		cout << "1: Access as a staff\n";
		cout << "2: Access as a student\n";

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete []respond;
		return x;
	}
}

int yearScreen() {
	while(1) {
		cout << "Please input your choice Staff: \n\n";
		cout << "0: Logout\n";
		cout << "1: Change password\n\n";
		cout << "2: Create a new school year\n\n";
		char *s = new char[51];
		int cnt = 3;
		ifstream fIn("C:\\Github\\CS162FinalProject\\Data\\Year.txt");
		while(fIn >> s)
			cout << cnt++ << ": Access year " << s << '\n';
		delete[] s;
	
		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
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

		cout << "Please input your choice: \n\n";
		cout << "0: Go back\n\n";
		cout << "1: Check all semesters and edit courses\n\n";
		cout << "2: Create a new class\n\n";
		char *s = new char[51];
		int cnt = 3;
		ifstream fIn(dir);
		while(fIn >> s)
			cout << cnt++ << ": Access class " << s << '\n';
		delete[] s;
	
		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
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
		cout << "Class: " << className << "\n\n";

		Student * curStudent = pStudent;
		while (curStudent != nullptr) {
	        cout << setw(12) << left << curStudent->studentID;
	        cout << setw(25) << left << curStudent->Name;
	        cout << setw(8) << left << ((curStudent->gender) ? "FEMALE" : "MALE");
	        cout << curStudent->DOB.day << "/" << curStudent->DOB.month << "/"  << curStudent->DOB.year << '\n';
			curStudent = curStudent -> studentNext;
		}	

		cout << '\n';

		cout << "Please input your choice: \n\n";
		cout << "0: Go back\n\n";
		cout << "1: Create a new student\n";
		cout << "2: Add students through .csv file\n";
		cout << "3: View scoreboard of the class\n";
	
		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}
}

void createStudentScreen(Student *& pStudent, char* yearName, char* className) {
	Student *newStu = new Student;
	inputStudent(newStu);
	addStudent(pStudent, yearName, className, newStu, 1);
}

void createStudentCSVScreen(Student *& pStudent, char* yearName, char* className) {
	cout << "Please drag the .csv file you wish to import into the directory CS162FinalProject\\Data\\Class_csv\n";
	cout << "Also, please input the name of the file (with the file name extension too, for example: 20CTT1_Student.csv): ";
	char *csvFile = new char[101];
	cin >> csvFile;
	system("cls");
	addStudentCSV(pStudent, csvFile, yearName, className, 1);
}

int semesterScreen(Semester *& pSemester) {
	while(1) {
		cout << "Please input your choice: \n\n";

		cout << "0: Go back\n\n";
		cout << "1: Create a new semester\n\n";

		int cnt = 2;
		Semester * pCur = pSemester;
		while (pCur != nullptr) {
			cout << cnt++ << ": Access semester " << pCur -> SemesterName << " (From " << pCur->startDate.month << '/' << pCur->startDate.day << '/' << pCur->startDate.year <<
				" to " << pCur->endDate.month << '/' << pCur->endDate.day << '/' << pCur->endDate.year << ")" << '\n';
			pCur = pCur -> semesterNext;
		}

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}
}                     

void createSemesterScreen(Semester *& pSemester, char *yearName) {
	cout << "Please input the new semester name: \n";
	char *semesterName = new char[51];
	cin >> semesterName;

	cout << "Please input the start date of the semester: \n";
	Date startDate;
	cout << "Year?: "; cin >> startDate.year;
	cout << "Month: "; cin >> startDate.month;
	cout << "Day?: "; cin >> startDate.day;

	cout << "Please input the end date of the semester: \n";
	Date endDate;
	cout << "Year?: "; cin >> endDate.year;
	cout << "Month: "; cin >> endDate.month;
	cout << "Day?: "; cin >> endDate.day;

	createNewSemester(pSemester, semesterName, yearName, startDate, endDate, 1);
	system("cls");
}

int courseScreen(Course *& pCourse, char * semesterName) {
	while(1) {
		cout << "Semester: " << semesterName << "\n\n";

		cout << "Please input your choice: \n\n";
		cout << "0: Go back\n\n";
		cout << "1: Create a course registration session\n";
		cout << "2: Add a new course\n";
		cout << "3: View list of courses\n\n";

		int cnt = 4;
		Course * pCur = pCourse;
		while (pCur != nullptr) {
			cout << cnt++ << ": Access course " << pCur -> id << '\n';
			pCur = pCur -> courseNext;
		}

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}	
}

void addCourseScreen(Course *& pCourse, char* yearName, char* semesterName) {
	Course * newCourse = new Course;
	                   
	cin.get();
    cout << "Please input the course ID: ";
    newCourse -> id = new char[101];
	cin.getline(newCourse -> id, 50);
    
    cout << "Please input the course name: ";
    newCourse -> name = new char[101];
	cin.getline(newCourse -> name, 50);

    cout << "Please input the course lecturer's name: ";
    newCourse -> lecturerName = new char[101];
	cin.getline(newCourse -> lecturerName, 50);

    cout << "Please input the number of credits: ";
    cin >> newCourse->numberOfCredits;

    cout << "Please input the maximal student: ";
    cin >> newCourse->maxStudent;
    cin.get();

    cout << "The session that the course will be performed (MON / TUE / WED / THU / FRI / SAT)" << endl;
    cout << "and shift S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30))" << endl;
    cout << "Please input 2 sessions :" << endl;
    newCourse -> date.d1 = new char[5];
    newCourse -> date.s1 = new char[5];
    newCourse -> date.d2 = new char[5];
    newCourse -> date.s2 = new char[5];
    cout << "Day 1: ";
	cin.getline(newCourse -> date.d1, 5);
    cout << "Shift 1: "; newCourse->date.s1;
	cin.getline(newCourse -> date.s1, 5);
    cout << "Day 2: ";
	cin.getline(newCourse -> date.d2, 5);
    cout << "Shift 2: "; newCourse->date.s1;
	cin.getline(newCourse -> date.s2, 5);
	addNewCourse(pCourse, semesterName, yearName, newCourse, 1);
	system("cls");
}

int editCourseScreen(Course *& curCourse) {
	while (true) {
		cout << "Course ID: " << curCourse -> id << '\n';
	    cout << "Course Name: " << curCourse -> name << '\n';
	    cout << "Lecturer Name: " << curCourse -> lecturerName << '\n';
		cout << "Number of Credit: " << curCourse -> numberOfCredits << '\n';
	    cout << "Occur in: " << curCourse -> date.d1 << " " << curCourse -> date.s1 << " and " << curCourse -> date.d2 << " " << curCourse -> date.s2 << '\n';
	    int cnt = 0;
	    Student* stuInCourse = curCourse -> pStudent;
	    while (stuInCourse != nullptr) {
	    	cnt++;
	    	stuInCourse = stuInCourse -> studentNext;
	    }
		cout << "Number of students registered: " << cnt << " / " << curCourse -> maxStudent << '\n';
  		cout << '\n';

  		cout << "Please input your choice: \n\n";
  		cout << "0: Go back\n\n";

  		cout << "1: Update this course information\n";
  		cout << "2: View list of students in this course\n";
  		cout << "3: View the scoreboard of this course\n\n";

  		cout << "4: Delete this course\n";

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}
}

int enrollSemesterScreen(Year *& pYear, char * studentID) {
	Student *curStudent = nullptr;
	Class * curClass = pYear -> pClass; 
	while (curStudent == nullptr && curClass != nullptr) {
		curStudent = curClass -> pStudent;
		while (curStudent != nullptr) {
			if (strcmp(curStudent -> studentID, studentID) == 0)
				break;
			curStudent = curStudent -> studentNext;
		}
		curClass = curClass -> classNext;
	}                                      


	while(1) {
		cout << "Student's ID: " << curStudent -> studentID << '\n';
		cout << "Student's Name: " << curStudent -> Name << '\n';
		cout << "Student's Gender: " << ((curStudent -> gender) ? "Female" : "Male") << '\n';
		cout << "Student's Day of Birth: " << curStudent -> DOB.month << '/' << curStudent -> DOB.day << '/' << curStudent -> DOB.year << "\n\n";

		cout << "Please input your choice: \n\n";

		cout << "0: Logout\n";   
		cout << "1: Change password\n\n";
		int cnt = 2;
		Semester * pCur = pYear -> pSemester;
		while (pCur != nullptr) {
			cout << cnt++ << ": Access semester " << pCur -> SemesterName << " (From " << pCur->startDate.month << '/' << pCur->startDate.day << '/' << pCur->startDate.year <<
				" to " << pCur->endDate.month << '/' << pCur->endDate.day << '/' << pCur->endDate.year << ")" << '\n';
			pCur = pCur -> semesterNext;
		}

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}				
}

int enrollCourseScreen(char *semesterName) {
	while(1) {
		cout << "Semester: " << semesterName << "\n\n";

		cout << "Please input your choice: \n\n";
		cout << "0: Go back\n\n";
		cout << "1: Enroll in a course\n";
		cout << "2: View list of your enrolled courses in this semester\n";
		cout << "3: View your scoreboard in this semester\n";

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}
}

int chooseCourse(Course *& pCourse) {
	while (1) {
		Course * pCur = pCourse;
	    while (pCur != nullptr) {
	        cout << "Course ID: " << pCur -> id << '\n';
	        cout << "Course Name: " << pCur -> name << '\n';
	        cout << "Lecturer Name: " << pCur -> lecturerName << '\n';
			cout << "Number of Credit: " << pCur -> numberOfCredits << '\n';
	        cout << "Occur in: " << pCur -> date.d1 << " " << pCur -> date.s1 << " and " << pCur -> date.d2 << " " << pCur -> date.s2 << '\n';
	        int cnt = 0;
	        Student* stuInCourse = pCur -> pStudent;
	        while (stuInCourse != nullptr) {
	        	cnt++;
	        	stuInCourse = stuInCourse -> studentNext;
	        }
			cout << "Number of students registered: " << cnt << " / " << pCur -> maxStudent << '\n';
			cout << '\n';
	
	        // move to next course
	        pCur = pCur -> courseNext;
	    }

	    cout << "Please input your choice: \n\n";
	    cout << "0: Go back\n\n";

	    int cnt = 1;
	    pCur = pCourse;
	    while (pCur != nullptr) {
	    	cout << cnt++ << ": Enroll in course " << pCur -> id << '\n';
	    	pCur = pCur -> courseNext;
	    }

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}
}

int viewAndDeleteCourseScreen(Course *& pCourse, char *semesterName) {
    while(1) {
		viewEnrollList(pCourse, semesterName);
		
		cout << "Please input your choice: \n\n";
		cout << "0: Go back\n\n";
		cout << "1: Unenroll a course\n";

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}
}

void deleteCourseScreen(Course * pCourse, Student * pStudent, char * yearName, char * semesterName, char * studentID) {
	cout << "Please input the ID of the course you want to unenroll: ";
	char * courseID = new char[101];
	cin >> courseID;
	cout << '\n';
	Course * tmpCourse = pCourse;
	while (tmpCourse) {
		if (strcmp(tmpCourse -> id, courseID) == 0)
			break;
		tmpCourse = tmpCourse -> courseNext;	
	}

	if (tmpCourse == nullptr) {
		cout << "There are no courses that match the course ID you just input!\n";
		system("pause");
		system("cls");
		return;
	}

	while (strcmp(pCourse -> id, courseID) != 0)
		pCourse = pCourse -> courseNext;

	
	removeCourseInEnrollList(pCourse, pStudent, yearName, semesterName, courseID, studentID);
}

void viewOrAddScoreBoard(Course *curCourse, char * yearName, char * semesterName) {
   	if (!curCourse -> pScoreboard) {
   		while (1) {
   			cout << "There is no scoreboard in this course yet.\n";
   			cout << "Do you want to import a scoreboard into this semester?\n\n";

   			cout << "Please input your choice: \n\n";

   			cout << "0: No\n";
   			cout << "1: Yes\n";

      		cout << "Your input: ";
      		char *respond = new char[101]; cin >> respond;
      		system("cls");
      		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
      			cout << "Invalid, please try again\n\n";
      			continue;
      		}

      		int x;
      		if (strlen(respond) == 1)
      			x = respond[0] - '0';
      		else
      			x = (respond[0] - '0') * 10 + (respond[1] - '0');
			delete[] respond;
      		if (x != 0 && x != 1) {
      			cout << "Invalid, please try again\n\n";
      			continue;
      		}	
      		if (x == 0) return;
			cout << "Please drag the scoreboard of the course in the format " << curCourse -> id << ".csv file into the folder C:\\Github\\CS162FinalProject\\Data\\Scoreboard_csv\\ \n\n";
			system("pause");
			system("cls");
   			addScoreBoardCSV(curCourse -> pScoreboard, yearName, semesterName, curCourse -> id);
   			break;
  		}
  	}
  	while (1) {
		viewScoreboardOfCourse(curCourse);

		cout << "Please input your choice: \n\n";

		cout << "0: Go back\n";
		cout << "1: Update a student result\n";
		cout << "Your input: ";
      	char *respond = new char[101]; cin >> respond;
      	system("cls");
      	if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
      		cout << "Invalid, please try again\n\n";
      		continue;
      	}

      	int x;
      	if (strlen(respond) == 1)
      		x = respond[0] - '0';
      	else
      		x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;

		if (x != 0 && x != 1) {
			cout << "Invalid, please try again\n\n";
			continue;
		}

		if (x == 0)
			break;
		else if (x == 1) {
			char *studentID = new char[51]; 
			cout << "Please input the Student's ID: ";
			cin >> studentID;
			updateScoreBoardStudent(curCourse -> pScoreboard, yearName, semesterName, curCourse -> id, studentID);
			delete[] studentID;
		}	
	}
}