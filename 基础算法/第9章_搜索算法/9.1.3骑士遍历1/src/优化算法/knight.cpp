//��ʿ���� -�Ż��㷨
#include<bits/stdc++.h>
using namespace std;
int way[5][2]= {{0,0},{1,-2},{2,-1},{2,1},{1,2}};//��������
int step[1000]= {0,2};                  //��1���ӷ���2��ʼ

int main()
{
  //freopen("knight.in","r",stdin);
  //freopen("knight.out","w",stdout);
  int x=1,y=1,X,Y,k=1;
  cin>>X>>Y;
  while(k>=1)
  {
    step[k]++;
    while(step[k]>4)
    {
      step[k]=0;
      k--;
      if(k==0)
      {
        cout<<-1<<endl;
        return 0;
      }
      x-=way[step[k]][0];//�ָ�����һ��
      y-=way[step[k]][1];
      step[k]++;
    }
    x+=way[step[k]][0];
    y+=way[step[k]][1];
    if(x==X && y==Y)
      break;
    if(x>X||x<1||y>Y||y<1||(Y-y)>(2*(X-x)))//�Ż�
    {
      x-=way[step[k]][0];
      y-=way[step[k]][1];
    }
    else
      k++;
  }
  for(int i=1; i<k; ++i)
    cout<<step[i]<<" ";
  cout<<step[k]<<endl;
  return 0;
}
