/***********************************************************************                      模拟退火算法解决单机调度问题

***********************************************************************/
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;
const int MAXN = 500;           //最大约束数n
const double INIT_T =50000;      //初始温度
const double RATE = 0.98;        //温度衰减率
const double FINAL_T = 0;    //终止温度
const int IN_LOOP = 20000;      //内层循环次数
const int OUT_LOOP =50000 ;       //外层循环次数
struct sequence {                   //定义调度序列结构类型
     int p[MAXN];             //工作序号
     int time;              //此调度顺序下总加工时间
 };
int N=20;                          //工件数量
int P[MAXN]={1,3,3,3,3,3,3,4,4,4,4,4,5,5,5,6,6,6,7,7};
int D[MAXN]={93,93,31,93,39,62,93,93,93,93,93,93,93,93,93,40,60,93,93,93};     //加工时间pj
sequence bestseq;                   //最优的遍历路径

void swap(int &a,int &b)       //交换工件顺序
  {
	  int t;
      t=a;a=b;b=t;
  }

inline int totaldist(sequence q)        //计算总时间
 {  int pe=0;//惩罚系数pe
    int cost[20]={0};//Ci，即完成时间
    int totaltime=0;
    for(int i=0 , k=0;i<20,k<20;i++,k++)
    {
        for(int j=0;j<=i;j++)
     {
        cost[i]+=P[q.p[j]];
     }
     if(cost[i-1]<=29&&cost[i]>29)//t=29时刻的检修
     {
         cost[i]=30+cost[i]-2*cost[i-1];
     }
     if(cost[i-1]<=59&&cost[i]>59)//t=59时刻的检修
     {
         cost[i]=60+cost[i]-2*cost[i-1];
     }
    if(cost[i]>D[q.p[k]])//对于超过交货期的加入惩罚
           {
               pe=cost[i]-D[q.p[k]];
           }
           else{pe=0;}
        totaltime=totaltime+cost[i]+pe;//总完成时间=sum(Ci,0,19)+pe
    }
	     return totaltime;
 }

void init()                     //读入数据，并初始化
{  for (int i=0; i<N; i++)    //最优解的初始序列
    {
         bestseq.p[i] = i;
     }
     bestseq.time = totaldist(bestseq);
}
/***********************************************************************               产生新的顺序
***********************************************************************/
sequence getnext(sequence p)   //新解产生函数
 {
     int r1,r2;
     sequence ret;
     ret = p;
     do{
        r1=rand()%20;
        r2=rand()%20;
     }while(r1==r2);
     swap(ret.p[r1], ret.p[r2]);     //交换两工件位置顺序
     ret.time = totaldist(ret);
     return ret;
 }
/***********************************************************************                     退火和降温过程
 **********************************************************************/
  sequence sa()
 {
    double T;               //温度
    sequence curseq,newseq; //当前工件顺序和新工件顺序
    int i,A_t=0;//A_t统计外循环次数
    double delta;
    T = INIT_T;     //赋值初始温度
    curseq = bestseq;//现将初始序列赋值给当前序列
srand((unsigned)time(NULL));//随机产生随机数种子
  while(true)
     {
        for (i=1; i<=IN_LOOP; i++)
        {
            newseq = getnext(curseq); //获取新路径
            delta = newseq.time - curseq.time;
            if (delta < 0.0)
            {
                curseq = newseq;
            }
            A_t++;
          }
if ( A_t >= OUT_LOOP || T < FINAL_T) break;
         T = T * RATE;    //降温
      }
      return curseq;
}
/***********************************************************************                  程序主函数
  *********************************************************************/
int main()
 {
    init();
    printf("初始工件序列: %d\n", bestseq.time);
	for(int i=0;i<N;i++)
	{
		printf(" %d->", bestseq.p[i]+1);
	}
 	printf("\n");
    bestseq=sa();
    printf("最优工件序列: %d\n", bestseq.time);
	for(int j=0;j<N;j++)
	{
		printf(" %d->",bestseq.p[j]+1);
	}
	printf("\n");
    return 0;
}
