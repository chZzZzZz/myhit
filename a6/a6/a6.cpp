#include<iostream>      /////////��ȡdian.txt�ļ��е����� ������Ϊ��ά����  
#include<fstream>  
using namespace std;  
const int n=4;
const int m=4;
int main()  
{   int i,j;
    int a[n][m];
    ifstream fin("F:\in.txt");         //���ļ�//��������  
    for(i=0;i<n;i++)  
        for(j=0;j<m;j++)  
            fin>>a[i][j];  
    fin.close();  
     
    for(i=0;i<n;i++,cout<<endl)                //����ոն��������  
        for(j=0;j<m;j++)   
            cout<<a[i][j]<<" ";  
   
 ofstream fout("F:\out.txt");     /////////////�����ά���鵽�ļ�out.txt��  
 for(i = 0; i <100; i ++)  
    {  
        for(j = 0; j <4; j ++)  
        {  
            fout<<a[i][j]<<"  "; //��ÿ��Ԫ��д���ļ����Կո�ָ�  
        }  
        fout << endl;//ÿ�������������ӻ��С�  
 }  
    return 0;  
}  