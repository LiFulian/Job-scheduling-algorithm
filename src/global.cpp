#include <fstream>
#include <iostream>
#include "../headers/global.h"
using namespace std;
void write(char *data){
// 以写模式打开文件
   ofstream outfile;
   outfile.open("output.txt", ios::app);
 // 向文件写入用户输入的数据
   outfile << data << endl;
      // 关闭打开的文件
   outfile.close();
}

