//ŷ������ɸ
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;

bool a[MAXN];                   //a[i]=0��ʾi������
int prime[MAXN/3], Count;       //prime[N]��������,Count:�ҵ�����������

int main()
{
  for(int i=2; i<MAXN; i++)
  {
    if(a[i]==0)
      prime[Count++] = i;       //�������δ�����
    for(int j=0; j<Count && i*prime[j]<MAXN; j++)
    {
      a[i*prime[j]]=1;
      if(i%prime[j] == 0)       //�˴����Ż��Ĺؼ�
        break;                  //��֤ÿ������������С��������ɸȥ
    }
  }
  for(int i=0; i<Count-1; i++)
    cout<<prime[i]<<' ';
  cout<<prime[Count-1]<<endl;
  return 0;
}
