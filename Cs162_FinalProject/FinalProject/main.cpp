#include <iostream>
#include <string.h>
#include "Header.h"
#include "Class.h"
#include "Course.h"
#include "Staff.h"
#include "Student.h"
#include "System.h"

using namespace std;

int main() {
	//Input interface

	Year* pYear = nullptr;
	loadData(pYear);
	system("cls");

	cout << "Welcome to the HCMUS Course Registration system\n\n";

	while(true) { // Basic screen, choose which role to login
		int respondRole = chooseRoleScreen();
		if (respondRole == 0) 
			break;
		else if (respondRole == 1) {
			char * filler;
			if (LogIn(1, filler)) { // Login as a Staff
				while(true) { // Edit Year screen
					int respondYear = yearScreen();
					if (respondYear == 0) 
						break;
					else if (respondYear == 1) { // Change password
						// To be coded
					}	
					else if (respondYear == 2) { // Create a School Year
						createYearScreen(pYear);	
					}
					else {
						// Access that year, might need to add a function to change password
						Year* curYear = pYear;
						int cntYear = 3;
						while (curYear != nullptr && cntYear < respondYear) {
							curYear = curYear -> yearNext;
							cntYear++;
						}
						if (curYear == nullptr || cntYear < respondYear) {
							cout << "Invalid, please try again\n\n";
							continue;
						}	

						while(true) { // Edit Class screen
							int respondClass = classScreen(curYear -> YearName);
							if (respondClass == 0)
								break;       
							else if (respondClass == 1) { 
								while (true) { // Check all semesters
									int respondSemester = semesterScreen(curYear -> pSemester);
									
									if (respondSemester == 0)
										break;
									else if (respondSemester == 1) { // Create a new Semester in this year
										createSemesterScreen(curYear -> pSemester, curYear -> YearName);	
									}
									else {
     									// Access that semester
     									Semester* curSemester = curYear -> pSemester;
     									int cntSemester = 2;
     									while (curSemester != nullptr && cntSemester < respondSemester) {
     										curSemester = curSemester -> semesterNext;
     										cntSemester++;
     									}
     									if (curSemester == nullptr || cntSemester < respondSemester) {
     										cout << "Invalid, please try again\n\n";
     										continue; 
     									}

     									while (true) { // Edit Course screen  
     										int respondCourse = courseScreen(curSemester -> pCourse, curSemester -> SemesterName);

     										if (respondCourse == 0)
     											break;
     										else if (respondCourse == 1) { // Create a course registration session
												courseRegistration(curSemester);												     											
     										}	
     										else if (respondCourse == 2) { // Add a course to this semester
     											addCourseScreen(curSemester -> pCourse, curYear -> YearName, curSemester -> SemesterName);
     										}
     										else if (respondCourse == 3) {	// View the details of all the courses
     											viewListOfCourse(curSemester -> pCourse);
     										}
											else {
												// Access that Course
												
												int cntCourse = 4;
												Course *curCourse = curSemester -> pCourse;
												while (curCourse != nullptr && cntCourse < respondCourse) {
													curCourse = curCourse -> courseNext;
													cntCourse++;
												}
												if (curCourse == nullptr || cntCourse < respondCourse) {
     												cout << "Invalid, please try again\n\n";
		     										continue;
												}

     											while (true) { // Edit the current course
	     											int respondEditCourse = editCourseScreen(curCourse);
	     											if (respondEditCourse == 0) {
    	 												break;
	     											}
	     											else if (respondEditCourse == 1) { // Update course information
														updateCourse(curSemester -> pCourse, curYear -> YearName, curSemester -> SemesterName, curCourse -> id);
	     											}
	     											else if (respondEditCourse == 2) { // View list of students in this course
	     												// To be coded
	     											}
	     											else if (respondEditCourse == 3) { // Delete the current course
														deleteCourse(curSemester -> pCourse, curYear -> YearName, curSemester -> SemesterName, curCourse -> id);
														break;
	     											}
	     											else 
	     												cout << "Invalid, please try again\n\n";
												}
											}
     									}
     								}
								}
							}
							else if (respondClass == 2) { // Create a Class in this year
								createClassScreen(curYear -> pClass, curYear -> YearName);
							}                         
							else {           
								//Access that class
								Class* curClass = curYear -> pClass;
								int cntClass = 3;
								while (curClass != nullptr && cntClass < respondClass) {
									curClass = curClass -> classNext;
									cntClass++;
								}
								if (curClass == nullptr || cntClass < respondClass) {
									cout << "Invalid, please try again\n\n";
									continue;
								}

								while (true) { // Edit Student Screen
									int respondStudent = studentScreen(curClass -> pStudent, curYear -> YearName, curClass -> ClassName);
									if (respondStudent == 0)
										break;
									else if (respondStudent == 1) { // Create a new student in this class
										createStudentScreen(curClass -> pStudent, curYear -> YearName, curClass -> ClassName);
									}	
									else if (respondStudent == 2) { // Add students through .csv file
										createStudentCSVScreen(curClass -> pStudent, curYear -> YearName, curClass -> ClassName);										
									}
									else if (respondStudent == 3) {	// View scoreboard of a class
										// To be coded
									}
								}
							}
						}	
					}
				}	
			}
		}
		else if (respondRole == 2) {
			char * studentID;
			if (LogIn(2, studentID)) { // Login as a Student
				while (true) {  // Choose a semester to enroll
    				char * yearName = new char[51];
    				int tmp = (studentID[0] - '0') * 10 + studentID[1] - '0';
    				char tmp_c[40];
    				strcat(yearName, "20");
    				strcat(yearName, itoa(tmp, tmp_c, 10));
    				strcat(yearName, "-20");
    				strcat(yearName, itoa(tmp + 1, tmp_c, 10));

    				Year * curYear = pYear;
    				while (curYear && strcmp(curYear -> YearName, yearName) != 0)
    					curYear = curYear -> yearNext;
    						
    				int respondSemester = enrollSemesterScreen(curYear, studentID);
    				if (respondSemester == 0)
    					break;
    				else if (respondSemester == 1) {// Change password
    					// To be coded
    				}						
    				else {
         				// Access that semester
       					Semester* curSemester = curYear -> pSemester;
       					int cntSemester = 2;
       					while (curSemester != nullptr && cntSemester < respondSemester) {
       						curSemester = curSemester -> semesterNext;
       						cntSemester++;
       					}
       					if (curSemester == nullptr || cntSemester < respondSemester) {
       						cout << "Invalid, please try again\n\n";
       						continue; 
       					}

       					while (true) {
       						int respondCourse = enrollCourseScreen();

       						if (respondCourse == 0)
       							break;
       						else if (respondCourse == 1) { // Choose a course to enroll
       							// To be coded
       						}	
       						else if (respondCourse == 2) { // View list of enrolled course
       							// To be coded
       						}
       						else if (respondCourse == 3) { // View scoreboard in this semester
       							// To be coded
       						}
       					}
    				}
				}
			}
		}
		else
			cout << "Invalid, please try again\n\n";
	}
}