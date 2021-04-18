#include<bits/stdc++.h>
#include "System.h"
#include "Header.h"

using namespace std;

bool LogIn(int t){
	char ad[200] = "";
	ifstream fin;
	bool login = false;
	bool StillLog = true;

	if (t == 1)
		strcat(ad, "C:\\Github\\CS162FinalProject\\Data\\Account_staff.txt");
	else if (t == 2)
		strcat(ad, "C:\\Github\\CS162FinalProject\\Data\\Account_student.txt");			
	
	while(!login || StillLog){
		int x;
		cout << "Do you want to log in as a " << ((t == 1) ? "Staff" : "Student") << " ?\n";
		cout << "0: Go back\n";
		cout << "1: Log in\n";
		cin >> x;
		system("cls");
		if(x == 0){
			StillLog = false;
			break;
		}
		char Username[101]; char Password[101];
		cout << "Please input Username: ";
		cin >> Username;
		cout << "Please input Password: ";
		cin >> Password;
		fin.open(ad);
		char name[101], pass[101];
		while(fin >> name && fin >> pass){
			if(strcmp(name,Username) == 0 && strcmp(pass, Password) == 0){
				system("cls");
				cout << "You have logged in!\n\n";
				login = true;
				break;
			}
		}
		if (login)
			break;
		system("cls");
		cout << "Wrong username or password, please try again.\n\n";
	}
	return login;
}