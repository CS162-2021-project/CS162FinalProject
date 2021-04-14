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
	int day;
	int month;
	int year;
};

struct Student
{
	char* username;
	char* password;
	char* studentID;
	char* Name;
	Date DOB;
	char* sClass;
	int gender; // 0 if male, 1 if female
	Course *pCourse = nullptr;
	Student *studentNext = nullptr;
};

struct listStudent {
	Student pStudent;
	Student* studentNext;
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
	Class *pClass;
	Semester *pSemester = nullptr;
	Year *yearNext = nullptr;
};

struct Semester {
	char *SemesterName;
	Course *pCourse = nullptr;
	Semester *semesterNext = nullptr;
};

struct dayPerformed {
	char d1[5]; // day
	char d2[5];
	char s1[5];	// shift
	char s2[5];
};

struct Course {
	char *id;
	char *name;
	char *lecturerName;
	int numberOfCredits;
	int maxStudent;
	dayPerformed date;
	Date startDate, endDate;
	Student* pStudent = nullptr;
	Course* courseNext = nullptr;
	Scoreboard* pScoreboard = nullptr;
};

#endif // !_HEADER_H_
