//������ĸ߾����㷨1
#include <bits/stdc++.h>
using namespace std;

long long save[10000][10000];

long long  Combin(int m,int n)
{
  if(n==0||m==n ||m==0)
    return 1;
  if (save[m][n]>0)//�Ż����������c(n,m),��ֹͣ��ȵݹ飬ֱ�����ü���
    return save[m][n];
  save[m][n]=Combin(m-1,n)+Combin(m-1,n-1);
  return save[m][n];
}

main()
{
  //freopen("combin.in","r",stdin);
  //freopen("combin.out","w",stdout);
  int m,n,t;
  cin>>m>>n;
  m+=n-2;
  n--;
  cout<<Combin(m,m-n<n?m-n:n)<<endl;  //C(m,n)=C(m,m-n),�˴��������Ż�Ч��
  return 0;
}
