//��¥��
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("stairs.in","r",stdin);
  //freopen("stairs.out","w",stdout);
  unsigned long long F[75]= {0,1,2,4};
  for(int i=4; i<=73; i++)
    F[i]=F[i-3]+F[i-2]+F[i-1];
  for(int n; scanf("%d",&n)!=EOF;)//EOF��ʾ�ļ�ĩβ
    printf("%llu\n",F[n]);        //ע��unsigned long long�ĸ�ʽ����
  return 0;
}

