//���������
#include<bits/stdc++.h>
using namespace std;

long long a[500001],n,Stack[500001],l,r;

int main()
{
  //freopen("rectangle.in","r",stdin);
  //freopen("rectangle.out","w",stdout);
  while(cin>>n && n)
  {
    for(int i=1; i<=n; i++)
      cin>>a[i];
    a[n+1]=-1;
    int top=0,ans=0;
    memset(Stack,0,sizeof(Stack));
    for(long long i=1; i<=n+1; i++)
    {
      for(; top!=0 && a[Stack[top]]>=a[i]; top--)  //���ΪL-R+1
      {
        long long tmp=((i-1)-Stack[top-1])*a[Stack[top]];//�ұ߽���i-1����Ϊi���ұߵ�һ������С����
        if(tmp>ans)                                      //��߽���top,��Ϊ��ջ����������ǵ�һ������С����
          ans=tmp;
      }
      Stack[++top]=i;
    }
    cout<<ans<<endl;
  }
  return 0;
}

