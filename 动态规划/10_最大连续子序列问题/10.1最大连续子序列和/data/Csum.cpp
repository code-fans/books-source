//����������к�
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("Csum.in","r",stdin);
  //freopen("Csum.out","w",stdout);
  int n,s[100005]= {0},a[100005]= {0},MAX=-2147483647;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    cin>>a[i];
    s[i]=s[i-1]+a[i];
    MAX=max(MAX,a[i]);      //�ҵ����ֵ��Ԫ��
  }
  int Min=a[1],ans=a[1];    //Min�������浽ĿǰΪֹ��Ԫ����Сֵ
  for(int i=1; i<=n; i++)
  {
    Min=min(Min,s[i]);      //min(a,b)�ɵõ�a,b����Сֵ
    ans=max(ans,s[i]-Min);  //�������ֵ��ans
  }
  printf("%d\n",ans?ans:MAX);//Ԫ�����ȫ�Ǹ�������������Ԫ��
  return 0;
}

