//����ȡ��
#include <bits/stdc++.h>
using namespace std;

int a[11][11];                        //��ţ�x,y��������
int f1[101][101],f2[101][101];        //����������i-1,i���׶ε�״̬
int x,y,z,n;

void Dp()
{
  for(int k=1; k<=2*n-1; k++)               //׼���ߵ�k��
  {
    for(int x1=1; x1<=k; x1++)       //ö������·���ڵ�i-1��ʱ��״̬x1��x1
      for(int x2=x1; x2<=k; x2++)    //x2��x1��ʼ������(x,y),(y,x)���ظ�����
      {
        int Y1=k+1-x1;                       //�������y1������C++���Ƴ�ͻ
        int Y2=k+1-x2;                          //Y2=k+1-x2
        if(x1<=n && x1>=1 && x2<=n && x2>=1 && Y1>=1 && Y1<=n && Y2>=1 && Y2<=n)
          for(int DirA=0; DirA<=1; DirA++)        //A��x������
            for(int DirB=0; DirB<=1; DirB++)      //B��y������
            {
              int X=x1,Y=Y1,x=x2,y=Y2;
              if(DirA==0)                     //A������
                Y++;
              else                          //A������
                X++;
              if(DirB==0)                     //B������
                y++;
              else                          //B������
                x++;
              if(X<=n&&X>=1&&Y<=n&&Y>=1&&x<=n&&x>=1&&y>=1&&y<=n)
                f2[X][x]=max(f2[X][x],f1[x1][x2]+a[x][y]+(X==x?0:a[X][Y]));
            }
      }
    memcpy(f1,f2,sizeof(f2));               //���ƹ�������
  }
}

int main()
{
  freopen("GetNum.in","r",stdin);
  freopen("GetNum.out","w",stdout);
  cin>>n;
  n++;                               //����ά���һ��һ�У���֤���������
  while(cin>>x>>y>>z,x && y && z)
    a[x+1][y+1]=z;                   //a�����ŷ���������Ӧ�������궼��1
  Dp();
  cout<<f1[n][n]<<endl;
  return 0;
}

