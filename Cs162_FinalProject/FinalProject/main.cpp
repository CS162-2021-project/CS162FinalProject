#include <iostream>
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
			if (LogIn(1)) { // Login as a Staff
				while(true) { // Edit Year screen
					int respondYear = yearScreen();
					if (respondYear == 0) 
						break;
					else if (respondYear == 1) { // Create a School Year
						createYearScreen(pYear);	
					}
					else {
						// Access that year, might need to add a function to change password
						Year* curYear = pYear;
						int cntYear = 2;
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
	     											else if (respondEditCourse == 2) { // Delete the current course
														deleteCourse(curSemester -> pCourse, curYear -> YearName, curSemester -> SemesterName, curCourse -> id);
														break;
	     											}
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
			if (LogIn(2)) { // Login as a Student
				// To be coded
				int respondActivity = activityScreen();
				if (respondActivity == 0)
					break;
				else if (respondActivity == 1) { // Enroll in a course
					enrollCourseScreen();
				}
				else if (respondActivity == 2) { // View list of all enrolled courses
					// To be coded
				}
				else if (respondActivity == 3) { // View his/her scoreboard
					// To be coded
				}
			}
		}
		else
			cout << "Invalid, please try again\n\n";
	}
}