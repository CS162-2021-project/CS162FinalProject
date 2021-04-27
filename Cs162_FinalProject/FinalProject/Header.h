#ifndef _HEADER_H_
#define _HEADER_H_

struct Time;
struct Date;
struct Student;
struct Scoreboard;
struct Class;
struct Year;
struct Semester;
struct dayPerformed;
struct Course;

struct Time {
	int hours;
	int mins;
};

struct Date {
	int day = -1;
	int month = -1;
	int year = -1;
};

struct Student
{
	char* studentID;
	char* Name;
	Date DOB;
	char* sClass;
	int gender; // 0 if male, 1 if female
	bool **enrolledSession;
	Course *pCourse = nullptr;
	Student *studentNext = nullptr;
	Student () {
		enrolledSession = new bool* [8];
		for (int i = 0; i < 8; i++ ) {
			enrolledSession[i] = new bool[5];
			for (int j = 0; j < 5; j++)
				enrolledSession[i][j] = false;			
		}
	}
};

struct Scoreboard {
	Student stu;
	float midterm;
	float final;
	float bonus;
	float total;
	Scoreboard *scoreboardNext = nullptr;
};

struct Class {
	char *ClassName;
	Student *pStudent = nullptr;
	Class *classNext = nullptr; 
};

struct Year {
	char *YearName;
	Class *pClass = nullptr;
	Semester *pSemester = nullptr;
	Year *yearNext = nullptr;
};

struct Semester {
	char *SemesterName;
	Date startDate, endDate;
	Date startReg, endReg;
	Course *pCourse = nullptr;
	Semester *semesterNext = nullptr;
};

struct dayPerformed {
	char *d1; // day
	char *d2;
	char *s1; // shift
	char *s2;
};

struct Course {
	char *id;
	char *name;
	char *lecturerName;
	int numberOfCredits;
	int maxStudent;
	dayPerformed date;
	Student* pStudent = nullptr;
	Course* courseNext = nullptr;
	Scoreboard* pScoreboard = nullptr;
};

#endif // !_HEADER_H_
