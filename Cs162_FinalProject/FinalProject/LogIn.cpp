#include<bits/stdc++.h>
#include "System.h"
#include "Header.h"

using namespace std;

bool LogIn(){
	char ad[200];
	ifstream fin;
	bool login = false;
	bool StillLog = true;
	strcat(ad, "E:\\Github\\CS162FinalProject\\Data\\Account.txt");
	
	while(!login || StillLog){
		int x;
		cout << "You want to log in? (1) means yes/(0) means no";
		cin >> x;
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
				cout << "You have logged in " << endl;
				login = true;
				break;
			}
		}
	}
	
	if(login == true) return true;
	return false;
}


