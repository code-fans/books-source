//��ת���� - BFS
#include <bits/stdc++.h>
using namespace std;

queue <int> que;                           //��������������õ��Ķ���
bool flag[65536];                          //flag[i]=1��i״̬�ѳ��ֹ�
int step[65536];                           //step[i]����i״̬�Ĳ���

int Flip(int state,int pos)                //��תpos������Χλ��
{
  state^=(1<<pos);
  state^=((pos-4)>=0)<<(pos-4);            //��ת�Ϸ�
  state^=((pos+4)<=15)<<(pos+4);           //��ת�·�
  state^=(pos%4!=0)<<(pos-1);              //��ת��
  state^=(pos%4!=3)<<(pos+1);              //��ת�ҷ�
  return state;
}

int BFS()                                  //����
{
  while(que.empty()!=1)                    //�����в�Ϊ��
  {
    int state=que.front();                 //ȡ������״̬
    que.pop();                             //��������Ԫ��
    for(int i=0; i<16; i++)
    {
      int temp=Flip(state,i);              //ö�ٵ�ǰ״̬�£���ת16�����Ӻ��״̬
      if(temp==0 || temp==65535)           //��ȫ0��ȫ1
      {
        flag[temp]=1;
        step[temp]=step[state]+1;
        return true;
      }
      else if(!flag[temp])                 //����״̬û�г��ֹ�
      {
        que.push(temp);
        flag[temp]=1;                      //�����״̬
        step[temp]=step[state]+1;
      }
    }
  }
  return false;
}

int main()
{
  //freopen("FlipGame.in","r",stdin);
  //freopen("FlipGame.out","w",stdout);
  int state=0;
  char s[5];
  for(int i=0; i<4; i++)
  {
    scanf("%s",s);
    for(int j=0; j<4; j++)
      state|=((s[j]=='b')<<(i*4+j));       //��λΪ1ʱ��state+=1^λ��
  }
  if(state==0 || state==65535)             //��ȫ�׻�ȫ��
    printf("0\n");
  else
  {
    que.push(state);                       //��ʼ״̬�����
    flag[state]=1;                         //��ʾ��״̬�ѳ��ֹ�
    if(BFS())                              //�����������
      printf("%d\n",flag[0]?step[0]:step[65535]);
    else
      printf("Impossible\n");
  }
  return 0;
}

