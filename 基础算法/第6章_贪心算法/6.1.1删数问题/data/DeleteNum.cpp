//ɾ����Ϸ
#include <bits/stdc++.h>
using namespace std;

void Delete_Num(char str[],int n,int k)
{
  while(k--)
  {
    int i=0;
    for(; i<n && str[i]<=str[i+1]; i++);     //��λ
    for(int j=i; j<n; j++)
      str[j]=str[j+1];
  }
}

int main()
{
  freopen("DeleteNum.in","r",stdin);
  freopen("DeleteNum.out","w",stdout);
  int k;
  char str[300];
  while(scanf("%s%d",str,&k)!=EOF)
  {
    int len=strlen(str);
    Delete_Num(str,len,k);
    for(int i=0; i<len-k; i++)
      printf("%c",str[i]);
    printf("\n");
  }
  return 0;
}
