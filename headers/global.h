//������ҵ��Ϣ�ṹ
#ifndef _TEST_H_
#define _TEST_H_
typedef struct job{
    char number;         //��ҵ��
	int reach_time;     //��ҵ�ִ�ʱ��
	int need_time;      //��ҵ��ִ��ʱ��
	int privilege;	    //��ҵ����Ȩ
	float excellent;    //��Ӧ��
	int start_time;     //��ҵ��ʼʱ��
	int wait_time;      //�ȴ�ʱ��
	int tr_time;        //��תʱ��
	double wtr_time;    //��Ȩ��תʱ��
	int run_time;       //��ҵ�ۼ���ִ��ʱ��
	bool visited;		//��ҵ�Ƿ񱻷��ʹ�
	int finish_time; //��ҵ���ʱ��
	bool reached; //��ҵ�Ƿ�ִ�
};
const int MAX_NUM = 10;//�����ҵ����
const int MAX_LINE=1024;//һ�е�size
void write(char *data);
#define inf 0x3f3f3f
#endif
