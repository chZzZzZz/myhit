/***********************************************************************  模拟退火算法解决工作指派问题
***********************************************************************/
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h>
using namespace std;
const int MAXN = 50;           //最大约束数n
const double INIT_T =2000;      //初始温度
const double RATE = 0.95;        //温度衰减率
const double FINAL_T = 0;    //终止温度
const int IN_LOOP = 13000;      //内层循环次数
const int OUT_LOOP = 20000;       //外层循环次数
struct work {                   //定义工作结构类型
     int p[MAXN];             //工人序号
     double time;              //时间
 };
int N;                          //工人数量
double D[MAXN][MAXN];        //工作时间
int x[MAXN][ MAXN];           //选择工人与工作
work bestwork;                   //最优的遍历路径

void swap(int &a,int &b)         //注意&a和&b 我们要的p[]里存储的数据
  {
	  int t;
      t=a;a=b;b=t;
  }
inline double totaldist(work q)        //计算总时间
 {
    int a,i,j;
    double cost = 0;
	for(i=0,j=0;i<N;i++,j++)
		{
			a=q.p[i];
			cost=D[a][j];
		}
	     return cost;
 }
void init()                     //读入数据，并初始化//输入时间矩阵D[i][j] 格式：工人i 工作j
{  cout<<"input N"<<endl;
   cin>>N;
   int i=0,j=0;
for(i=0;i<N;i++)
{
	   for(j=0;j< N;j++)

	    D[i][j]=rand()%100;

}

for (i=0; i<N; i++)    //最优解的初始状态
    {
         bestwork.p[i] = i;

     }
     bestwork.time = totaldist(bestwork);
}
/***********************************************************************               产生指派方法
***********************************************************************/
work getnext(work p)   //新解产生函数
 {
     int x, y;
     work ret;
     ret = p;
     do {
         x = rand() % 4;
         y = rand() % 4 ;//x,y产生0-3的随机数
        }while(x == y);
     swap(ret.p[x], ret.p[y]);     //交换两工人位置顺序
     ret.time = totaldist(ret);
     return ret;
 }
/***********************************************************************                     退火和降温过程
 **********************************************************************/
  work sa()
 {
    double T;               //温度
    work curwork,newwork; //当前指派和新指派
    int i,A_t=0;
    double delta;
    T = INIT_T;     //赋值初始温度
    curwork = bestwork;
    while(true)                            //内循环
     {
        for (i=1; i<=IN_LOOP; i++)
        {
            newwork = getnext(curwork);    //获取新路径
            delta = newwork.time - curwork.time;
            if (delta < 0.0)
            {
                curwork = newwork;
            }
            else
             {
                double rnd = rand()%1001/1000;     //随机产生0-1的浮点数
                double p = exp(-delta/T);
                if (p > rnd)
                    curwork = newwork;
                else
                    curwork=curwork;
              }
            A_t++;
          }
          T = T * RATE;    //降温
if ( A_t >= OUT_LOOP || T < FINAL_T) break;       //外循环停止条件

      }
      return newwork;
}
/***********************************************************************                  程序主函数
  *********************************************************************/
int main()
 {
    init();
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			cout<<D[i][j]<<" ";
			cout<<endl;
	}
    printf("初始工作指派: %.4f\n", bestwork.time);
	for(int i=0;i<N;i++)
	{
		printf(" %d->", bestwork.p[i]+1);
	}
 	printf("\n");
    bestwork=sa();
    printf("最优工作指派: %.4f\n", bestwork.time);
	for(int j=0;j<N;j++)
	{
		printf(" %d->",bestwork.p[j]+1);
	}
	printf("\n");
    system("pause");
    return 0;
}
