#ifndef _STUDENT_H_

#define _STUDENT_H_

#include "Header.h"

void enrollStudent(Course *& pCourse, Student *& pStudent, char* CourseID, char* StudentID, Date RegisterDate);

void viewScoreBoard(Course* pCourse, char* studentID); // task 26

#endif