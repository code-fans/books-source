#include <map>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define M 50005

map<char,char>mm;
vector<int>G[150];

int n, cnt;
int in[150], use[150];

string s[M], sim, ans;

int main()
{
// //freopen("break.in","r",stdin);
  //freopen("break222.out","w",stdout);
  scanf("%d", &n);
  for(int i = 1; i <= n; i ++)
    cin>>s[i];
  cin>>sim;
  for(int i = 2; i <= n; i ++)
  {
    int len = min(s[i].length(), s[i-1].length());
    for(int j = 0; j < len; j ++)
    {
      if( s[i][j] != s[i-1][j] )
      {
        G[s[i-1][j]-'a'+1].push_back(s[i][j]-'a'+1);//����
        in[s[i][j]-'a'+1] ++;//���++
        use[s[i][j]-'a'+1] ++;
        use[s[i-1][j]-'a'+1] ++;
        break;//ֻ�ܱȽϵ�һ����ͬ��ĸ
      }
    }
  }
  for(int i = 1; i <= n; i ++)
  {
    if( use[i] )
      cnt ++;
  }
  for(int i = 1; i <= cnt; i ++)
  {
    int j = 1;
    while( j < 27 && (in[j] || !use[j]) )
      j ++;
    if( j > 26 ) //�����ȶ���Ϊ0����û��һ����ĸ�ж�Ӧ����ȷ��ĸ
    {
      printf("0\n");
      return 0;
    }
    mm[j+'a'-1] = 'a'+i-1;//ӳ��
    in[j] = -1;
    int siz = G[j].size();
    for(int k = 0; k < siz; k ++)
    {
      int son = G[j][k];
      in[son] -- ;
    }
  }
  for(int i = 0; i < sim.length(); i ++)
  {
    if( !mm[sim[i]] ) //û�ж�Ӧ��ĸ
    {
      printf("0\n");
      return 0;
    }
    ans[i] = mm[sim[i]];//ӳ��
  }
  for(int i = 0; i < sim.length(); i ++)//�����sim��Ϊans�����䲻����
    cout<<ans[i];//printf("%s\n",ans);Ҳ���У�������Ϊʲô
  return 0;
}

