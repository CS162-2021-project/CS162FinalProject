#ifndef _COURSE_H_
#define _COURSE_H_

#include"Header.h"

// Create year

void createNewYear(Year*& pYear, char* yearName, int add);

// Create Semester

void createNewSemester(Semester*& pSemester, char* semesterName, char* yearName);

// Create Course

void addNewCourse(Course*& pCourse, char* semesterName, char* yearName);

//View list of all course available

void viewListOfCourse(Course* pCourse);

 // Delete Course

void deleteCourse (Course*& pHead, char *courseID);

// Update Course

void updateCourse (Course*& pHead , char* courseID);
  
#endif // !_COURSE_H_
