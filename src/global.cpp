#include <fstream>
#include <iostream>
#include "../headers/global.h"
using namespace std;
void write(char *data){
// ��дģʽ���ļ�
   ofstream outfile;
   outfile.open("output.txt", ios::app);
 // ���ļ�д���û����������
   outfile << data << endl;
      // �رմ򿪵��ļ�
   outfile.close();
}

