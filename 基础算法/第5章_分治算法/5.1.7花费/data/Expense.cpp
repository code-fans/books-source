//���� �����ַ�
#include <bits/stdc++.h>
using namespace std;

int data[100010];
int n,m,high,low,mid;

bool Judge()
{
  int temp = 0;
  int plan = 1;
  for (int i = 1; i <= n; i++)//���԰���ǰ����ͳ��
  {
    temp += data[i];          //�ۼ������εĻ���
    if (temp > mid)           //������ѳ��ƻ�
    {
      plan++;
      temp = data[i];         //�ؿ�һ��
    }
  }
  return plan>m?1:0;
}

int main()
{
  //freopen("Expense.in","r",stdin);
  //freopen("Expense.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&data[i]);
    high += data[i];
    low=max(low,data[i]);
  }
  while (low <= high)
  {
    mid=(low+high)>>1;
    Judge()?low=mid+1:high=mid-1;
  }
  printf("%d\n",low);
  return 0;
}
