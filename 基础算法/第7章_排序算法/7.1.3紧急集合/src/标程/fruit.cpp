//��������
#include <bits/stdc++.h>
using namespace std;

int n,sum,ans;
int a[20001],b[20001],t[20001];

int main()
{
  freopen("fruit.in","r",stdin);
  freopen("fruit.out","w",stdout);
  scanf("%d",&n);
  memset(a,127,sizeof(a));               //������Ԫ��ֵΪ���ֵ
  memset(b,127,sizeof(b));
  for (int i=1,k; i<=n; i++)
  {
    scanf("%d",&k);
    t[k]++;                              //��������
  }
  for (int i=1,k=0; i<=20000; i++)
    for(; t[i]; t[i]--)                  //��Ͱ��������������Ƶ�a������
      a[++k]=i;
  int k1=1,k2=1;                         //k1,k2Ϊָ�룬�ֱ�ָ��a[],b[]
  for (int i=1,k=0; i<n; i++)          //iͳ�ƺϲ�����
  {
    sum=a[k1]<b[k2] ? a[k1++] : b[k2++]; //�ҵ���һ���ϲ���ֵ
    sum+=a[k1]<b[k2] ? a[k1++] : b[k2++];//�ҵ��ڶ����ϲ���ֵ
    b[++k]=sum;                          //�ϲ���ֵ����ڶ�������
    ans+=sum;                            //ͳ�ƺϲ�ֵ
  }
  printf("%d\n",ans);
}
