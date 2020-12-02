#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream fs("abc",ios::in|ios::out|ios::trunc);
    if(!fs)
        cout<<"open error"<<endl;
    fs.put('a');
    fs.put('b');
    fs.seekp(0,ios::beg);
    char ch;
    while(fs.get(ch),!fs.eof()) {
        cout<<ch;
    }
    fs.close();
    return 0;
}
