#include <iostream>

using namespace std;

int main()
{   int i,n,a;
    char input[100];
    cout<<"how many number do you want to type"<<endl;
    cin.getline(input,100);i=atoi(input);//ע�ⲻ����cin>>i;��Ϊcin���лس����س�������һ�����������p[0]=0;
    cin>>a;//����������˵�Ƿ���ȷ
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
