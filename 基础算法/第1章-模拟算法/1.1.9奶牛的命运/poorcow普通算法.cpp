//��ţ������
#include <bits/stdc++.h>
using namespace std;

int T,n,Cyc[1010],del[1010];

int GCD(int m,int n)
{
  return n==0?m:GCD(n,m%n);
}

int main()
{
  //freopen("poorcow.in","r",stdin);
  //freopen("poorcow.out","w",stdout);
  scanf("%d", &T);
  while(T--)
  {
    scanf("%d", &n);
    vector<int> cow[1010];
    for(int i=0; i<n; i++)
    {
      scanf("%d", &Cyc[i]);      //����������
      for(int j=0,t; j<Cyc[i]; j++)
      {
        scanf("%d", &t);
        cow[i].push_back(t);
      }
    }
    int count=Cyc[0];
    for(int i=1; i<n; i++)//���������ڵ���С������
      count=count*Cyc[i]/GCD(count,Cyc[i]);
    int last = -1, cnt = n;
    memset(del, 0, sizeof(del));
    for(int k=0; k<=count*2 && cnt!=0; k++)//��С��������2��
    {
      int Minpos = -1, Min = 0x7FFFFFFF;
      for(int i=0; i<n; i++)
      {
        if(del[i])  continue;
        int temp= cow[i][k%Cyc[i]];
        if(Min==temp)
          Minpos = -1;
        if(Min>temp)
        {
          Min = temp;
          Minpos = i;     //���²���������ţ��
        }
      }
      if(Minpos!=-1)      //v���ֻ��һֻ��ţ��������
      {
        del[Minpos] = 1;  //����ţ����
        last = k;
        cnt--;
      }
    }
    printf("%d %d\n", cnt, last+1);
  }
  return 0;
}

