#ifndef _STAFF_H_
#define _STAFF_H_

#include "Header.h"

void viewListOfCLasses(Year* pYear);

void viewStudentInfo(Student student);
void viewListOfStudentsInClass(Year* pYear, char* className);
void viewScoreBoardOfClass(Student * pStudent, Semester * pSemester);

void viewListOfStudentsInCourse (Student *pStuInCourse, char *courseID);
void viewScoreboardOfCourse (Course *pCourse);

void inputScoreboardCSV(Scoreboard *& newScr , char *s);
void addScoreBoardCSV(Scoreboard *& pScore, char * yearName, char * semesterName, char * courseName);
void exportStudentToCsv(Student* pStuInCourse, char *courseID);
void updateScoreBoardStudent(Scoreboard *& pScr, char *yearName, char* semesterName, char *courseID, char* studentID);

#endif // !_STAFF_H_
