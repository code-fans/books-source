#include <bits/stdc++.h>
using namespace std;
const int MAXN =505;

bool w[MAXN][MAXN]; //w[i][j]����i������ͷ�ܷ񿴵�j������ͷ
int camera[MAXN]; //camera[i]������i��λ������û������ͷ
int ind[MAXN]; //ind[i]��¼i������ͷ����ȣ�Ҳ�����м�������ͷ�ܿ���i������ͷ��

int main()
{
  int n,k,s,x,ans=0;//ans��¼���ҵ�������ͷ����
  cin >> n;
  for(int i=1; i<=n; i++)
  {
    cin >> s >> k;
    camera[s]=1;//���a����
    for(int j=1; j<=k; j++)
    {
      cin >> x;
      ind[x]++;//x������ͷ�����++
      w[s][x]=1;
    }
  }
  for(int b=1; b<=100; b++)
    for(int i=1; i<=500; i++)
      if(camera[i]==1 && ind[i]==0)//���i������ͷ���Ϊ0
      {
        ans++;
        camera[i]=0;
        for(int j=1; j<=500; j++)
        {
          if(w[i][j])
            ind[j]--;
        }
      }
  ans==n? cout << "YES\n": cout << n-ans<<endl;
  return 0;
}
