#include<bits/stdc++.h>
using namespace std;

int s[30];
int l,r,n,sum;

void DFS(int dep)
{
  if(dep>n) //λ���ﵽҪ��
  {
    if(sum>0) //sum==0ʱ���������������Ǹ�������ȥ
    {
      for(int i=1; i<=n; i++)
        printf("%c",char(s[i]+'a'-1));
      printf("\n");
    }
    sum++;
    if(sum==6) exit(0);//���5�������������
    return;
  }
  if(sum>0)
    s[dep]=s[dep-1];//ǿ�Ʊ�֤��һλ���ڸ�λ��ԭ�����⣩
  for(int i=s[dep]+1; i<=r; i++)
  {
    s[dep]=i;
    DFS(dep+1);
  }
}

int main()
{
  //freopen("count.in","r",stdin);
  //freopen("count.out","w",stdout);
  char c;
  scanf("%d%d%d",&l,&r,&n);
  for(int i=1; i<=n; i++)
  {
    cin>>c;
    s[i]=c-'a';
  }
  DFS(1);//�ӵ�λ��ʼ����
  return 0;
}
