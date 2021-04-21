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
						// Ascess that year, might need to add a function to change password
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
							else if (respondClass == 1) { // Create a Class in this year
								createClassScreen(curYear -> pClass, curYear -> YearName);
							}
							else {           
								//Access that class
								Class* curClass = curYear -> pClass;
								int cntClass = 2;
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
			}
		}
		else
			cout << "Invalid, please try again\n\n";
	}
}