//ͨ����
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int h,a,c;
} stone[405];
bool dp[40005];//dp[i]��ʾ�ø߶��Ƿ�ﵽ

bool Cmp(node a,node b)
{
  return a.a<b.a;
}

int main()
{
  //freopen("Elevator.in","r",stdin);
  //freopen("Elevator.out","w",stdout);
  int k;
  cin>>k;
  for(int i=0; i<k; i++)
    scanf("%d%d%d",&stone[i].h,&stone[i].a,&stone[i].c);
  sort(stone,stone+k,Cmp);
  dp[0]=1;
  for(int i=0; i<k; i++)                       //ö��ʯͷ
    for(int j=0; j<stone[i].c; j++)            //ö��j��ʯͷ������
      for(int h=stone[i].a; h>=stone[i].h; h--)//ö�ٸ߶�
        dp[h]|=dp[h-stone[i].h];               //dp[h]��dp[h-stone[i].hΪ��
  for(int i=stone[k-1].a; i>=0; i--)
    if(dp[i])
    {
      cout<<i<<endl;
      return 0;
    }
  return 0;
}

