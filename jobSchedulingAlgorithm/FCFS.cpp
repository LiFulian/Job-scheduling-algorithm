#include <iostream>
#include <vector>
#include "FCFS.h"
//#include <stack>
#include <algorithm>
using namespace std;

struct process
{
    char name[10];
    int arriveTime;
    int maxCostTime;
//    int startTime = 0;
//    int endTime = 999999;
};
/* ���comparison��������Ҫ.���ϣ����������,����"<",�������о���">"��,
�ṹ����.����Ϊ�Ƚϱ�׼������.*/
bool comparisonFCFS(process a, process b)
{
    return a.arriveTime<b.arriveTime;
}
void FCFS()
{
    int n;
    cout << "��������������ҵ����Ŀ��" ;
    cin >> n;
    vector<process> Vpro(n);
    cout << "��������������ҵ����Ϣ��" << endl;
    cout << "������\t����\t�ܻ���" << endl;
    for(int i=0;i<n;i++)
    {
        cin >> Vpro[i].name >> Vpro[i].arriveTime >> Vpro[i].maxCostTime;
    }
    sort(Vpro.begin(), Vpro.end(), comparisonFCFS);
    cout << "ִ�е�˳��Ϊ��";
    for(int i=0;i<n;i++)
        cout << Vpro[i].name << "  ";
    cout << endl;
// �������Լ�д�㷨ʵ�ֵ�
//    stack<process> Spro;
//    for(int i=0;i<n;i++)
//    {
//        struct process tmp = Vpro[i];
//        int index=i;
//        for(int j=0;j<n;j++)
//        {
//            if(tmp.arriveTime <= Vpro[j].arriveTime)
//            {
//                tmp = Vpro[j];
//                index = j;
//            }
//
//        }
//        cout << tmp.name << endl;
//        Spro.push(tmp);
//        Vpro[index].arriveTime = -1;
//    }
//    cout << Spro.size() << endl;
//    int que = 0;
//    cout << "������˳��ִ��:" << endl;
//    while(!Spro.empty())
//    {
//        struct process tmp = Spro.top();
//        cout << "˳��\t������\t����\t�ܻ���" << endl;
//        cout << ++que << '\t' << tmp.name << '\t' << tmp.arriveTime << '\t' << tmp.maxCostTime<< endl;
//        Spro.pop();
//    }

}
