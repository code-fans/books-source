#include <iostream>
#include <fstream>
#define MAXN 201
using namespace std;
ifstream fi("game1.in");
ofstream fo("game1.out");
long n,ori,ans,ans2;
long F[MAXN][MAXN],num[MAXN];
 
inline long max(long a,long b)
{
	return a>b?a:b;
}
 
long get_S(long a,long b)		//计算区间a, b 值的和 
{
	long p=0;
	for (long i=a;i<=b;i++)
		p+=num[i];
	return p;
}
 
long get_F(long i,long j)	//动态规划 
{
	if (F[i+1][j]==ori)
		F[i+1][j]=get_F(i+1,j);
	if (F[i][j-1]==ori)
		F[i][j-1]=get_F(i,j-1);
	return max(num[i]+get_S(i+1,j)-F[i+1][j],num[j]+get_S(i,j-1)-F[i][j-1]);
}
 
void init()     	//初始化 
{
	long i;
	fi >> n;
	memset(F,0xF,sizeof(F));
	ori=F[0][0];
	for (i=1;i<=n;i++)
	{
		fi >> num[i];
		F[i][i]=num[i];
	}
}
 
void print()
{
	fo << ans << ' ' << ans2 << endl;
	fi.close();
	fo.close();
}
 
int main()
{
	init();
	ans=get_F(1,n);
	ans2=get_S(1,n)-ans;
	print();
	return 0;
}
