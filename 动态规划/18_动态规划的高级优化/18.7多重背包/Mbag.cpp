//���ر��� �����������Ż�
#include<bits/stdc++.h>
using namespace std;

int f[210],q[210],k[210];

int main()
{
  //freopen("Mbag.in","r",stdin);
  //freopen("Mbag.out","w",stdout);
  int N,V,head,tail,v,w,c;
  scanf("%d%d",&V,&N);
  for(int i=1; i<=N; i++)
  {
    scanf("%d%d%d",&v,&w,&c);
    int a=c>V/v?V/v:c;                     //��ȡ��������
    for(int b=0; b<v; b++)                 //ö������
    {
      head=tail=1;
      for(int t=0; t<=(V-b)/v; t++)//ö��t,���ǽ�(V-b)/v��ΪV/v����a�Ƿ����
      {
        int tmp=f[b+t*v]-t*w;
        while(head<tail && q[tail-1]<=tmp)
          tail--;
        q[tail]=tmp;
        k[tail++]=t;
        while(head<tail && t-k[head]>a)    //�������䳤�Ȳ�����a
          head++;
        f[t*v+b]=max(f[b+t*v],q[head]+t*w);//q[]�����f[t*v+b]-t*w,����+t*w
      }
    }
  }
  printf("%d\n",f[V]);
  return 0;
}

