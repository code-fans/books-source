//ð�����򷨵ĸĽ� - ��һ�������޷�ͨ�����ԣ����ҳ��������ڲ����
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
  int n;
  cin>>n;
  int a[n+1];//�ɶ�̬���������С,������ͬʱ��ֵ,��int a[n+1]={0};
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  int k=2,LastSwap;//k����������˵�λ�ã�LastSwapΪ��󽻻���λ��
  while(k<n)//�����a[k]��λ��С���Ҷ�a[n]��λ��,��������Ҫ�Ƚ�
  {
    LastSwap=n;            //���趨��һ��ɨ����󽻻�λ��Ϊn
    for(int j=n; j>=k; j--)//�Ӻ���ǰɨ�赽k����ǰ���ɨ��Ҳһ����
      if(a[j]<a[j-1])      //������������ǰ�����С
      {
        swap(a[j],a[j-1]); //����a[j]��a[j-1]��ֵ
        LastSwap=j;        //��¼���ı��λ��
      }
    k=LastSwap;            //��һ��ֻ��Ƚϵ���һ�ֵ�LastSwap
  }
  for(int i=1; i<n; i++)
    printf("%d ",a[i]);
  printf("%d\n",a[n]);
  return 0;
}

