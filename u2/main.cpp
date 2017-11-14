#include <fstream>
#include <iostream>
using namespace std;
ofstream fout("out.txt");
void Move(int n,char x,char y)
{
  fout<<"把"<<n<<"号从"<<x<<"挪动到"<<y<<endl;
}
void Hannoi(int n,char a,char b,char c)
{
      if(n==1)
              Move(1,a,c);
    else  {
          Hannoi(n-1,a,c,b);
            Move(n,a,c);
            Hannoi(n-1,b,a,c);
    }
}
int main()
{
    fout<<"以下是7层汉诺塔的解法:"<<endl;
    Hannoi(7,'a','b','c');
    fout.close();
    cout<<"输出完毕！"<<endl;
    return 0;
}
