//��Ϣ���� -����2
#include <bits/stdc++.h>
using namespace std;

bool a[255];                         //ͳ��ÿ��������

int main()
{
  //freopen("Msg.in","r",stdin);
  //freopen("Msg.out","w",stdout);
  int n,x,ans=0;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&x);
    while(x)                         //��ȡ��������ֱ��0
    {
      a[x]=true;                     //���Ϊ��,˵�������˴������ϸ�x
      scanf("%d",&x);
    }
  }
  for(int i=1; i<=n; i++)
    if(!a[i])                        //������Ϊ0,�𰸼�1
      ans++;
  printf("%d\n",ans==0?1:ans);
  return 0;
}

