#ifndef _COURSE_H_
#define _COURSE_H_

#include<iostream>
#include<fstream>
#include"Header.h"

// Input interfare

int inputInterfare();

// Create year

void Create_New_Year(Year*& pHead, int& n, char* year);

// Create Semester

void createNewSemester(Year*& pHead, int& n, char* semester, char* year);

// Create class

void createNewClass(Year*& pHead, int& n, char* semester, char* year, char* className);

// Create Course

void addNewCourse(Course*& pHead, int& n, char* semester, char* year);

// Delete Course
 
void deleteCourse (Course*& pHead, char *courseID);

// Update Course

void updateCourse (Course*& pHead);
  
#endif // !_COURSE_H_
