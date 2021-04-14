#ifndef _CLASS_H_
#define _CLASS_H_

#include <bits/stdc++.h>
#include "header.h"

// Create class

void createNewClass(Class*& pClass, char* yearName, char* className);

// Add Student

void inputStudent(Student *&newStu);
void addStudent(Student*& pStudent, char* yearName, char* className);

// Add student by CSV file

void inputStudentCSV(Student *&newStu, char *s);
void addStudentCSV(Student*& pStudent);

#endif