//ʱ�临�Ӷ�
#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("complexity.in","r",stdin);
  freopen("complexity.out","w",stdout);
  int t,L;
  cin>>t;
  while(t--)
  {
    scanf("%d",&L);         //��ȡ��������
    string s;
    getline(cin,s);
    int Time=s[3]=='1'?0:(s.size()==7?s[5]-'0':(s[5]-'0')*10+s[6]-'0');//��ȡʱ�临�Ӷ�
    int RealTime=0,NoLoop=0,Error=0;    //RealTime��ʾʵ�ʵ�ʱ�临�Ӷ�
    deque<int>q1,q2;        //˫�˶���,һ�������е�ѭ��������һ����μ�ѭ����ѭ������
    int Visit[101]= {0},InLoop[101]= {0};
    while(L--)
    {
      getline(cin,s);
      if(s[0]=='F')
      {
        int loop=s[2]-'a'+1;             //ȡѭ��������תΪ���ͣ�
        q1.push_front(loop);             //�����һ������
        if(!Visit[loop])                 //���loopδ�����
        {
          Visit[loop]=1;                 //���
          if(s[4]=='n')//���ѭ����n��ʼ������ѭ���Ҷ˵㲻��n
          {
            if(isdigit(s[6]))
              NoLoop=1;                  //���μ�ѭ��
          }
          else
          {
            int t1=atoi(s.substr(4,s.find(' ',5)-4).c_str());//���ѭ������ʼֵ
            if(s[s.find_last_of(' ',100)+1]=='n' && NoLoop==0) //���ѭ������ֵ��n���ҵ�ǰ������ѭ��
            {
              q2.push_front(loop);       //����ѭ������ڶ���������
              InLoop[loop]=1;            //���
              RealTime=max(int(q2.size()),RealTime);//�ڶ����������м���ѭ������,��ô���ӶȾ���O(n�ļ��η�)
            }
            if(s[s.find_last_of(' ',100)+1]!='n') //��ѭ������ֵ��Ϊn
              if(atoi(s.substr(s.find(' ',5)+1).c_str())<t1)
                NoLoop=1;//�����ֵС����ʼֵ�����μ�ѭ��
          }
        }
        else Error=1;
      }
      else if(s[0]=='E')
      {
        if(!q1.empty())                  //����һ�����в�Ϊ��
        {
          int p=q1.front();
          q1.pop_front();                //��������
          if(InLoop[p])                  //�������Ԫ��Ҳ�ڵڶ���������
          {
            q2.pop_front();
            InLoop[p]=0;
          }
          Visit[p]=0;
        }
        else Error=1;
        if(q1.empty())
          NoLoop=0;         //�����һ�����пգ���ѭ�����ִ������
      }
      else
        Error=1;
    }
    if(Error==1 || !q1.empty())
      cout<<"ERR"<<'\n';
    else
      RealTime!=Time?cout<<"No"<<'\n':cout<<"Yes"<<'\n';
  }
  return 0;
}
