#ifndef _CLASS_H_
#define _CLASS_H_

#include <bits/stdc++.h>

// Create class

void createNewClass(Year*& pYear, char* yearName, char* className);

// Add Student

void addStudent(Student*& pStudent, char* yearName, char* className);

// Add student by CSV file

void addStudentCSV();

#endif