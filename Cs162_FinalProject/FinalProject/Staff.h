#ifndef _STAFF_H_
#define _STAFF_H_

#include "Header.h"

void viewListOfCLasses(Year* pYear);

void viewStudentInfo(Student student);
void viewListOfStudentsInClass(Year* pYear, char* className);

void viewListOfStudentsInCourse (Student *pStuInCourse);
void ViewScoreboardOfCourse (Course *pCourse, char *courseID);


#endif // !_STAFF_H_
