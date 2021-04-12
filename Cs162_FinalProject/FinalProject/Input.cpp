#include <bits/stdc++.h>

using namespace std;

int inputInterfare() {
	cout << "Please input a number to use the task that you would like to do:\n";
	cout << "1: Create a school year\n";
	cout << "2: Add a class, to a specific semester, to a specific year\n";
	cout << "3: Add new 1st year students to 1st year classes\n";
	cout << "4: Add new students by import a CSV file\n";
	cout << "6: Create a semester, to a specific year\n";
	cout << "8: Adding a course, to a specific semester, to a specific year\n";
	cout << "10: Update a course information\n";
	cout << "11: Delete a course\n";
	cout << "0: End the current program\n";
	cout << "Your input: ";
	int respond; cin >> respond;
	return respond;
}
