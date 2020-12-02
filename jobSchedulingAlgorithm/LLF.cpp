#include <iostream>
#include <stdio.h>
#define MASK_BIT(x, bit) ((x) & (0x1) << (bit)) //解开，设置的值
#define SET_BIT(x, bit) ((x) |= ((0x1) << (bit))) //设置，这个值相等
#define NUM_TASKS 2 //定义任务数
#define EXE_LEN 40  //定义执行总数
using namespace std;
void init_task(task_t* , unsigned int , unsigned int , int );
void init_tasks(task_t [], unsigned int [], unsigned int [], int [],unsigned int );
void copy_tasks(task_t [], task_t [], unsigned int );
void print_tasks(task_t [], unsigned int );
unsigned int LLF(task_t [], unsigned int ,int );
void sim_schedule(task_t [], unsigned int , unsigned int [], unsigned int );
void print_schedule(unsigned int [], unsigned int );
void print_missed(unsigned int [], unsigned int );
//定义一个任务的结构体
typedef struct
{
	unsigned int WCET;
	unsigned int period;
	int deadline;
} task_t;

int main() {
	/**1. 初始化参数**/
	unsigned int WCET[NUM_TASKS] = {10,25};       //定义任务执行需要的时间
	unsigned int deadline[NUM_TASKS] = {20,50}; //定义任务截止时间
	int period[NUM_TASKS] = {20,50};            //定义经过多长时间以后又会有新的任务加入
	bool finished[NUM_TASKS] = {false,false};

	task_t tasks[NUM_TASKS];
	init_tasks(tasks, WCET, deadline, period, NUM_TASKS); //初始化任务表

	print_tasks(tasks, NUM_TASKS);                  //打印任务表
	printf("\nexecution length: %u\n", EXE_LEN);    //执行的总长度

	/**2. 求各个时间点根据算法应该执行的task**/
	unsigned int schedule[EXE_LEN];                             //时间序列（执行长度的每一个单位构成时间序列）
	sim_schedule(tasks, NUM_TASKS, schedule, EXE_LEN);

	/**3. 打印完整的时间序列表和缺失值**/
	printf("schedule: ");
	print_schedule(schedule, EXE_LEN);//打印最终安排的时间表
	printf("missed  : ");
	print_missed(schedule, EXE_LEN);//缺失值

}


//初始化任务：输入结构体，最坏执行时间WCET、需要时间period、截止时间deadline
void init_task(task_t *t, unsigned int WCET, unsigned int period, int deadline)
{
	t->WCET = WCET;
	t->period = period;
	t->deadline = deadline;
}

//初始化任务体集合（存储任务的数组），将各个task用数组存储，输入task的数目即数组的长度
void init_tasks(task_t t[], unsigned int WCET[], unsigned int period[], int deadline[],unsigned int numTasks)
{
	unsigned int i;
	for(i = 0; i < numTasks; i++)
	{
		init_task(&(t[i]),WCET[i],period[i],deadline[i]);
	}
}

//复制task，将一个task列表复制到另一个task列表中，常用作备用处理，需要传入task数目
void copy_tasks(task_t tasks_to_be_copied[], task_t place_to_copy[], unsigned int numTasks)
{
	unsigned int i;
	for(i = 0; i < numTasks; i++)
	{
		place_to_copy[i].WCET = tasks_to_be_copied[i].WCET;
		place_to_copy[i].period = tasks_to_be_copied[i].period;
		place_to_copy[i].deadline = tasks_to_be_copied[i].deadline;
	}
}

//打印task
void print_task(task_t t)
{
	printf("exe time: %u period: %u deadline: %u \n", t.WCET, t.period, t.deadline);
}

//打印task列表
void print_tasks(task_t t[], unsigned int numTasks)
{
	unsigned int i;
	for (i = 0; i < numTasks; ++i)
	{
		printf("task %u: ", i);
		print_task(t[i]);
	}

}

//LLF算法实现
unsigned int LLF(task_t t[], unsigned int numTasks,int time)
{//因为是对每个时间点的判断，所以这里传入时自带了当前时间，WCET（最坏完成时）即为运行时间+当前时间
	unsigned int least_index = 0;
	int least_laxity = 99999; //初始化最低松弛度（设置为int最大值）
	int current_laxity; //当前松弛度
	unsigned int i;
	for (i = 0; i < numTasks; i++)
	{//遍历所有的task
		if(t[i].WCET > 0)//task还未执行完
		{
			char s[2];
			s[0] = 'A';
			s[1] = 'B';
			int nowO = i;
			current_laxity = t[i].deadline - t[i].WCET ; //计算松弛度=截止时间-剩余需要执行的时间-当前时间
			cout<<time<<"时"<<s[nowO]<<"的松弛度="<<current_laxity<<endl;
		}

		if(current_laxity < least_laxity)
		{//交换索引
			least_index = i;
			least_laxity = current_laxity;
		}
	}
	return least_index;
}

void sim_schedule(task_t t[], unsigned int numTasks, unsigned int schedule[], unsigned int schedule_length)
{
    //复制原任务表
	task_t placeholder_task[numTasks];
	copy_tasks(t, placeholder_task, numTasks);

	unsigned int current_task;//当前任务索引

	unsigned int i;

	int times = 1;

	for(i = 0; i < schedule_length; i++)
	{//给每一个时间点分配task
		schedule[i] = 0; //各个时间点初始化为零

		//决定当前时间点应该分配的任务
		current_task = LLF(placeholder_task, numTasks,i); //传入llf算法，修改#1

		//执行最低松弛度对应的任务，执行一次
		placeholder_task[current_task].WCET -= 1;

		//时间点推移
		unsigned int j;
		for (j = 0; j < numTasks; j++)
		{//遍历所有任务
			placeholder_task[j].period -= 1;    //已经经过时间-1
			placeholder_task[j].deadline -= 1;  //截止时间剩余-1

			//到了截止时间以后
			if(placeholder_task[j].deadline <= 0)   //如果截止时间小于等于零
			{//如果任务还没有执行完
				if(placeholder_task[j].WCET > 0)    //而其仍然没有执行完
				{//就在时间表设置一个较大的值占位，方便下次比较
					SET_BIT(schedule[i], j + 16);
				}
			}

			//又加入了新的task
			if(placeholder_task[j].period <= 0)
			{
				times++;
				placeholder_task[j].WCET = t[j].WCET;
				placeholder_task[j].period = t[j].period;
				placeholder_task[j].deadline = t[j].deadline * times; //加入的task的截止时间已经改变
			}

		}

		SET_BIT(schedule[i], current_task); //设置时间表的占位：2^current_task
	}
}

void print_schedule(unsigned int schedule[], unsigned int length)
{//打印时间表
	unsigned int i;
	unsigned int count;
	for (i = 0; i < length; ++i)
	{//遍历了所有的执行点
		count = 0;
		while(MASK_BIT(schedule[i], count) == 0)
		{//统计时间序列表中所有
			count++;
		}
		printf("%u ", count); //十进制无符号整数，打印的其实是task对应的下标
	}
	printf("\n");
}

void print_missed(unsigned int schedule[], unsigned int length)
{//打印缺失值
	unsigned int i;
	unsigned int count;
	for (i = 0; i < length; ++i)
	{//遍历所有的时间序列
		printf("[ ");

		for(count = sizeof(schedule[0]); count > sizeof(schedule[0])/2; count--)
		{//遍历的其实是schedule[0]元素的类型的长度，是定制，sizeof(int)=4，循环2次
			if(MASK_BIT(schedule[i], count) == 1) //为1的情况只会是第一个task，而这里如果满足，代表始终没有符合执行的情况
			{
				printf("%u", count);
			}
		}
		printf("] ");
	}
	printf("\n");
}
