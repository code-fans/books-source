//�ǵݹ���۰���ҷ�
#include <bits/stdc++.h>
using namespace std;

int key,n,a[10010];

void Half()                              //���ֲ��ҷ�
{
  int Left=1;
  int Right=n;
  while (Left<=Right)
  {
    int mid=(Right+Left)>>1;
    if (key==a[mid])                     //��������ҵ�
    {
      printf("%d\n",mid);
      exit(0);
    }
    else if (key<a[mid])                 //ѡ������
      Right=mid-1;
    else                                 //ѡ���Ұ��
      Left=mid+1;
  }
  puts("-1");
}

int main ()
{
  //freopen("half.in","r",stdin);
  //freopen("half.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  cin>>key;
  Half();
  return 0;
}

