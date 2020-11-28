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
    cout << "请输入参与调度作业的数目：" ;
    cin >> n;
    vector<process> Vpro(n);
    cout << "请输入参与调度作业的信息：" << endl;
    cout << "进程名\t到达\t总花费" << endl;
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
