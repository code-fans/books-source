//�������֣��ӣԣ̰�
#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("dictionary.in","r",stdin);
  freopen("dictionary.out","w",stdout);
  char english[11],foreign[11];
  map<string,string>translate;//��¼Foreign��English��ӳ��
  while(true)//�����ֵ�
  {
    char t;  //��ʱ����
    if((t=getchar())=='\n')  //�ж��Ƿ������˿���
      break;
    else     //����english
    {
      english[0]=t;
      int i=1;
      while(true)
      {
        t=getchar();
        if(t==' ')
        {
          english[i]='\0';
          break;
        }
        else
          english[i++]=t;
      }
    }
    cin>>foreign;
    getchar();  //���� ����foreign��� �س���
    translate[foreign]=english;
  }
  char word[11];
  while(cin>>word)//��ʼ����
  {
    if(translate[word]!="")
      cout<<translate[word]<<endl;
    else
      cout<<"eh"<<endl;
  }
  return 0;
}
