//ǰ���������
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30;

int C[MAXN][MAXN];
char pre[MAXN],post[MAXN];
int n,m;

void Init()                           //Ԥ����C(m,n)��ֵ
{
  for(int i=0; i<MAXN; i++)
    C[i][0] = 1;
  for(int i=1; i<MAXN; i++)
    for(int j=1; j<=i; j++)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
}

long long DFS(int L1,int R1,int L2,int R2)
{
  if(L1==R1)
    return 1;
  int son=0;                          //ͳ���ж��ٸ�����
  long long ans=1;
  int root=L2;                        //��������L2��ʼѰ��
  for(int l=L1+1; l<=R1;)             //L1+1��������
  {
    for(; root<R2; root++)            //ɨ��Ѱ�������ĸ�
      if(pre[l]==post[root])          //�ҵ���������
      {
        son++;
        break;
      }
    ans*= DFS(l, l+root-L2, L2, root);//�ݹ��ҵ�����һ������
    l+=root-L2+1;                     //��һ��������
    L2=++root;                        //��һ����������L2λ�ÿ�ʼ����
  }
  return ans*C[m][son];
}

int main()
{
  //freopen("PrePost.in","r",stdin);
  //freopen("PrePost.out","w",stdout);
  Init();
  while(scanf("%d",&m) && m)
  {
    scanf("%s %s",pre,post);
    cout<<DFS(0,strlen(pre)-1,0,strlen(pre)-1)<<endl;
  }
  return 0;
}
