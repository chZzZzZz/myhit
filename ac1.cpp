#include <iostream>

using namespace std;
//�ó����з��ŵ��������ַ�ת��Ϊ�޷�������
int main()
{   signed char a=-128;//char 8bits��short 16bits��long32bits
    int r=static_cast<unsigned short>(a);//static_cast���ڻ�����������ת�� ע�⣡������ת��const������
    cout <<hex<<"0x"<<r<<"H";"\n";//hex���ڽ�int������16������ʽ���
    return 0;
}
