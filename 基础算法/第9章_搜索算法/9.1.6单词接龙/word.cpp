//���ʽ���
#include <bits/stdc++.h>
using namespace std;

int n,Len,Max;
int used[100001],l[100001];
string s[10001];

int Find(int a, int b)        //�Ƿ��ܺϲ�
{
  for(int i=l[a]-1; i>=1; i--)
    if(s[a][i] == s[b][0])
    {
      for(int j=i+1,k=1; j<=l[a]-1; j++,k++)
        if(s[a][j] != s[b][k])//��һ����ĸ����Ⱦͷ���0
          return 0;
      return l[b]- (l[a]-i);      //ȫ��ȷ��س���
    }
  return 0;
}

void Dfs(int x)//��������
{
  for(int i = 1; i <= n; i++)
    if(used[i] < 2 && Find(x, i))//�����������ҿ��Խ���
    {
      used[i]++;//�õĴ���++
      Len += Find(x, i);//�����µ��ʵĳ���
      Dfs(i);//����������ʼ�����
      used[i]--;//����
      Len -= Find(x, i);//����
    }
  Max=max(Max,Len);
}

int main()
{
  freopen("word.in","r",stdin);
  freopen("word.out","w",stdout);
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    cin>>s[i];
    l[i] = s[i].length();//�������е��ʵĳ���
  }
  char ch;
  cin>>ch;
  for(int i = 1; i <= n; i++)
    if(s[i][0] == ch)    //����ĸ��ͬ���ܽ�
    {
      Len = l[i];        //��ʼ����
      used[i]++;
      Dfs(i);
      used[i]--;         //����
    }
  printf("%d\n", Max);
  return 0;
}
