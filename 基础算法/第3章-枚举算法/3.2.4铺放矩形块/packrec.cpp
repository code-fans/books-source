//�̷ž��ο�-DFS
#include<bits/stdc++.h>
using namespace std;

int xx[5],yy[5],ans=1000000,x[5],y[5];
bool vis[5],Used[1005];

void UpdateAns(int x,int y)//���ºͱ����
{
  if(x*y<ans)
  {
    ans=x*y;
    memset(Used,0,sizeof(Used));//��������
  }
  if(x*y==ans)
    Used[x]=Used[y]=1;
}

void Enum(int x[],int y[])//ö������״̬
{
  int X,Y;
  X=x[1]+x[2]+x[3]+x[4];               //��һ�����з�ʽ
  Y=max(max(y[1],y[2]),max(y[3],y[4]));
  UpdateAns(X,Y);

  X=max(x[1]+x[2]+x[3],x[4]);          //�ڶ������з�ʽ
  Y=max(y[1],max(y[2],y[3]))+y[4];
  UpdateAns(X,Y);

  X=max(x[1]+x[2],x[3])+x[4];          //���������з�ʽ
  Y=max(max(y[1],y[2])+y[3],y[4]);
  UpdateAns(X,Y);

  X=x[1]+max(x[2],x[3])+x[4];          //���ġ��������з�ʽ
  Y=max(y[1],max(y[2]+y[3],y[4]));
  UpdateAns(X,Y);

  Y=max(y[1]+y[3],y[2]+y[4]);          //���������з�ʽ
  if(y[1]+y[3]<=y[4])
    X=max(x[2],max(x[1],x[3])+x[4]);
  else if(y[3]<=y[4] && y[1]+y[3]>=y[4])
    X=max(x[1]+x[2],max(x[1],x[3])+x[4]);
  else if(y[3]>=y[4] && y[3]<=y[2]+y[4])
    X=max(x[1]+x[2],max(x[2],x[4])+x[3]);
  else if(y[3]>=y[2]+y[4])
    X=max(x[1],max(x[2],x[4])+x[3]);
  else if(y[3]==y[4])
    X=max(x[1]+x[2],x[3]+x[4]);
  UpdateAns(X,Y);
}

void DFS(int step)//DFS��������
{
  if(step>4)
    Enum(x,y);
  else
    for(int i=1; i<5; i++)
      if(!vis[i])
      {
        x[step]=xx[i],y[step]=yy[i],vis[i]=1;
        DFS(step+1);
        x[step]=yy[i],y[step]=xx[i];
        DFS(step+1);
        vis[i]=x[step]=y[step]=0;//�ָ�ԭ��
      }
}

int main()
{
  freopen("packrec.in","r",stdin);
  freopen("packrec.out","w",stdout);
  for(int i=1; i<=4; i++)
    scanf("%d%d",&xx[i],&yy[i]);
  DFS(1);
  printf("%d\n",ans);
  for(int i=1; i<=sqrt(ans); i++)
    if(Used[i])
      printf("%d %d\n",i,ans/i);
  return 0;
}
