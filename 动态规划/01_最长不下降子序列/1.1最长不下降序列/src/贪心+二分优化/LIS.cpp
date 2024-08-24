//����½�������- �����Ż�
#include<bits/stdc++.h>
using namespace std;

int f[100005], c[100005], a[100005];

int main()
{
  freopen("LIS.in","r",stdin);
  freopen("LIS.out","w",stdout);
  int n,longest=1;
  scanf("%d", &n);
  for(int i=1; i<=n; ++i)
    scanf("%d", &a[i]);
  f[1]=a[1];
  c[1]=1;
  for(int i=2; i<=n; ++i)
  {
    if(f[longest]<=a[i])
    {
      f[++longest]=a[i];
      c[i]=longest;
    }
    else
    {
      int j=upper_bound(f+1,f+longest+1,a[i])-f;
      f[j]=a[i];
      c[i]=j;
    }
  }
  printf("%d\n", longest);
  //�����LIS��Ԫ��
  stack <int> st;        //ʹ�ö�ջ�������LIS��Ԫ��
  for(int i=n, j=longest; i>=1 && j!=0; --i)
    if(c[i]==j)
    {
      st.push(a[i]);
      --j;
    }
  while(!st.empty())     //˳�����
  {
    printf("%d ", st.top());
    st.pop();
  }
  return 0;
}
