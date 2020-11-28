#include <iostream>
#include <vector>
#include "FCFS.h"
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

bool comparisonSJF(process a, process b)
{
    return a.maxCostTime<b.maxCostTime;
}

void SJF()
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
    sort(Vpro.begin(), Vpro.end(), comparisonSJF);
    for(int i=0;i<n;i++)
    {
        cout << Vpro[i].name << Vpro[i].arriveTime << Vpro[i].maxCostTime << endl;
    }
}
