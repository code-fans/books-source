//������Ϸ
#include <bits/stdc++.h>
using namespace std;

int s[17]= {0,-50,-2,-3,-4,-5,-6,-7,-8,-9,-10,-20,-30,-40,-100,100};//��ֵ

void Out(int t)
{
  if(t>0)
    cout<<'+';
  cout<<t<<' ';
}

int main()
{
  freopen("poker.in","r",stdin);
  freopen("poker.out","w",stdout);
  while(1)
  {
    int MAP[5][17]= {0};                   //�����Ƶ�״̬��Ϊ0
    int Num[5]= {0};                       //����ÿ���õ��Ƶ�����
    for(int i=1; i<=4; i++)
    {
      cin>>Num[i];
      for(int j=1,p; j<=Num[i]; j++)
      {
        char k;
        cin>>k>>p;                         //�����Ƶ���������
        if(k=='H') MAP[i][p] =1;           //����Ǻ����ƣ����
        if(k=='S') MAP[i][14]=1;           //����Ǻ��ң��϶������ƣ����
        if(k=='D') MAP[i][15]=1;           //����Ƿ��飬�϶������ƣ����
        if(k=='C') MAP[i][16]=1;           //�����÷�����϶��Ǽӱ��ƣ����
      }
    }
    if(Num[1]+Num[2]+Num[3]+Num[4]==0)     //�˳����ж�
      break;
    for(int i=1; i<=4; i++)                //��ʼ�Ʒ�
    {
      int Score=0,AllH=1;                  //AllH�ж��Ƿ�ȫ�Ǻ���
      for(int j=1; j<=13 && AllH; j++)
        AllH=MAP[i][j];
      if(AllH)                             //���ȫ�Ǻ���
      {
        Score=200;
        if(MAP[i][14] && MAP[i][15])       //���ͬʱ�ú���Q�ͷ���J
          Score=500;                       //��500
        else
          Score+=MAP[i][14]*s[14]+MAP[i][15]*s[15];//���򵥶����
        Out(MAP[i][16]?(Score<<1):Score);  //���ܷ���
      }
      else
      {
        bool OnlyC10=true;
        for(int j=1; j<=15 && OnlyC10; j++)//�ж��ǲ��ǳ���C10,�����ƶ�û��
          OnlyC10=!MAP[i][j];
        if(OnlyC10)
          Out(MAP[i][16]?50:0);            //ֻ��C10�����50
        else
        {
          for(int j=1; j<=15; j++)
            Score+=MAP[i][j]*s[j];
          Out(MAP[i][16]?(Score<<1):Score);//���ܷ���
        }
      }
    }
    cout<<endl;
  }
  return 0;
}

