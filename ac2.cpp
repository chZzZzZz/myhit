#include <iostream>

using namespace std;

int main()
{   int i,n,a;
    char input[100];
    cout<<"how many number do you want to type"<<endl;
    cin.getline(input,100);i=atoi(input);//注意不能用cin>>i;因为cin带有回车，回车进入下一个输入里造成p[0]=0;
    cin>>a;//测试上述所说是否正确
    cout<<"please type the number"<<endl;
    int *p=new int[i];
    if (p==NULL)exit(1);
    for(n=0;n<i;n++)
    {
        cin.getline(input,100);
        p[n]=atoi(input);
    }

    for(n=0;n<i;n++)
    {
        cout<<p[n]<<" ";
    }

        delete[] p;


    return 0;
}
