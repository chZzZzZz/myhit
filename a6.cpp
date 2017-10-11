#include<iostream>      /////////读取dian.txt文件中的数据 并保存为二维数组  
#include<fstream>  
using namespace std;  
const int n=4;
const int m=4;
int main()  
{   int i,j;
    int a[n][m];
    ifstream fin("F:\in.txt");         //打开文件//读入数字  
    for(i=0;i<n;i++)  
        for(j=0;j<m;j++)  
            fin>>a[i][j];  
    fin.close();  
     
    for(i=0;i<n;i++,cout<<endl)                //输出刚刚读入的数据  
        for(j=0;j<m;j++)   
            cout<<a[i][j]<<" ";  
   
 ofstream fout("F:\out.txt");     /////////////保存二维数组到文件out.txt中  
 for(i = 0; i <100; i ++)  
    {  
        for(j = 0; j <4; j ++)  
        {  
            fout<<a[i][j]<<"  "; //将每个元素写入文件，以空格分隔  
        }  
        fout << endl;//每行输出结束，添加换行。  
 }  
    return 0;  
}  