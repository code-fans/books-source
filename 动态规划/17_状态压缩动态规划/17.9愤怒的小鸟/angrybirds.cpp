//��ŭ��С��
#include <bits/stdc++.h>
using namespace std;

double x[20],y[20];               //�������
int Bird[405],f[1048580];

int main()
{
  //freopen("angrybirds.in","r",stdin);
  //freopen("angrybirds.out","w",stdout);
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n,m,cnt=0;                 //cntͳ�Ʒ�������
    memset(Bird,0,sizeof(Bird));
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
      scanf("%lf%lf",&x[i],&y[i]);
    for(int i=1; i<=n; ++i)        //ö�����е�������
      for(int j=i+1; j<=n; ++j)
        if(x[i]!=x[j])             //�Ż���xֵ��ͬ�������겻������ͬһ��������
        {
          double a=(x[i]*y[j]-x[j]*y[i])/(x[j]*x[i]*x[j]-x[j]*x[i]*x[i]);
          double b=(x[i]*y[j]*x[i]-x[j]*x[j]*y[i])/(x[j]*x[i]*x[i]-x[j]*x[j]*x[i]);
          if(a<0)
          {
            ++cnt;                 //��������һ
            for(int k=1; k<=n; ++k)
              if(fabs(a*x[k]*x[k]+b*x[k]-y[k])<1e-6)//����������kֻ��
                Bird[cnt]+=1<<k-1;
          }
        }
    memset(f,0x3f,sizeof(f));     //f[i]��ʾ�ﵽi״̬��Ҫ�����ٷ�����
    f[0]=0;
    for(int i=0; i<(1<<n); ++i)   //��С����ö��ÿ��״̬
    {
      for(int j=1; j<=cnt; ++j)   //ö�ٷ���
        f[i|Bird[j]]=min(f[i]+1,f[i|Bird[j]]);
      for(int j=1,t=1; j<=n; t=1<<j,++j)//ö����һֻ��
        f[i|t]=min(f[i]+1,f[i|t]);
    }
    printf("%d\n",f[(1<<n)-1]);
  }
  return 0;
}

