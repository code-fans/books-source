//��� 
#include <bits/stdc++.h>
using namespace std;
#define MAX 0x3f3f3f3f                    //����Ϊʲô��ȡ0x7fffffff�� 

int w[10005],l[10005],F[10005],sum[10005];//wΪ���ȣ�lΪ��߶�
int n,t,sw;

int Opt(int L,int R)                      //������������(L,R)�����߶�
{
  int W=0,h=0;
  for(int i=L; i<=R; i++)
    h=max(l[i],h) ;
  return sum[R]-sum[L-1]>sw ? MAX : h;    //�ܿ�Ȳ��ܳ�������޶�
}

int main()
{
  //freopen("book.in","r",stdin);
  //freopen("book.out","w",stdout);
  scanf("%d%d",&n,&sw);
  for(int i = 1; i <= n; i++)
  {
    scanf("%d%d",&w[i],&l[i]);
    sum[i]=sum[i-1]+w[i];                 //ǰ׺��ͳ��������Ŀ��
  }
  for(int i = 1; i <= n; i++)             //��һ����ÿһ����
  {
    F[i] = MAX;
    for(int j = i-1; j>=0; j--)
    {
      if(Opt(j+1,i)>sw)
        break;
      F[i]=min(F[i],F[j]+Opt(j+1,i));
    }
  }
  printf("%d\n",F[n]);
  return 0;
}

