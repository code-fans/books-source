//��ת���� - BFS
#include <bits/stdc++.h>
using namespace std;

queue <int> que;                           //��������������õ��Ķ���
int flag[65536];                           //flag[i]=1��i״̬�ѳ��ֹ�
int step[65536];                           //step[i]����i״̬�Ĳ���

int Flip(int state,int pos)                //��תpos������Χλ��
{
  state^=(1<<pos);
  if((pos-4)>=0)   state^=(1<<(pos-4));    //��ת�Ϸ�
  if((pos+4)<=15)  state^=(1<<(pos+4));    //��ת�·�
  if(pos%4!=0)     state^=(1<<(pos-1));    //��ת��
  if(pos%4!=3)     state^=(1<<(pos+1));    //��ת�ҷ�
  return state;
}

int BFS()                                  //����
{
  int OK=0,state,temp;
  while(que.empty()!=1)                    //�����в�Ϊ��
  {
    state=que.front();                     //ȡ������״̬
    que.pop();                             //��������Ԫ��
    for(int i=0; i<16; i++)
    {
      temp=Flip(state,i);                  //ö�ٵ�ǰ״̬�£���ת16�����Ӻ��״̬
      if(temp==0||temp==65535)             //��ȫ0��ȫ1
      {
        OK=1;
        flag[temp]=1;
        step[temp]=step[state]+1;
        break;
      }
      else if(!flag[temp])                 //����״̬û�г��ֹ�
      {
        que.push(temp);
        flag[temp]=1;                      //�����״̬
        step[temp]=step[state]+1;
      }
    }
    if(OK)
      break;
  }
  return OK;
}

int main()
{
  freopen("FlipGame.in","r",stdin);
  freopen("FlipGame.out","w",stdout);
  int state=0;
  char s[5];
  for(int i=0; i<4; i++)
  {
    scanf("%s",s);
    for(int j=0; j<4; j++)
      if(s[j]=='b')                        //��'b'=1,'w'=0,����λΪ0ʱ�������
        state|=(1<<(i*4+j));               //��λΪ1ʱ��state+=1^λ��
  }
  if(state==0||state==65535)               //��ȫ�׻�ȫ��
    printf("0\n");
  else
  {
    que.push(state);                       //��ʼ״̬�����
    flag[state]=1;                         //��ʾ��״̬�ѳ��ֹ�
    if(BFS())                              //�����������
      printf("%d\n",flag[0]==1?step[0]:step[65535]);
    else
      printf("Impossible\n");
  }
  return 0;
}

