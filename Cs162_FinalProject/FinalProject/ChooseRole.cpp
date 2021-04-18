#include <bits/stdc++.h>
#include "System.h"
#include "Header.h"

using namespace std;

int chooseRole() {
	cout << "Please input your choice: \n";
	cout << "0: Exit the programme\n";
	cout << "1: Access as a staff\n";
	cout << "2: Access as a student\n";
	cout << "Your input: ";
	int respond; cin >> respond;
	system("cls");
	return respond;
}