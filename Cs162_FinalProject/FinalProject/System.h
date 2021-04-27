#ifndef _SYSTEM_H_

#define _SYSTEM_H_

#include "Header.h"

void loadData(Year *& pYear);

int chooseRoleScreen();
bool LogIn(int t, char *& studentID);
void changePassword(int t, char * username);

int yearScreen();
void createYearScreen(Year*& pYear);

int classScreen(char* yearName);
void createClassScreen(Class *& pClass, char* yearName);

int studentScreen(Student * pStudent, char* yearName, char* className);
void createStudentScreen(Student *& pStudent, char* yearName, char* className);
void createStudentCSVScreen(Student *& pStudent, char* yearName, char* className);

int semesterScreen(Semester *& pSemester);
void createSemesterScreen(Semester *& pSemester, char* yearName);

int courseScreen(Course *& pCourse, char* semesterName);
void addCourseScreen(Course *& pCourse, char* yearName, char* semesterName);

int editCourseScreen(Course *& curCourse);

int enrollSemesterScreen(Year *& pYeawr, char * studentID);
int enrollCourseScreen(char *semesterName);
int chooseCourse(Course *& pCourse);

int viewAndDeleteCourseScreen(Course *& pCourse, char * semesterName);
void deleteCourseScreen(Course * pCourse, Student * pStudent, char * yearName, char * semesterName, char * studentID);

#endif