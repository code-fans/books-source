//�������� - �ݹ��㷨�Ż�
#include <bits/stdc++.h>
using namespace std;
const int MAXN=312;

int n;
int Dir[MAXN][MAXN];
double c[MAXN][MAXN][MAXN];

double F(int day,int x,int y,double p)//pΪ����
{
  if(day>n || Dir[x][y]==0)    //�糬ʱ�������곬��Χ
    c[day][x][y]=-1;           //���Ϊ-1
  if(c[day][x][y]==-1)         //����ѱ���ǹ�������������
    return 0;                  //����0
  if(c[day][x][y]!=0)          //����Ѿ������dayʱ(x,y)�����������ӵĸ���
    return c[day][x][y];       //ֱ�ӷ���ֵ
  if(day==x && y==(n>>1)+1)    //�����������������,���ظ���
  {
    c[day][x][y]=p;
    return p;
  }
  double t=F(day+1,x+1,y,p)+F(day+1,x-1,y,p)+F(day+1,x,y+1,p)+F(day+1,x,y-1,p);
  if(t==0)                     //���û����������,��ǲ��˳�
  {
    c[day][x][y]=-1;
    return 0;
  }
  c[day][x][y]=t/Dir[x][y];    //����,�����dayʱ(x,y)�����������ӵĸ���
  return c[day][x][y];
}

int main()
{
  freopen("encounter.in","r",stdin);
  freopen("encounter.out","w",stdout);
  scanf("%d",&n);
  if(n%4==1)
    puts("0");
  else
  {
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        Dir[i][j]=2+(i>1 && i<n)+(j>1 && j<n);
    printf("%.4f\n",F(0,(n/2)+1,((n/2)+1),1));
  }
  return 0;
}

