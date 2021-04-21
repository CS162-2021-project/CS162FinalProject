#ifndef _CLASS_H_
#define _CLASS_H_

#include "Header.h"

// Create class

void createNewClass(Class*& pClass, char* yearName, char* className, int add);

// Add Student

void inputStudent(Student *&newStu);
void addStudent(Student*& pStudent, char* yearName, char* className, Student *& newStu, int add);

// Add student by CSV file

void inputStudentCSV(Student *&newStu, char *s);
void addStudentCSV(Student*& pStudent, char* CSV_Student_File, char* yearName, char* className, int add);

#endif