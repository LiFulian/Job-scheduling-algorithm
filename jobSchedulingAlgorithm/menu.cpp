#include<iostream>

//�����ȷ���FCFS
#include "FCFS.h"
#include "SJF.h"
//����ҵ����SJF������ռ��
//����Ӧ�����ȵ����㷨HRRN
//���ʣ��ʱ�����SRT
using namespace std;

void menu()
{
    cout << "��ӭʹ����ҵ�����㷨����" << endl;
    bool t = true;
    while(t)
    {
        cout << "-------------------------" << endl;
        cout << "1����FCFS | 2����SJF" << endl;
        cout << "0�����˳�" << endl;
        cout << "����������ѡ��";
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
