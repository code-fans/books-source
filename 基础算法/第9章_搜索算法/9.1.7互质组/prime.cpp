//������-ö��
#include <bits/stdc++.h>
using namespace std;

int n,a[20],Group[20],Ans=1;

int GCD(int a,int b)
{
  return a%b==0 ? b : GCD(b,a%b);
}

int main()
{
  freopen("prime.in","r",stdin);
  freopen("prime.out","w",stdout);
  for(int i=0; i<20; i++)
    Group[i]=1;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  Group[1]=a[1];
  for(int i=2,g; i<=n; i++)      //ö��ÿ����
  {
    for(g=1; g<=Ans; g++)        //ö��ÿһ�飬�ܼӾͼ�
      if(GCD(a[i],Group[g])==1)
      {
        Group[g]*=a[i];
        break;
      }
    if(g-1==Ans)                 //����Ӳ���ȥ
      Group[++Ans]=a[i];         //�Խ�һ��
  }
  printf("%d\n",Ans);
  return 0;
}
