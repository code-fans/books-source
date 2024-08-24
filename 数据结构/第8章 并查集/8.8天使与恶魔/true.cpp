#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN=600;

int fa[MAXN],Rank[MAXN],sets[MAXN],tag[MAXN][2],path[MAXN][MAXN],man[MAXN][2];

int Find(int x)
{
  if(x!=fa[x])
  {
    int px=Find(fa[x]);
    Rank[x]^=Rank[fa[x]];               //x->z=(x->y)^(y->z)
    fa[x]=px;                           //·��ѹ��
  }
  return fa[x];
}

void Union(int x, int y, int d)
{
  int px=Find(x);
  int py=Find(y);
  if(px!=py)
  {
    fa[py]=px;
    Rank[py]=Rank[x]^Rank[y]^d;          //yesͬ�࣬noΪ����
  }
}

int main()
{
  int m,p,q,x,y;
  while(scanf("%d%d%d",&m,&p,&q)==3 && m || p || q)
  {
    memset(sets, 0, sizeof(sets));
    memset(path, 0, sizeof(path));
    memset(tag, 0, sizeof(tag));
    memset(man, 0, sizeof(man));
    for(int i=1; i<=p+q; i++)
    {
      Rank[i]=0;                         //Rank=0��ʾͬ�࣬=1��ʾ����
      fa[i]=i;                           //���鼯��ʼ��
    }
    while(m--)
    {
      char ch[5];
      scanf("%d%d%s", &x, &y, ch);
      Union(x, y, ch[0]=='y' ? 0 : 1);
    }
    int tot=0;
    for(int i=1; i<=p+q; i++)             //ͳ��������ɵĲ��鼯�������ұ��
      if(Find(i)==i)                      //�������������˵���Ѿ�������ļ�����
        sets[i]=++tot;
    for(int i=1; i<=p+q; i++)             //ͳ��ÿ���������������Ŀ���洢��tag��
      tag[sets[Find(i)]][Rank[i]]++;      //��Find(i)�ҵ�i���ڵ�sets����
    int dp[MAXN][MAXN]= {1};                          //dp[i][j]:��ǰi��������ѡ��j�����˵ķ�����
    for(int i=1; i<=tot; i++)             //ö��ÿ������
      for(int j=0; j<=p+q; j++)           //ö��j
      {
        if(j-tag[i][0]>=0 && dp[i-1][j-tag[i][0]])//������������1��
        {
          dp[i][j]+=dp[i-1][j-tag[i][0]];
          path[i][j]=tag[i][0];           //�����¼·������ѡ����1����0
        }
        if(j-tag[i][1]>=0 && dp[i-1][j-tag[i][1]])
        {
          dp[i][j]+=dp[i-1][j-tag[i][1]];
          path[i][j]=tag[i][1];
        }
      }
    if(dp[tot][p]!=1)                     //����ҵ��ķ�������Ψһ
      printf("no\n");
    else
    {
      for(int i=tot,j=p; j>0 && i>0; i--) //���Ƴ����·��
      {
        if(path[i][j]==tag[i][0])
          man[i][0]=1;
        else
          man[i][1]=1;
        j-=path[i][j];
      }
      for(int i=1; i<=p+q; i++)
        if(man[sets[Find(i)]][Rank[i]])
          printf("%d\n", i);
      printf("end\n");
    }
  }
  return 0;
}
