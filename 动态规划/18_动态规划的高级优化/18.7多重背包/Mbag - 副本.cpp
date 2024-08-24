//���ر��� - ���������Ż�
#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int T,n,m,v,w,tot,q1[N],q2[N],f[N];

void DP(int v,int w,int tot)          //totΪ��ǰ��Ʒ�ĸ���
{
  for (int i=0; i<v; i++)
  {
    int st=0,ed=0;                    //������ָ�룬βָ��
    q1[0]=q2[0]=0;                    //�������У�q1[]��������±꣬q2[]������ڵ�ֵ
    for (int j=0; j<=(m-i)/v; j++)
    {
      //f[i+j*v[i]]=max{f[i+k*v[i]]+k*w[i]}+j*w[i](j-tot<=k<=j)
      if (st<=ed && q1[st]<j-tot) st++;  //j-tot<=k<=j
      int t=f[i+j*v]-j*w;		           //�����д�f[i+j*v]-j*w
      f[i+j*v]=max(f[i+j*v],q2[st]+j*w); //����f[i+j*v]
      while (st<=ed && t>=q2[ed])
        ed--;	                        //��j�������
      q1[++ed]=j;
      q2[ed]=t;
    }
  }
}

int main()
{
  //freopen("Mbag.in","r",stdin);
  //freopen("Mbag.out","w",stdout);
  scanf("%d%d",&m,&n);
  for(int i=0; i<=m; i++)
    f[i]=0;
  for(int i=1; i<=n; i++)
    scanf("%d%d%d",&v,&w,&tot),DP(v,w,tot);
  int mx=0;
  for(int i=1; i<=m; i++)
    mx=max(mx,f[i]);
  printf("%d\n",mx);
  return 0;
}

