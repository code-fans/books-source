//��̽����
#include <bits/stdc++.h>
using namespace std;

int lie[25],whosay[200]; //lie���ڱ���Ƿ�˵��,whosay[]����˭˵����仰
int ERR,guilt;
string name[105],say[205];
string week[8]= {" ","Today is Sunday.",
                 "Today is Monday.",
                 "Today is Tuesday.",
                 "Today is Wednesday.",
                 "Today is Thursday.",
                 "Today is Friday.",
                 "Today is Saturday.",
                };

void Judge(int who,int guilt)
{
  if(lie[who] && lie[who]!=guilt)     //˵һ���������ﷸ�ֲ����ﷸ������
    ERR=1;
  else
    lie[who]=guilt;
}

int main()
{
  //freopen("LOGIC.in","r",stdin);
  //freopen("LOGIC.out","w",stdout);
  int m,n,p;
  cin>>m>>n>>p;
  for(int i=1; i<=m; i++)
    cin>>name[i];
  for(int i=1; i<=p; i++)
  {
    string man;
    cin>>man;
    man=man.substr(0,man.length()-1); //ȥð��
    for(int j=1; j<=m; j++)
      if(name[j]==man)
        whosay[i]=j;                  //�ж���仰��˭˵��
    getline(cin,say[i]);
    say[i]=say[i].substr(1,say[i].length()-1);//ĳЩ��վ�ϵ����ݻ����ر���
  }
  for(int today=1; today<=7; today++) //ö�ٽ��������ڼ�
    for(int G=1; G<=m; G++)           //ö���ﷸ
    {
      ERR=0;                          //������
      memset(lie,0,sizeof(lie));
      for(int i=1; i<=p; i++)         //�����ж�ÿ�仰
      {
        int who=whosay[i];
        if(say[i]=="I am guilty.")    //˵�Լ����ﷸ
          Judge(who,G==who?1:-1);
        if(say[i]=="I am not guilty.")//˵�Լ������ﷸ
          Judge(who,G!=who?1:-1);
        for(int j=1; j<=m; j++)       //˵���˾����滰��������Ǽٻ�
        {
          if(say[i]==name[j]+" is guilty.")
            Judge(who,j==G?1:-1);
          if(say[i]==name[j]+" is not guilty.")
            Judge(who,j!=G?1:-1);
        }
        for(int j=1; j<=7; j++)
          if(say[i]==week[j])         //�жϽ��������ڼ������Ǽ�
            Judge(who,j==today?1:-1);
      }
      int liecount=0,uncertain=0;     //liecount:˵�ٻ���������uncertain:��ȷ��������
      for(int i=1; i<=m; i++)
      {
        if(lie[i]==-1) liecount++;
        if(lie[i]==0)  uncertain++;
      }
      if(!ERR && liecount+uncertain>=n && liecount<=n)
        if(guilt && guilt!=G)         //����������������ﷸ
        {
          cout<<"Cannot Determine\n";
          return 0;
        }
        else guilt=G;
    }
  cout<<(guilt?name[guilt]:"Impossible")<<endl;
}
