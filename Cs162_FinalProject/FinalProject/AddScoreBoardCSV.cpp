#include<iosteam>
#include<fstream>
#include"Staff.h"
#include"Header.h"

using namespace std;

void inputScoreboardCSV(Scoreboard *& newScr , char *s) {
	int t = 0, n = strlen(s);
	char *cur = new char[50], 
	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || s[i] == ',') {
			if (t == 0) {
				//Do nothing
			}
			else if (t == 1) {
				newScr -> stu -> studentID = new char[pos + 10];
				for (int i = 0 ; i < pos; i++)
					newScr -> stu -> studentID[i] = cur[i];
				newScr -> stu -> studentID[pos] = '\0';					
			} 
			else if (t == 2) {
				newScr -> stu -> Name = new char[pos + 10];
				for (int i = 0 ; i < pos; i++)
					newScr -> stu -> Name[i] = cur[i];
				newScr -> stu -> Name[pos] = '\0';
			}
			else if (t == 3) {
				newScr -> midterm = atof(cur[0]);
			}
			else if (t == 4) {
				newScr -> final = atof(cur[0]); 
			}
			else if (t == 5) {
				newScr -> bonus = atof(cur[0]); 
			}else if(t == 6) {
				newScr -> total = atof(cur[0]);
			}
			t++;
			pos = 0;
		}
		else 
			cur[pos++] = s[i];
	} 
}


void addScoreBoardCSV(Scoreboard *& pScore, char* yearName, char* semesterName, char* coursename) {
	char dirOut[] = { "C:\\Github\\CS162FinalProject\\Data\\" };
	char d[505] = "";
	strcat(d, dirOut);
	strcat(d, yearName);
	strcat(d, "\\Semester\\");
	strcat(d, semesterName);
	strcat(d, "\\");
	strcat(d, "Course.txt");

	ifstream fin;
	
	fin.open(d);
	if(!fin.is_open()){
		cout << "Error at open Course.txt" << endl;
		return;
	}else{
		system("cls");
		cout << ">>Course: " << endl;
		int n;
		fin >> n;
		for(int i = 0; i < n; i++){
			char tcourse[20];
			fin.ignore(100, '\n');
			fin.get(tcourse, 20, '\n');
			cout << "[" << i+1 << "] " << tcourse << endl;
		}
		cout << "Please input a course: ";
		char mycourse[20];
		cin.ignore(100, '\n');
		cin.get(mycourse, 20, '\n'); 
	}
	fin.close();
	
	char dc[201] = "";
	strcat(dc, mycourse);
	strcat(dc, ".txt");
	
	char ddd[505] = "";
	strcat(ddd, dirOut);
	strcat(ddd, yearName);
	strcat(ddd, "\\Semester\\");
	strcat(ddd, semesterName);
	strcat(ddd, "\\");
	strcat(ddd, dc);
	
	
	ofstream fOut(ddd);
	char dirIn[] = { "C:\\Github\\CS162FinalProject\\Data\\Scoreboard_csv\\" };
	char dd[505] = "";
	strcat(dd, dirIn);
	strcat(dd, mycourse);

	ifstream fIn(dd);

	char* s = new char[505];
	while (fIn.getline(s, 505)) {
		Scoreboard *newScr = new Scoreboard;
	    inputScoreboardCSV(newScr, s);
	
		if (pScore == nullptr)
			pScore = newScr;
		else {
			Scoreboard* pCur = pScore;
			while (pCur -> scoreboardNext != nullptr)
				pCur = pCur -> scoreboardNext;
			pCur -> scoreboardNext = newScr;
			pCur = pCur -> scoreboardNext;
		}
	}
	Scoreboard *pCur = pScore;
	while (pCur != nullptr) {
		fOut << pCur -> stu -> studentID << ' ' << pCur -> stu -> Name << ' ' << pCur -> midterm << "-" << pCur -> final << "-" << pCur -> bonus << ' ' << pCur -> total << '\n';
		pCur = pCur -> scoreboardNext;
	}
}
