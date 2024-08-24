//���������� - IDA*
#include <bits/stdc++.h>
using namespace std;

const int goal[9]= {1,2,3,8,0,4,7,6,5};        //Ŀ��״̬
const int seat[9]= {4,0,1,2,5,8,7,6,3};        //ÿ�����ֵ�Ŀ��λ��
int step[100];                                 //����ÿһ���ķ���
int limit=-1;                                  //�������

inline int Dis(int loc1,int loc2)
{
  return abs(loc1/3-loc2/3) + abs(loc1%3-loc2%3);
}

inline int Manhattan(int state[9])
{
  int ans=0;
  for(int i=0; i<9; i++)
    if(state[i])
      ans+=Dis(i,seat[state[i]]);
  return ans;
}

inline bool Check(int state[9])                //�ж��Ƿ�ɹ�
{
  for(int i=0; i<9; i++)
    if(state[i]!=goal[i])
      return 0;
  return 1;
}

inline bool Move(int zero, int dir, int &nxt)  //�жϿո��ܷ���dir�����ƶ�
{
  switch(dir)
  {
    case 0:
      nxt=zero-3;                         //nxtΪ0�ƶ����λ��
      return zero>2;                      //0��λ�ô���2�ſ�������
    case 1:
      nxt=zero+1;
      return zero%3!=2;                   //0��λ�ò��ڵ����вſ�����
    case 2:
      nxt=zero+3;
      return zero<6;                      //0��λ�ò��ڵ����вſ�����
    case 3:
      nxt=zero-1;
      return zero%3;                      //0��λ�ò��ڵ�һ�вſ�����
  }
}

bool DFS(int state[], int zero, int dep=0)     //depΪ�������
{
  if(dep==limit)
    return Check(state);
  if(dep+Manhattan(state)>limit)
    return 0;
  int nxt;                                     //�ո��ƶ����λ��
  for(int d=0; d<4; d++)            //����4�������ƶ���0:��,1:��,2:��,3:��
    if((!dep || abs(step[dep-1]-d)!=2) && Move(zero,d,nxt))//���������ֵΪ2
    {
      swap(state[zero],state[nxt]);
      step[dep]=d;
      if(DFS(state, nxt, dep+1))
        return 1;
      swap(state[zero],state[nxt]);
    }
  return 0;
}

int main()
{
  freopen("Puzzle8.in","r",stdin);
  freopen("Puzzle8.out","w",stdout);
  int start[9], zero;
  for(int i=0; i<9; i++)
  {
    cin>>start[i];
    if(start[i]==0)
      zero=i;
  }
  int sum=0;
  for(int i=0; i<8; i++)                //���������
    for(int j=i+1; j<9; j++)
      if(start[i] && start[j] && start[i]>start[j])
        sum++;
  if(sum & 1)                           //�������Ϊ�������н�
  {
    limit=Manhattan(start);             //��ʼ���Ʋ���Ϊ��ʼ״̬�������پ���
    while(limit<100 && !DFS(start, zero))
      limit++;
  }
  cout<<limit<<endl;
  return 0;
}

