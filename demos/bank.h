#include<stdio.h>
#include <iostream>
void showInfo(int resourceNum, int available[], int processNum, int **maxRequest, int **allocation, int **need);
void SafeInfo(int *work, int i, int resourceNum, int **allocation, int **need);
bool isAllZero(int kang, int num, int resourceNum, int **need);
bool isSafe(int resourceNum, int num, int **need, int **allocation, int safeSeries[], int available[], int processNum, bool Finish[]);
void fun_bank();
