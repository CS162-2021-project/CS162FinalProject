#ifndef _STAFF_H_
#define _STAFF_H_

#include "Header.h"

void viewListOfCLasses(Year* pYear);

void viewStudentInfo(Student student);
void viewListOfStudentsInClass(Year* pYear, char* className);

void viewListOfStudentsInCourse (Student *pStuInCourse, char *courseID);
void ViewScoreboardOfCourse (Course *pCourse, char *courseID);

void exportStudentToCsv(Student* pStuInCourse, char *courseID);
#endif // !_STAFF_H_
