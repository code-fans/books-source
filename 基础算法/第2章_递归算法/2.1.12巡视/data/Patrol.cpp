//Ѳ��-STL
#include<bits/stdc++.h>
using namespace std;

struct node
{
  int x,y;
} w[20];                                     //��������
int T,m,a[20];

int Calc(int ans=0)                          // ���㵱ǰ·�ĳ���
{
  for(int i=0; i<m; i++)
    ans+=abs(w[a[i]].x-w[a[i+1]].x)+abs(w[a[i]].y-w[a[i+1]].y);
  ans+=abs(w[a[m]].x-w[a[0]].x)+abs(w[a[m]].y-w[a[0]].y);
  return ans;
}

int main()
{
  //freopen("Patrol.in","r",stdin);
  //freopen("Patrol.out","w",stdout);
  scanf("%d",&T);
  while(T--)
  {
    scanf("%*d%*d%d%d%d",&w[0].x,&w[0].y,&m);//��ʼ2��ֵ����
    for(int i=1; i<=m; i++)
      scanf("%d%d",&w[i].x,&w[i].y);
    for(int i=1; i<=m; i++)                  //a[i]��ʼ���������
      a[i]=i;
    int ans=1e10;
    do                                       //ö��ÿһ�����
      ans=min(ans,Calc());
    while(next_permutation(a+1,a+1+m));
    printf("The shortest path has length %d\n",ans);
  }
  return 0;
}
