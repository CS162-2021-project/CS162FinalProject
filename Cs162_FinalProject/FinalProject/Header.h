#ifndef _HEADER_H_
#define _HEADER_H_

struct Time {
	int hours;
	int mins;
};

struct Year {
	char* years;
	char* semesters;
	char* className;
	Year* pNext;
};

struct student {
	char* account;
	char* password;
	char* name;
	char* dob;
	char* className;
	int gender;
	int isActive;
};

struct Date {
	int day;
	int month;
	int year;
};

struct Student
{
	char* userName;
	char* password;
	char* ID;
	char* sName;
	Date DOB;
	char* sClass;
	int gender; // 1 if female
};

struct checkin {
	bool w[10];
};


struct staff {
	char* account;
	char* password;
	char* name;
	int gender;
};

struct score {
	float midterm;
	float final;
	float bonus;
	float total;
};

struct scoreboard {
	student* stu;
	int isActive;
	score* sco;
	int went2class[10];
};

struct lecture {
	char* account; //username
	char* password;
	char* name;
	char* academy;
	int gender;
};

struct schedule {
	int no;
	char* courseID;
	char* courseName;
	char* Class;
	lecture* lec;
	Date Sdate;
	Date Edate;
	char* dayofweek;
	Time Stime;
	Time Etime;
	char* room;
};

struct Node {
	student* stu;
	scoreboard* scb;
	schedule* schedule;
	Node* next = nullptr;
};

struct StuNode
{
	Student stu;
	StuNode* pNext = nullptr;
};

struct dayPerformed {
	char d1[5];
	char d2[5];
	char s1[5];
	char s2[5];
};

struct Course {
	char id[101];
	char name[101];
	char lecturerName[101];
	int numberOfCredits;
	int maxStudent;
	dayPerformed date;
	Course* pNext = nullptr;
};

#endif // !_HEADER_H_
