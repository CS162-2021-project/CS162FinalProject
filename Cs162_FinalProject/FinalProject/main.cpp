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
						// Ascess that year
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
							cout << "Year: " << curYear -> YearName << "\n\n";

							int respondClass = classScreen(curYear, curYear -> YearName);
							if (respondClass == 0)
								break;
							else if (respondClass == 1) { // Create a Class in this year
								createClassScreen(curYear -> pClass, curYear -> YearName);
							}
							else {
								// To be coded;
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