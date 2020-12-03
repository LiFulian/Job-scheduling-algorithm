#include "windows.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include ".\headers\control.h"
#include ".\headers\global.h"
#include ".\headers\job\FCFS.h"
#include ".\headers\job\SJF.h"
#include ".\headers\job\HRRF.h"
#include ".\headers\job\HPF.h"
#include ".\headers\job\RR.h"
#include ".\headers\job\LLF.h"

using namespace std;

int main()
{
    welcome();
    system("color 5f"); //改变颜色

    job jobs[MAX_NUM];//作业空间
	initial_jobs(jobs); //初始化所有作业信息
	int num = read_Jobdata(jobs); //读取数据文件,返回作业数目

	int choice = 1;
        printf("\n请选择其中一种调度算法:\n");
		printf("(1)先来先服务FCFS\n");
		printf("(2)短作业优先SJF\n");
		printf("(3)高相应比优先HRRF\n");
		printf("(4)优先权高者优先HPF\n");
		printf("(5)时间片轮转RR\n");
		printf("(6)最低松弛度LLF\n");
		printf("(9)自动执行所有算法\n");
		printf("(0)退出\n");
	while(choice != 0){
		printf("请输入一个数字：");
		scanf("%d",&choice);
		switch (choice){
		case 1:FCFS(jobs,num);break;
		case 2:SJF(jobs,num);break;
		case 3:HRRF(jobs,num);break;
		case 4:HPF(jobs,num);break;
		case 5:RR(jobs,num);break;
		//case 6:fun_llf();break;
		case 9:
		    FCFS(jobs,num);
		    SJF(jobs,num);
		    HRRF(jobs,num);
		    HPF(jobs,num);
		    RR(jobs,num);
		    printf("执行完成，已自动为您打开输出文件。~~~，，，(^v^)、、、~~~\n\n");
            system("start \"\" \"output.txt");
            break;
		case 0:printf("退出程序\n");break;
		}
	}
	_keygo();
}
