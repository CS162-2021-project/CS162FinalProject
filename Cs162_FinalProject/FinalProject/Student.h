#ifndef _STUDENT_H_

#define _STUDENT_H_

#include "Header.h"

void enrollStudent(Course *& pCourse, Student *& pStudent, char* CourseID, char* StudentID, char * yearName, char * semesterName, int add);
void removeCourseInEnrollList(Course *& pCourse, Student*& pStudnet, char *yearName, char *semesterName, char* CourseID, char *studentID);
void viewEnrollList(Course* pEnrollCourse, char * semesterName);

void viewScoreBoard(Course* pCourse, char* studentID); // task 26

#endif