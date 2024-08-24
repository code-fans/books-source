//����
#include <bits/stdc++.h>
using namespace std;

int father[20001];
int n,m,q,x,y;

int Find(int x)
{
  while(father[x]!=x)
    x=father[x];        //·��ѹ��
  return x;
}

void Union(int X,int Y)//�ϲ���������
{
  father[Y]=X;
}

int main()
{
  //freopen("relation.in","r",stdin);
  //freopen("relation.out","w",stdout);
  cin>>n>>m>>q;
  for(int i=1; i<=n; i++) //��ʼ��
    father[i]=i;//�����µļ��ϣ�����еĳ�Ա��i
  for(int i=1; i<=m; i++)
  {
    scanf("%d%d",&x,&y);
    int X=Find(x);
    int Y=Find(y);
    if(X!=Y)
      Union(X,Y);
  }
  for(int i=1; i<=q; i++)
  {
    scanf("%d%d",&x,&y);
    printf("%s\n",Find(x)==Find(y)?"YES":"NO");
  }
  return 0;
}
