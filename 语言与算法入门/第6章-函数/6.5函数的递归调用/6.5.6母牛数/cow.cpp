//ĸţ��
#include<bits/stdc++.h>
using namespace std;
typedef long long ULL;//typedef����long long�ı���ΪULL

ULL num[65];          //�˴���long long�Ϳɱ�ʾΪULL

ULL Cow(int n)
{
  if(n<=4)
    return n;
  if(num[n])                 //�����ֵ֮ǰ�Ѿ����
    return num[n];           //����ݹ飬ֱ��ȡֵ
  else
    num[n]=Cow(n-1)+Cow(n-3);//�ݹ������ֵ�ȴ���num[n]
  return num[n];             //�ٷ��ؽ��num[n]
}

int main()
{
  freopen("cow.in","r",stdin);
  freopen("cow.out","w",stdout);
  int n;
  while(scanf("%d",&n)==1)
    printf("%lld\n",Cow(n));
  return 0;
}
