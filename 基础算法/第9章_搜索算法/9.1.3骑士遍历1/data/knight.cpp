//��ʿ����1 - ����������
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("knight.in","r",stdin);
  freopen("knight.out","w",stdout);
  int k=0,num=0,x=1,y=1,X,Y;               //numΪ������A���x=1,y=1��ʼ
  int step[1000];                        //�洢ÿ��һ���ķ���
  int dx[5]= {0, 1, 2,2,1};            //����x�������������
  int dy[5]= {0,-2,-1,1,2};            //����y�������������
  cin>>X>>Y;
  while(1)
  {
    if(x==X && y==Y)                   //�������µ㣬���˳�
      break;
    k++;                               //�ı䷽��
    if(k>4)                            //���4�����������ˣ�����һ��
    {
      k=step[num];                     //��÷���
      num--;                           //������1
      if(num==0)
      {
        cout<<-1<<endl;
        return 0;
      }
      x-=dx[k];                        //��ԭx
      y-=dy[k];                        //��ԭy
    }
    else                               //�������Ű�k�ķ���ǰ��
    {
      x+=dx[k];
      y+=dy[k];
      if(x>X||x<1||y>Y||y<1||(Y-y)>(2*(X-x)))         //����Եķ��򳬳����̷�Χ�����˻�
      {
        x-=dx[k];
        y-=dy[k];
      }
      else                             //����÷��������
      {
        num++;                         //������1
        step[num]=k;                   //���ò������������
        k=0;                           //����һ���ķ����ʼΪ0
      }
    }
  }
  for(k=1; k<=num; k++)
    printf("%d ",step[k]);
  return 0;
}

