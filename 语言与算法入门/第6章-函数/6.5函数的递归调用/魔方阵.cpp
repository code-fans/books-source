//ħ����
#include<bits/stdc++.h>
using namespace std;
int a[10]= {0,0,0,0,0,5,0,0,0,0},j,num=0;

int fun(int m)
{
  int i;
  if(m==5)
  {
    for(j=1; j<=3; ++j)//���ħ�����Ƿ����
      if(a[j]+a[j+3]+a[j+6]!=15 || a[3*j]+a[3*j-1]+a[3*j-2]!=15)
        return 0;
    printf("%d%d%d\n",a[1],a[2],a[3]);//�������������
    printf("%d%d%d\n",a[4],a[5],a[6]);
    printf("%d%d%d\n\n",a[7],a[8],a[9]);
    ++num;
  }
  else
    for(i=1; i<=9; ++i)//ö��9������
    {
      if(a[i]==0)//����ø���δ����
      {
        a[i]=m;//�ø�������
        a[10-i]=10-m;//��Ӧ��������
        fun(m+1);//�ݹ�����һ����
        a[i]=0;//ע��˴�Ҫ�ָ�,�����޷�������������
        a[10-i]=0;
      }
    }
}

int main()
{
  int m=1;
  fun(m);
  printf("%d\n",num);
  return 0;
}

