//game
#include <bits/stdc++.h>
using namespace std;
int f[200][200];

int main()
{
  //freopen("game.in","r",stdin);
  //freopen("game.out","w",stdout);
  int n,m,k,s;
  int a[105],b[105];
  while(~scanf("%d%d%d%d",&n,&m,&k,&s))
  {
    memset(f,0,sizeof(f));
    for(int i=1; i<=k; i++)
      scanf("%d%d",&a[i],&b[i]);
    for(int i=1; i<=k; i++)                      //����ÿ����Ʒ�����
      for(int v=1; v<=s; v++)                    //�����������ˢ��Ϊ��ȫ����
        for(int u=b[i]; u<=m; u++)               //�������̶�
          f[v][u]=max(f[v][u],f[v-1][u-b[i]]+a[i]);
    int flag=-1;
    for(int u=0; u<=m; u++)                      //�ȱ������Ͷ�,��Ϊ���Ͷ����Ⱦ�����
      for(int v=1; v<=s; v++)                    //�ٱ���ɱ����
        if(f[v][u]>=n)                           //�����������
        {
          flag=m-u;
          u=m+1;
          break;
        }
    printf("%d\n",flag);
  }
  return 0;
}

