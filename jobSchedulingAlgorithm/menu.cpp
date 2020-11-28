#include<iostream>

//先来先服务FCFS
#include "FCFS.h"
#include "SJF.h"
//短作业优先SJF（非抢占）
//高响应比优先调度算法HRRN
//最短剩余时间调度SRT
using namespace std;

void menu()
{
    cout << "欢迎使用作业调度算法程序！" << endl;
    bool t = true;
    while(t)
    {
        cout << "-------------------------" << endl;
        cout << "1代表FCFS | 2代表SJF" << endl;
        cout << "0代表退出" << endl;
        cout << "请输入您的选择：";
        int select;
        cin >> select;
        switch(select)
        {
            case 0:
                cout << "Good Bye!";
                t = false;
                break;
            case 1:
                FCFS();
                break;
            case 2:
                SJF();
                break;
            case 3:
                break;
        }

    }
}
