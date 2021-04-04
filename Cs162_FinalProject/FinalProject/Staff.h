#ifndef _STAFF_H_
#define _STAFF_H_

#include<iostream>
#include<string>
using namespace std;

struct Schoolyear {

};

struct Date {
	int d;
	int m;
	int y;
};

struct Students {
	int ID;
	char* Firstname;
	char* Lastname;
	bool Gender; //true for boys false for girls
	Date DOB;
	int SocialID;
};

struct Classes {
	Students *students;
};

struct Schoolyear {
	Classes *classes;
};

struct Semester {
	Schoolyear schoolyear;
	Date start_date;
	Date end_date;
	Semester* pNext;
};



#endif // !_STAFF_H_
