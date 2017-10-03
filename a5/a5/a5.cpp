#include<iostream>
using namespace std;
int main()
{	
	int D[10][10];
	for(int i=0;i<4;i++)
	{
			for(int j=0;j<4;j++)
			{
				D[i][j]=rand()%101;
			}
			
	}
	for(int i=0;i<4;i++)
	{
			for(int j=0;j<4;j++)
			{cout<<D[i][j]<<" ";}
			cout<<endl;
	}
	return 0;
}