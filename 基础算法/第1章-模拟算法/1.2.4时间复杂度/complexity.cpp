//ʱ�临�Ӷ�
#include <bits/stdc++.h>
using namespace std;

int t,L,ans;
struct Code
{
  char F,i;
  int x,y;
} code[200];

int Judge()
{
  stack <int> st;
  int used[256]= {0};
  int time=0,Maxtime=0,stop=0;   //stop���޷�����ѭ���ı�־
  for(int i=0; i<L; i++)
    if(code[i].F=='F')
    {
      if(used[code[i].i])        //����ظ��������������-1
        return -1;
      used[code[i].i]=1;         //������ʹ�ã����
      st.push(i);                //�������������ջ
      if(code[i].y-code[i].x<0)  //�粻��ѭ������ô����Ƕ�׵�ѭ������Ч
        stop++;
      if(code[i].y-code[i].x>1e6 && !stop)
        time++;                  //����n��ѭ��������ʱ�临�Ӷ�
      Maxtime=max(Maxtime,time); //�������ʱ�临�Ӷ�
    }
    else
    {
      if(st.empty())
        return -1;
      used[code[st.top()].i]=0;  //���������٣�ȡ�����
      if(code[st.top()].y-code[st.top()].x>1e6 && !stop)
        time--;
      if(code[st.top()].y-code[st.top()].x<0)
        stop--;
      st.pop();
    }
  return st.size()==0?Maxtime:-1;
}

int main()
{
  freopen("complexity.in","r",stdin);
  freopen("complexity.out","w",stdout);
  cin>>t;
  while(t--)
  {
    scanf("%d",&L);             //��ȡ��������
    string S,X,Y;
    getline(cin,S);             //��ȡʱ�临�Ӷȣ�ע��S��ͷ��һ���ո�
    int Time=S[3]=='1'?0:(S.size()==7  ? S[5]-'0' : (S[5]-'0')*10+S[6]-'0');

    for(int i=0; i<L; i++)
    {
      cin>>code[i].F;
      if(code[i].F=='F')
      {
        cin>>code[i].i>>X>>Y;
        code[i].x=(X=="n"?1e8:atoi(X.c_str()));//stringתchar��c_str()
        code[i].y=(Y=="n"?1e8:atoi(Y.c_str()));//atoi��*charתΪ����
      }
    }
    int ans=Judge();
    ans==-1?printf("ERR\n"):printf("%s\n",ans==Time?"Yes":"No");
  }
  return 0;
}
