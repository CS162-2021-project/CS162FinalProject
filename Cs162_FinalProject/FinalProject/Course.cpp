#include <bits/stdc++.h>
#include<string.h>
#include "Course.h"
#include "Header.h"

using namespace std;

void Create_New_Year(Year*& pHead, int& n, char* year) {
	ofstream fout;
	fout.open("E:\\GitHub\\CS162FinalProject\\Data\\year.txt");

	Year* pCur = pHead;
	n += 1;
	fout << n << endl;
	if (pHead == nullptr) {
		pHead = new Year;
		pHead->years = year;
		pHead->pNext = nullptr;
		fout << pHead->years;
	}
	else {
		while (pCur != nullptr) {
			fout << pCur->years << endl;
			pCur = pCur->pNext;
		}
		pCur = new Year;
		pCur->years = year;
		fout << pCur->years;
		pCur->pNext = nullptr;
	}
	fout.close();

	char dirD[] = "E:\\GitHub\\CS162FinalProject\\Data\\";
	char c[500] = "mkdir ";
	strcat(c, dirD);
	strcat(c, year);
	system(c);
	
	strcat(c, "\\semester.txt");

	fout.open(c);
	fout << 0;
	fout.close();
}

void createNewSemester(Year*& pHead, int& n, char* semester, char* year)
{
	char dirD[] = "E:\\Github\\CS162FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	strcat(c, "\\semester.txt");

	ofstream fout;
	fout.open(c);

	Year* cur = pHead;
	n += 1;
	fout << n << endl;
	if (pHead == nullptr) {
		pHead = new Year;
		pHead->semesters = semester;
		pHead->pNext = nullptr;
		fout << pHead->semesters;
	}
	else {
		while (cur != nullptr) {
			fout << cur->semesters << endl;
			cur = cur->pNext;
		}
		cur = new Year;
		cur->semesters = semester;
		fout << cur->semesters;
		cur->pNext = nullptr;
	}
	fout.close();

	char d[500] = "mkdir ";
	strcat(d, dirD);
	strcat(d, year);
	strcat(d, "\\");
	strcat(d, semester);
	system(d);

	strcat(d, "\\class.txt");
	fout.open(d);
	fout << 0;
	fout.close();
}

void createNewClass(Year*& pHead, int& n, char* semester, char* year, char* className)
{
	char dirD[] = "E:\\Github\\CS162FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	strcat(c, "\\");
	strcat(c, semester);
	strcat(c, "\\class.txt");

	ofstream fout;
	fout.open(c);

	Year* cur = pHead;
	n += 1;
	fout << n << endl;

	if (pHead == nullptr) {
		pHead = new Year;
		pHead->className = className;
		pHead->pNext = nullptr;
		fout << pHead->className;
	}
	else {
		while (cur != nullptr) {
			fout << cur->className << endl;
			cur = cur->pNext;
		}
		cur = new Year;
		cur->className = className;
		fout << cur->className;
		cur->pNext = nullptr;
	}
	fout.close();

	char d[500] = "mkdir ";
	strcat(d, dirD);
	strcat(d, year);
	strcat(d, "\\");
	strcat(d, semester);
	strcat(d, "\\");
	strcat(d, className);
	system(d);
}

void addNewCourse(Course*& pHead, int& n, char* semester, char* year) {
	char dirD[] = "E:\\Github\\CS162FinalProject\\Data\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, year);
	strcat(c, "\\");
	strcat(c, semester);
	strcat(c, "\\course.txt");

	//

	ofstream fout;
	fout.open(c , std::ios_base::app);
	if (fout.is_open()) {
		n += 1;
		fout << n << endl;
		Course* pCur = pHead;
		if (!pHead) {
			pHead = new Course;
			pCur = pHead;
		}
		else {
			while (pCur->pNext) {
				pCur = pCur->pNext;
			}
			pCur->pNext = new Course;
			pCur = pCur->pNext;
		}
		// get info
		cin.ignore(1001, '\n');
		cin.get(pCur->id, 101, '\n');
		fout << pCur->id << endl;

		cin.ignore(1001, '\n');
		cin.get(pCur->name, 101, '\n');
		fout << pCur->name << endl;

		cin.ignore(1001, '\n');
		cin.get(pCur->lecturerName, 101, '\n');
		fout << pCur->lecturerName << endl;

		cin >> pCur->numberOfCredits;
		fout << pCur->numberOfCredits << endl;
        
		cin >> pCur->maxStudent;
		fout << pCur->maxStudent << endl;

		cout << " the session that the course will be performed (MON / TUE / WED / THU / FRI / SAT)" << endl;
		cout << " and shift S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30))" << endl;
		cout << "Please input 2 sesstions :" << endl;
		cin >> pCur->date.d1 >> pCur->date.s1;
		cin >> pCur->date.d2 >> pCur->date.s2;
		fout << pCur->date.d1 << ' ' << pCur->date.s1 << endl;
		fout << pCur->date.d2 << ' ' << pCur->date.s2 << endl;
	}
	fout.close();
}


void deleteCourse (Course*& pHead, char *courseID) {
    if (pHead->id == courseID) {
        Course *pDel = pHead;
        pHead = pHead->pNext;
        delete pDel;
    } else {
        Course *pCur = pHead;
        while (pCur->pNext && pCur->pNext->id != courseID) {
            pCur = pCur->pNext;
        }
        Course *pDel = pCur->pNext;
        pCur->pNext = pDel->pNext;
        delete pDel;
    }
}

void updateCourse (Course*& pHead) {
    cout << "Please enter the course ID that you want to update: ";
    char ID[101];
    cin.ignore(1001, '\n');
    cin.get(ID, 101, '\n');
    Course *pCur = pHead;
    while (pCur && pCur->id != ID) {
        pCur = pCur->pNext;
    }
    
    cout << "Choose 1 of these functions:";
    cout << "1. Course ID" << endl;
    cout << "2. Course name" << endl;
    cout << "3. Lecturer name" << endl;
    cout << "4. Number of credits" << endl;
    cout << "5. Max students" << endl;
    cout << "6. Session and Shifts" << endl;
    cout << "which information you want to update?" << endl;
    int x;
    cin >> x;
    
    
    if (x == 1) {
        cout << "New course ID:" ;
        cin.ignore(1001, '\n');
        cin.get(pCur->id, 101, '\n');
    } else if (x == 2) {
        cout << "New course name:" ;
        cin.ignore(1001, '\n');
        cin.get(pCur->name, 101, '\n');
    } else if (x == 3) {
        cout << "New lecturer name:" ;
        cin.ignore(1001, '\n');
        cin.get(pCur->lecturerName, 101, '\n');
    } else if (x == 4) {
        cout << "New number of credits:" ;
        cin >> pCur->numberOfCredits;
    } else if (x == 5) {
        cout << "New max students:" ;
        cin >> pCur->maxStudent;
    } else {
        cout << "New day 1 and shift 1:";
        cin >> pCur->date.d1 >> pCur->date.s1;
        cout << "New day 2 and shift 2:";
        cin >> pCur->date.d2 >> pCur->date.s2;
    }
}

void viewListOfCourse(Course* pHead) {
	while (pHead) {
		cout << "Course ID and Name:" << pHead->id << " " << pHead->name;
		cout << "Occur in :" << pHead->date.d1 << pHead->date.s1 << " ";
		cout << pHead->date.d2 <<pHead->date.s2 << endl;

		// move to next course
		pHead = pHead->pNext;
	}
}

// a course registration session is active,student can do :

void registrationSession() {
	cout << "You have to log in to the system first:";
	// Login to the system
	int n;
	cout << "Choose one of these function:" << endl;
	cout << "1.Enroll in a course." << endl;
	cout << "2.View list of enrolled courses." << endl;
	cout << "3.Remove a course from the enrolled list." << endl;
	cout << "Which one you want to do ? Please input a number:";
	cin >> n;
	switch(n)
	{
	case 1 : //enroll in a course
		break;
	case 2 : //List of enrolled student
		break;
	case 3 : // remove course
		break;
	default:
		break;
	}
}

void enrollInACourse(Course* pHead , Course*& pEnrolledCourse) {
	char ID[101];
	int cnt = 0;
	cout << "Course available:" << endl;
	viewListOfCourse(pHead);
	cout << "PLease input the ID of Course in which you want to enroll :";
	cin.ignore(1001, '\n');
	cin.get(ID, 101, '\n');	


	
}