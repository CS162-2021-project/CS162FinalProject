#ifndef _STUDENT_H_

#define _STUDENT_H_

#include "Header.h"

void enrollStudent(Course *& pCourse, Student *& pStudent, char* CourseID, char* StudentID, char * yearName, char * semesterName, int add);

void removeCourseInEnrollList(Course*& pEnrollCourse, char *yearName, char *semesterName, char* CourseID);

void viewEnrollList(Course* pEnrollCourse);

void viewScoreBoard(Course* pCourse, char* studentID); // task 26

#endif