//�ϲ�ʯ��2 - �ı��β���ʽ�Ż�
#include <bits/stdc++.h>
using namespace std;
#define N 2005

int n,Num,a[N],sum[N];
int S[N][N],Fmin[N][N],Fmax[N][N];

void Init()
{
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&a[i]);
    a[n+i]=a[i];                                   //��ת��˫��������
    sum[i]=sum[i-1]+a[i];                          //����ǰ���
    S[i][i]=i;
    S[n+i][n+i]=n+i;
  }
  Num= n<<1;                                       //��2*n
  for(int i=n+1; i<=Num; i++)                      //�����������ǰ���
    sum[i]=sum[i-1]+a[i];
}

int main()
{
  freopen("merge2.in","r",stdin);
  freopen("merge2.out","w",stdout);
  Init();
  for(int i=Num-1; i>0; i--)
    for(int j=i+1; j<=Num; j++)
    {
      int t=0x3fffffff,Min=0;
      Fmax[i][j]=max(Fmax[i][j-1],Fmax[i+1][j])+sum[j]-sum[i-1];
      for(int k=S[i][j-1]; k<=S[i+1][j]; k++)      //��Сȡֵ��Χ����Сֵ
      {
        int temp=Fmin[i][k]+Fmin[k+1][j]+(sum[j]-sum[i-1]);
        if(temp<t)
        {
          t=temp;
          Min=k;
        }
      }
      S[i][j]=Min;
      Fmin[i][j]=t;
    }
  int Ans1=0,Ans2=0x3fffffff;
  for(int i=1; i<=n; i++)
  {
    Ans1=max(Ans1,Fmax[i][i+n-1]);
    Ans2=min(Ans2,Fmin[i][i+n-1]);
  }
  printf("%d\n%d\n",Ans2,Ans1);
  return 0;
}

