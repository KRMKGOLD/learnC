#ifndef __MENU_H__
#define __MENU_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#pragma warning (disable : 4996)

struct student {
	int number;
	char name[10];
	int kor;
	int eng;
	int math;
};

typedef struct student Student;

Student* stuArr;

void showMenu();

int checkOverLap(int number, char name[]);

void inputFirstData();
void inputStuNum();
void inputData();
void deleteData();
void searchData();
void printData();

#endif