#include <iostream>

using namespace std;
//该程序将有符号的整数或字符转换为无符号整数
int main()
{   signed char a=-128;//char 8bits，short 16bits，long32bits
    int r=static_cast<unsigned short>(a);//static_cast用于基本数据类型转换 注意！！不能转换const等属性
    cout <<hex<<"0x"<<r<<"H";"\n";//hex用于将int变量以16进制形式输出
    return 0;
}
