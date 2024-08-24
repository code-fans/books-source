//��������
//״̬ѹ��dp
//dp[i][s]:�������ַ���ѡȡ���Ϊsʱ����ǰ��Ϊi�ַ�������С����,i����ǰ���Ǳ���DFS���ֵ���
//����ö����һ���ַ����ɵ�״̬ת�Ʒ���
//dp[i][s | 1 << i] = min(dp[i][s | 1<< i], dp[j][s] + cost[i][j]);
//dp��Ϻ󼴿�ͨ����������������ַ��������յõ��𰸡�
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 17;
const int INF = 0x3f3f3f3f;

int n, dp[MAX][1<<MAX];//dp[i][s]:�������ַ���ѡȡ���Ϊsʱ����ǰ��Ϊi�ַ�������С����
string S[MAX], ans;
int LEN[MAX][MAX]; //LEN[i][j]��ʾ��j�ַ���ǰ�����i�ַ��������ϵ���С����

void Init()
{
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
      if(S[i].find(S[j]) != string::npos)//���S[i]������S[j]
        S[j] = S[i]; //ֻ����ĸ�����Ա�ɾ��
  stable_sort(S, S + n);
  n = unique(S, S + n) - S;
  memset(LEN, 0, sizeof(LEN));
  for(int i = 0; i < n; i++)//Ԥ����������ַ�����������Ҫ���ӵĳ���LEN[][]
    for(int j = 0; j < n; j++)
      if(i != j)
      {
        int len = min(S[i].length(), S[j].length());
        for(int k = 0; k <= len; k++)
          if(S[i].substr(S[i].length() - k) == S[j].substr(0, k))
            LEN[i][j] = S[i].length() - k;//j�ַ���ǰ�����i�ַ��������ϵ���С����
      }
}

void DFS(int id, int s)
{
  if(s!=0)
  {
    string tmp;
    int next_id = -1;
    for(int i = 0; i < n; i++)
      if(i != id && (s >> i & 1))
        if(dp[id][s] == dp[i][s & ~(1 << id)] + LEN[id][i])
        {
          string t = S[i].substr(S[id].length()-LEN[id][i],S[i].length());
          if(next_id == -1 || t < tmp)
          {
            tmp = t;
            next_id = i;
          }
        }
    ans += tmp;
    DFS(next_id, s & ~(1 << id));
  }
}

int main()
{
  //freopen("DNA1.in", "r", stdin);
  //freopen("DNA1.ans", "w", stdout);
  int T, Case = 0;
  cin >> T;
  while(T--)
  {
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> S[i];
    if(n==1)
      ans = S[0];
    else
    {
      Init();
      for(int i = 0; i <= n; i++)
        fill(dp[i], dp[i] + (1 << n), INF);
      for(int i = 0; i < n; i++)
        dp[i][1 << i] = S[i].length();
      for(int s = 0; s < 1 << n; s++)
        for(int j = 0; j < n; j++)                   //����ö����һ���ַ���
          if(dp[j][s] != INF && (s >> j & 1))
            for(int i = 0; i < n; i++)
              if(!(s>>i & 1))
                dp[i][s|1<<i]=min(dp[i][s|1<<i], dp[j][s]+LEN[i][j]);
      int id = 0;
      for(int i = 1; i < n; i++)
        if(dp[i][(1 << n) - 1] < dp[id][(1 << n) - 1])
          id = i;
      ans = S[id];
      DFS(id, (1 << n) - 1);//�����Ž�
    }
    cout<<"Scenario #"<<++Case<<":"<<endl<<ans<<endl<<endl;
  }
  return 0;
}

