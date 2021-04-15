#include <bits/stdc++.h>

#include "Header.h"
#include "Student.h"

using namespace std;

void enrollStudent(Course *& pCourse, Student *& pStudent, char* CourseID, char* StudentID, Date RegisterDate) { 
	Course *curCourse = pCourse;
	while (curCourse && strcmp(curCourse -> id, CourseID) != 0) {
		curCourse = curCourse -> courseNext;
	}

	Student *curStudent = pStudent;
	while (curStudent && strcmp(curStudent -> studentID, StudentID) != 0) {
		curStudent = curStudent -> studentNext;
	}


	if (!((curCourse -> startDate.year <= RegisterDate.year) && (curCourse -> startDate.month <= RegisterDate.month) && (curCourse -> startDate.day <= RegisterDate.day) &&
		(RegisterDate.year <= curCourse -> endDate.year) && (RegisterDate.month <= curCourse -> endDate.month) && (RegisterDate.day <= curCourse -> endDate.day))) {
			cout << "The registration phase has expired, cannot enrolled\n";
			return;
		}
	
	int d1, d2, s1, s2;

	if (strcmp(curCourse -> date.d1, "MON") == 0) d1 = 2;
	else if (strcmp(curCourse -> date.d1, "TUE") == 0) d1 = 3;
	else if (strcmp(curCourse -> date.d1, "WED") == 0) d1 = 4;
	else if (strcmp(curCourse -> date.d1, "THU") == 0) d1 = 5;
	else if (strcmp(curCourse -> date.d1, "FRI") == 0) d1 = 6;
	else if (strcmp(curCourse -> date.d1, "SAT") == 0) d1 = 7;
	s1 = (curCourse -> date.s1)[1] - '0';

	if (strcmp(curCourse -> date.d1, "MON") == 0) d1 = 2;
	else if (strcmp(curCourse -> date.d1, "TUE") == 0) d1 = 3;
	else if (strcmp(curCourse -> date.d1, "WED") == 0) d1 = 4;
	else if (strcmp(curCourse -> date.d1, "THU") == 0) d1 = 5;
	else if (strcmp(curCourse -> date.d1, "FRI") == 0) d1 = 6;
	else if (strcmp(curCourse -> date.d1, "SAT") == 0) d1 = 7;
	s2 = (curCourse -> date.s2)[1] - '0';

	if (curStudent -> enrolledSession[d1][s1] || curStudent -> enrolledSession[d2][s2]) {
		cout << "The current course has  sessions that are conflict with existing enrolled course sessions, cannot enrolled\n";
		return;
	}
	
	int sz_enroll = 0;
	Course* enrollCourse = curStudent -> pCourse;
	while (enrollCourse) {
		sz_enroll++;
		enrollCourse = enrollCourse -> courseNext;
	}
	if (sz_enroll >= 5) {
		cout << "The student has already enrolled in 5 courses, cannot enrolled\n";
		return;
	}

	int sz_student = 0;
	Student* stuInCourse = curCourse -> pStudent;
	while(stuInCourse) {
		sz_student++;
		stuInCourse = stuInCourse -> studentNext;
	}
	if (sz_student >= curCourse -> maxStudent) {
		cout << "The course is already full, cannot enrolled\n";
		return;
	}
		
	curStudent -> enrolledSession[d1][s1] = true;
	curStudent -> enrolledSession[d2][s2] = true;

	enrollCourse = curStudent -> pCourse;
	while (enrollCourse -> courseNext)
		enrollCourse = enrollCourse -> courseNext;
	enrollCourse -> courseNext = new Course;
	enrollCourse = enrollCourse -> courseNext;
	enrollCourse -> id = curCourse -> id;
	enrollCourse -> name = curCourse -> name;
	enrollCourse -> date = curCourse -> date;

	stuInCourse = curCourse -> pStudent;
	while(stuInCourse -> studentNext)
		stuInCourse = stuInCourse -> studentNext;
	stuInCourse -> studentNext = new Student;
	stuInCourse = stuInCourse -> studentNext;
	stuInCourse -> studentID = curStudent -> studentID;
	stuInCourse -> Name = curStudent -> Name;
	stuInCourse -> DOB = curStudent -> DOB;
	stuInCourse -> sClass = curStudent -> sClass;
	stuInCourse -> gender = curStudent -> gender;
}