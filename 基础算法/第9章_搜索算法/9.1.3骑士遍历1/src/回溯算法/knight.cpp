//��ʿ����1
#include <bits/stdc++.h>
using namespace std;

int k=0,m=0,X,Y,x=1,y=1;          //mΪ������A���x=1,y=1��ʼ
int step[1000];                   //�洢ÿ��һ���ķ���

int In(int x,int y)
{
  return (x>0 && x<=X && y>0 && y<=Y);
}

int main()
{
  //freopen("knight.in","r",stdin);
  //freopen("knight.out","w",stdout);
  cin>>X>>Y;
  int dx[5]= {0, 1, 2,2,1};       //����x�������������
  int dy[5]= {0,-2,-1,1,2};       //����y�������������
  while(x!=X || y!=Y)
  {
    k++;                          //�ı䷽��
    if(k>4)                       //��4����������󣬺���һ��
    {
      k=step[m];                  //��÷���
      m--;                        //������1
      if(m<0)
      {
        puts("-1");
        exit(0);
      }
      x-=dx[k];                   //��ԭx
      y-=dy[k];                   //��ԭy
    }
    else                          //�������Ű�k�ķ���ǰ��
    {
      x+=dx[k];
      y+=dy[k];
      if(In(x,y))                 //����Եķ��������̷�Χ��
      {
        m++;                      //������1
        step[m]=k;                //���ò������������
        k=0;                      //����һ���ķ����ʼΪ0
      }
      else                        //����÷��������
      {
        x-=dx[k];
        y-=dy[k];
      }
    }
  }
  for(k=1; k<m; k++)
    printf("%d ",step[k]);
  printf("%d\n",step[m]);
  return 0;
}

