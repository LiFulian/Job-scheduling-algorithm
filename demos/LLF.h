#include <iostream>  
#include <string>
#include <stdio.h>
#define EXE_LEN 90  //定义执行总数
using namespace std;
int NUM_TASKS = 3;
typedef struct
{
	string name;			//名
	unsigned int WCET;		//执行时间
	unsigned int period;	//加入时间，默认为执行完立即加入
	int deadline;			//截止时间
	int cycle;				//目前执行的周期
	int status; 			//记录当前任务的执行状态，未执行完为0，在截止前执行完设置为1
	int join;				//加入时间
} task_t;

void init_task(task_t *t, string name, unsigned int WCET, unsigned int period, int deadline, int cycle, int status, int join);
void init_tasks(task_t t[], string name[], unsigned int WCET[], unsigned int period[], int deadline[], int cycle[], int status[], int join[], unsigned int numTasks);
void copy_tasks(task_t tasks_to_be_copied[], task_t place_to_copy[], unsigned int numTasks);
void update_task(task_t *t, unsigned int WCET, unsigned int period, int deadline, int cycle, int join);
void print_task(task_t t);
void print_tasks(task_t t[], unsigned int numTasks);
void set_schedule(string schedule[], string name, int index);
unsigned int llf(task_t ori_t[], task_t t[], unsigned int numTasks,int time);
void sim_schedule(task_t t[], unsigned int numTasks, string schedule[], unsigned int schedule_length);
void fun_llf();