//�����Ƶļӷ�
#include <bits/stdc++.h>
using namespace std;

int n,a,b,c,n9,sum;               //n9��ʾ֮ǰ���۵�9�ĸ�������ʼΪ0

int main()
{
  freopen("add3.in","r",stdin);
  freopen("add3.out","w",stdout);

  scanf("%d",&n);
  bool first=1;
  for(int i=1; i<=n; i++)         //�Ӹ�λ��ʼ�����δ���ÿһλ
  {
    scanf("%d%d",&a,&b);
    sum=a+b;
    if(sum<9)                     //�޽�λ���
    {
      if(c>0||first==0)           //����ǰ��0
        printf("%d",c);
      for(int j=1; j<=n9; j++)    //��Ϊ��λ�޽�λ����ɽ�֮ǰ���۵�999..99���
        printf("9");
      first=0;
      n9=0;                       //���۵�999...999������������Ϊ0
      c=sum;
    }
    else if(sum==9)               //Ϊ9ʱ��ֻҪ��¼9�ĸ���
      n9++;
    else                          //����9����������λ���
    {
      printf("%d",++c);           //��λ�����
      for(int j=1; j<=n9; j++)    //��Ϊ��λ,��ǰ����۵�999..99��000...000���
        printf("0");
      first=0;
      n9=0;
      c=sum-10;                   //c��¼��λ����λ�����µ���
    }
  }

  printf("%d",c);                 //����ʣ�µ�һ��999...999
  for(int j=1; j<=n9; j++)
    printf("9");
  printf("\n");
  return 0;
}

