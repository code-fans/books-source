//�ڵ���
#include <bits/stdc++.h>
using namespace std;

int a[10010],ans[10010];

int Test(int n)                      //���ƣ��ɹ�����1��ʧ�ܷ���0
{
  for(int i=2; i<=n; i++)
  {
    ans[i+1]=a[i]-ans[i-1]-ans[i];
    if(ans[i+1]<0 || ans[i+1]>1 )
      return 0;
  }
  return ans[n+1]==1? 0:1;          //�����Ӧ�ó��ֵ��׵�λ���е���
}

int main()
{
  freopen("bomp.in","r",stdin);
  freopen("bomp.out","w",stdout);
  int n;
  scanf("%d",&n);
  for (int i=1; i<=n; i++)
  {
    scanf("%d",&a[i]);
    if ((a[i]<0) || a[i]>3)       //���������ݲ��Ϸ�
    {
      cout<<"No answer\n";
      return 0;
    }
  }
  if (a[1]==1)
    ans[1]=1;
  if(a[1]==2)
    ans[1]=ans[2]=1;
  if (a[1]==1 && Test(n)==0)       //�������ʧ�ܣ�����ans[1],ans[2]
    swap(ans[1],ans[2]);
  if (Test(n)==0)
    cout<<"No answer\n";
  else
    for (int i=1; i<=n; i++)
      printf("%d%c",ans[i],i==n?'\n':' ');
  return 0;
}

