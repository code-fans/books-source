//һ�ʻ�����
//�˳�����������ͼ�޹�
#include <bits/stdc++.h>
using namespace std;

int graph[7][7]= {0,0,0,0,0,0,0,
                  0,0,1,0,0,1,1,
                  0,1,0,1,1,0,1,
                  0,0,1,0,1,0,0,
                  0,0,1,1,0,1,1,
                  0,1,0,0,1,0,1,
                  0,1,1,0,1,1,0
                 };

int a[7],total,edge;            //a[]����ÿ������Ķ�

int Draw(int v)
{
  int k=0;
  if(total==edge) return 1;
  for(int i=1; i<7; i++)
  {
    if(graph[v][i]==1)
    {
      k=1;
      graph[v][i]=0;
      graph[i][v]=0;
      edge+=2;
      if(Draw(i))               //�ݹ飬������Լ�������ȥ
      {
        printf("%3d",i);
        return 1;
      }
      else
      {
        graph[v][i]=1;          //�ָ�
        graph[i][v]=1;
        edge-=2;
        k=0;
      }
    }
  }
  if(k==0) return 0;
}

int main()
{
  int v,k=0;
  for(int i=1; i<7; i++)
  {
    for(int j=1; j<7; j++)
      if(graph[i][j]==1)
        a[i]++;                 //ͳ��ÿ������Ķ�
    total+=a[i];
    if(a[i]%2==1)               //ͳ��������
    {
      k++;
      v=i;
    }
  }
  if(k>2)
    printf("No solution\n");
  else
  {
    Draw(v);                    //����һ�����v����
    printf("%3d",v);
  }
  return 0;
}

