#ifndef HEAD_H
#define HEAD_H

#define TAB "\t"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define INIT_SIZE 100
#define INCREMENT 10

using namespace std;

typedef struct ElemType
{	
	int row;	
	int col;
	int ord = 0;
	int di = 0;
}ElemType;
typedef int Status;
typedef bool FLAG;
#endif