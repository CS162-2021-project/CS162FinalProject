#include <bits/stdc++.h>

using namespace std;

int inputInterfare() {
	cout << "Please input a number to use the task that you would like to do:\n";
	cout << "1: Create a school year\n";
	cout << "2: Add a class, to a specific semester, to a specific year\n";
	cout << "6: Create a semester, to a specific year\n";
	cout << "0: End the current program\n";
	cout << "Your input: ";
	int respond; cin >> respond;
	return respond;
}
