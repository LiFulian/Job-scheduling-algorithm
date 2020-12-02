#include <iostream>
//#include "../headers/job/FCFS.h"
//#include "../headers/job/HRRF.h"
//#include "../headers/job/SJF.h"
#include "../headers/control.h"
#include "../headers/global.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<queue>
#define getpch(type) (type*)malloc(sizeof(type))
#define inf 0x3f3f3f
#include <fstream>
using namespace std;
//数据设置区域

void initial_jobs(job jobs[])   //初始化所有作业信息
{
    for(int i=0; i<MAX_NUM; i++)
    {
        jobs[i].excellent=0;
        jobs[i].need_time=0;
        jobs[i].number=0;
        jobs[i].privilege=0;
        jobs[i].reach_time=0;
        jobs[i].run_time=0;
        jobs[i].start_time=0;
        jobs[i].tr_time=0;
        jobs[i].visited=false;
        jobs[i].wait_time=0;
        jobs[i].wtr_time=0;
        jobs[i].finish_time=0;
        jobs[i].reached=false;
    }
}
int read_Jobdata(job jobs[])  //读取数据文件,返回进程数目
{
    int num =1;
    char buffer[150];
    string line;
    // 以读模式打开文件
    ifstream infile("job.txt");
    string title;
    getline(infile, title);
    char t;
    while (infile.getline(buffer,120))//每一行
    {
        char *p;
        const char *d = " ,\r\n";
        p = strtok(buffer,d);
        int n=0;//列数
        char c;
        while(p) //每个行的每一列
        {
            n=n+1;
            if(n==1)
            {
                if(isdigit(p[0]))//纯数字
                    sscanf(p,"%d",&jobs[num].number);
                else
                    sscanf(p,"%c%d",&c,&jobs[num].number);
            }

            if(n==2)
                jobs[num].reach_time=atoi(p);
            if(n==3)
                jobs[num].need_time=atoi(p);
            if(n==4)
                jobs[num].privilege=atoi(p);
            p=strtok(NULL,d);
        }
        num++;
    }
    num--;
    // 关闭打开的文件
    infile.close();
    printf("read data success!\n");
    printf("作业的数量为: %d\n\n",num);
    cout<<title<<endl;
    for(int j=1; j<=num; j++)
    {
        printf("p%d\t%d\t\t%d\t\t%d\n",jobs[j].number,jobs[j].reach_time,jobs[j].need_time,jobs[j].privilege);
    }
    return num;
}
void initial_jobs_again(job jobs[],int num)
{
    for(int i=1; i<=num; i++)
    {
        jobs[i].finish_time=0;
        jobs[i].excellent=0;
        jobs[i].tr_time=0;
        jobs[i].wtr_time=0;
        jobs[i].wait_time=0;
        jobs[i].visited=false;
    }
}

//按任意键继续
char _keygo()
{
    char c;
    printf("按任意键继续.......\n");
    c = getch();
    return c;
}
