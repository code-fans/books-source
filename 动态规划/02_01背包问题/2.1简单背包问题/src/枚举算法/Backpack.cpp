//��ͨ��������-ö���㷨
#include <bits/stdc++.h>
using namespace std;

int N,S;
int W[40],use[40];

int main()
{
  freopen("Backpack.in","r",stdin);
  freopen("Backpack.out","w",stdout);
  cin>>S>>N;
  for(int i=0; i<N; i++)
    cin>>W[i];
  for(int num=0; num<(1<<N); num++) //2��N�η������
  {
    int sum=0;
    memset(use,0,sizeof(use));
    for(int i=0; i<N; i++)
      if((1<<i) & num)              //�����ǰλ��1
      {
        sum+=W[i];
        use[i]=1;
      }
    if(sum==S)                      //��ӡ����
    {
      for(int i=0; i<N; i++)
        if(use[i])
          cout<<W[i]<<endl;
      exit(0);
    }
  }
  cout<<"Failed!\n";
  return 0;
}
