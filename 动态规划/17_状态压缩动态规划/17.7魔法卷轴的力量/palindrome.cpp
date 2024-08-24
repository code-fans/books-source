#include<bits/stdc++.h>
using namespace std;
const int MAXN=65537;

string str;
int dp[MAXN],cycle[MAXN],tot;//cycle�Ǵ�������Ļ��������У�tot��¼����

bool Check(int x)                //�ж�x״̬�Ƿ�Ϊ����
{
  char t[MAXN];
  int cnt=0,len=str.length();
  for(int i=0; i<len; i++)
    if(x>>i&1)
      t[cnt++]=str[len-i-1];
  for(int l=0,r=cnt-1; l<r; ++l,--r)
    if(t[l]!=t[r])
      return 0;
  return 1;
}

int main()
{
  //freopen("palindrome.in","r",stdin);
  //freopen("palindrome.out","w",stdout);
  int N;
  cin>>N;
  while(N--)
  {
    tot=0;                         //totΪ�ҵ��Ļ���������
    memset(dp,0x3F,sizeof(dp));
    cin>>str;
    int maxx=(1<<str.length())-1;
    for(int i=1; i<=maxx; i++)
      if(Check(i))
      {
        dp[i]=1;
        cycle[++tot]=i;               //�����ҵ��Ļ��Ĵ�
      }
    for(int i=1; i<=maxx; i++)        //ö������״̬
      for(int j=1; j<=tot; j++)       //ö�����л�����
        if((i&cycle[j])==0)           //���i���ڵ�ǰ״̬��
          dp[i|cycle[j]]=min(dp[i|cycle[j]],dp[i]+1);//i��״̬��cycle[j]����dp[i]+1
    cout<<dp[maxx]<<endl;
  }
  return 0;
}

//�ö���������ʾһ�����Ƿ��Ѿ�ɾȥ��1Ϊɾȥ��0Ϊδɾ
//dp[s]��ʾ��s��ת��Ϊ�����ƣ�������£�������Ҫ����
//Ԥ��������л��������м�¼�������ɰѶ�Ӧ��dp[s]�ĳ�1��������ϵ��ֻ��һ�ξ�����ɣ�
//���ǵ�Ŀ���Ǵ�0���1111.....
//�ַ�������Ϊlen�Ļ�
//����Ҫ��Ŀ��״̬����1<<len-1��λ���㣩
//�糤��Ϊ4��Ŀ��Ϊ10000-1=1111
//����0��1<<len-1�������״̬��Ԥ���������״̬�ϲ����õ��µ�״̬,��״̬�Ĳ����͵���ԭ״̬+1
//dp[i]��ʾ��״̬i���ٲ���
//DFSҲ����
