//���б任
#include <bits/stdc++.h>
using namespace std;

long long a[1000005],t[1000005];

inline int Read()                        //���ַ�����ʽ�������ֿ�����
{
  int x=0,f=1;
  char c=getchar();
  for(; c<'0'  || c>'9';  c=getchar())
    if(c=='-')
      f=-1;
  for(; c<='9' && c>='0'; c=getchar())
    x=(x<<3)+(x<<1)+c-'0';               //λ�����Ż���x*8+x*2=x*10
  return f*x;
}

int main()
{
  freopen("change.in","r",stdin);
  freopen("change.out","w",stdout);
  int n,m,x,y,ans;
  n=Read();
  m=Read();
  for (int i=1; i<=n; i++)
    a[i]=Read();
  for (int i=1,opt; i<=m; i++)
  {
    opt=Read();
    if (opt==1)
    {
      x=Read();
      y=Read();
      t[x]+=y;//ֻ�ڵ�ǰλ��y
    }
    else
    {
      x=Read();
      ans=a[x];
      for (int j=sqrt(x); j>=1; j--)//����ö������
      {
        if (x%j==0)
          if (j*j!=x)
            ans+=t[j]+t[x/j];//��ʱ�������֮ǰ��yֵ
          else
            ans+=t[j];//ƽ����Ҫ���У��������������Ӷ�Ҫ�ۼ�
      }
      printf("%d\n",ans);
    }
  }
  return 0;
}
