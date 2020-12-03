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
    system("color 5f"); //�ı���ɫ

    job jobs[MAX_NUM];//��ҵ�ռ�
	initial_jobs(jobs); //��ʼ��������ҵ��Ϣ
	int num = read_Jobdata(jobs); //��ȡ�����ļ�,������ҵ��Ŀ

	int choice = 1;
        printf("\n��ѡ������һ�ֵ����㷨:\n");
		printf("(1)�����ȷ���FCFS\n");
		printf("(2)����ҵ����SJF\n");
		printf("(3)����Ӧ������HRRF\n");
		printf("(4)����Ȩ��������HPF\n");
		printf("(5)ʱ��Ƭ��תRR\n");
		printf("(6)����ɳڶ�LLF\n");
		printf("(9)�Զ�ִ�������㷨\n");
		printf("(0)�˳�\n");
	while(choice != 0){
		printf("������һ�����֣�");
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
		    printf("ִ����ɣ����Զ�Ϊ��������ļ���~~~������(^v^)������~~~\n\n");
            system("start \"\" \"output.txt");
            break;
		case 0:printf("�˳�����\n");break;
		}
	}
	_keygo();
}
