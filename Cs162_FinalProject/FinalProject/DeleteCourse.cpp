#include"Header.h"
#include"Course.h"
#include<iostream>
using namespace std;

void deleteCourse(Course*& pHead, char* courseID) {
    if (strcmp(pHead->id, courseID) == 0) {
        Course* pDel = pHead;
        pHead = pHead->pNext;
        delete pDel;
    }
    else {
        Course* pCur = pHead;
        while (pCur->pNext && strcmp(pCur->pNext->id, courseID) != 0) {
            pCur = pCur->pNext;
        }
        if (pCur->pNext) {
            Course* pDel = pCur->pNext;
            pCur->pNext = pDel->pNext;
            delete pDel;
        }
    }
}