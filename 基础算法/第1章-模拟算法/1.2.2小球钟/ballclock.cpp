//С����
#include <bits/stdc++.h>
using namespace std;
const int LIMIT[4] = {5,3,4,24}; //����ÿ�й�����ɵ�С����

int Line[4][25];                 //���й������1���ӣ�5���ӣ�15���ӣ�Сʱ���
int solved[300];                 //�������õĽ��
deque<int> Q;                    //����

int GCD(int m, int n)            //�����Լ��
{
  return n==0?m:GCD(n,m%n);
}

unsigned long long GetDay(int n)
{
  int j,k;
  unsigned long long ans = 1;
  for (int i = 0; i < n; ++i)    //ö��ÿ��С��
  {
    for (j = Q[i], k = 1; j != i; j = Q[j], ++k);//����ÿ��С�������k
    ans=ans*k/GCD(ans, k);//���С����֮ǰ����С������ڵ���С������
  }
  return ans;
}

int Solve(int n)
{
  Q.clear();                            //��ն���
  for (int i = 0; i < n; ++i)           //��ʼ������
    Q.push_back(i);
  while(1)
  {
    Line[0][++Line[0][0]]=Q.front();    //Line[i][0]��¼��i�й�����е�����
    Q.pop_front();
    for (int i = 0; i < 3; ++i)         //ö��1���ӣ�5���ӣ�15���ӵĹ��
      if (Line[i][0] == LIMIT[i])       //�����дﵽ�����ɼ���
      {
        Line[i+1][++Line[i+1][0]]=Line[i][Line[i][0]--];//���һ�����������
        while (Line[i][0] != 0)
          Q.push_back(Line[i][Line[i][0]--]);//ʣ������������������
      }
    if (Line[3][0] == LIMIT[3])         //��24Сʱ����
    {
      int o = Line[3][0]--;             //�ȼ�¼����ı��
      while (Line[3][0] != 0)           //���������������
        Q.push_back(Line[3][Line[3][0]--]);
      Q.push_back(Line[3][o]);          //��������������
      break;
    }
  }
  return GetDay(n);
}

int main()
{
  //freopen("ballclock4.in","r",stdin);
  //freopen("ballclock4.ans","w",stdout);
  int n;
  while (cin >> n, n != 0)
    if (solved[n] != 0)                 //���֮ǰ�Ѽ������ֱ��������
      cout<<solved[n]<<"\n";
    else
      cout<<(solved[n]=Solve(n))<<'\n'; //��¼�����������
  return 0;
}

