#ifndef _HEADER_H_
#define _HEADER_H_

struct Time {
	int hours;
	int mins;
};

struct Date {
	int day;
	int month;
	int year;
};

struct Scoreboard {
	Student stu;
	float midterm;
	float final;
	float bonus;
	float total;
	Scoreboard *scoreboardNext;
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
};

struct Class {
	char *ClassName;
	Student *pStudent;
	Class *classNext; 
};

struct Year {
	char *YearName;
	Class *pClass;
	Semester *pSemester;
	Year *yearNext;
};

struct dayPerformed {
	char d1[5];
	char d2[5];
	char s1[5];
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
	Course* pNext = nullptr;
};

#endif // !_HEADER_H_
