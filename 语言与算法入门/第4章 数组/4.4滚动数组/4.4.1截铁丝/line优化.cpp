//����˿-�������鷨
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("line.in","r",stdin);
  freopen("line.out","w",stdout);
  long long d[3]= {1,1};
  int total,i,sum=2;    //sumΪ�ѽص���˿���Ⱥͣ�������2
  scanf("%d",&total);
  for(i=2; ; i++)
  {
    d[i%3]=d[(i-1)%3]+d[(i-2)%3];
    if(total-sum>=d[i%3])
      sum+=d[i%3];      //�Ѿ���ȥ����˿�ܳ�
    else
      break;
  }
  printf("%d\n",i);
  return 0;
}

