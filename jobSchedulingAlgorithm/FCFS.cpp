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
/* 这个comparison函数很重要.如果希望升序排序,就是"<",降序排列就是">"号,
结构体名.属性为比较标准排序了.*/
bool comparisonFCFS(process a, process b)
{
    return a.arriveTime<b.arriveTime;
}
void FCFS()
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
    sort(Vpro.begin(), Vpro.end(), comparisonFCFS);
    cout << "执行的顺序为：";
    for(int i=0;i<n;i++)
        cout << Vpro[i].name << "  ";
    cout << endl;
// 下面是自己写算法实现的
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
//    cout << "按下列顺序执行:" << endl;
//    while(!Spro.empty())
//    {
//        struct process tmp = Spro.top();
//        cout << "顺序\t进程名\t到达\t总花费" << endl;
//        cout << ++que << '\t' << tmp.name << '\t' << tmp.arriveTime << '\t' << tmp.maxCostTime<< endl;
//        Spro.pop();
//    }

}
