#ifndef _COURSE_H_
#define _COURSE_H_

#include"Header.h"

// Create year

void createNewYear(Year*& pYear, char* yearName, int add);

// Create Semester

void createNewSemester(Semester*& pSemester, char* semesterName, char* yearName, Date startDate, Date endDate, int add);

// Create Course registration session

void courseRegistration(Semester *& pSemester);

// Create Course

void addNewCourse(Course*& pCourse, char* semesterName, char* yearName, Course *& newCourse, int add);

//View list of all course available

void viewListOfCourse(Course * pCourse);

 // Delete Course

void deleteCourse (Course*& pCourse, char* yearName, char* semesterName, char* courseID);

// Update Course

void updateCourse (Course*& pCourse, char* yearName, char* semesterName, char* courseID);

  
#endif // !_COURSE_H_
