//�Ӽ�����
#include <bits/stdc++.h>
using namespace std;

char s[500010];
char c1[]= {" that "};                          //�����Ƿ�������������
char c2[]= {" this "};
char c3[]= {" have "};

int main()
{
  //freopen("MSG.in","r",stdin);
  //freopen("MSG.out","w",stdout);
  int Len;
  for(Len=0; ~scanf("%c",&s[Len]); Len++);  //�������ĵ��ļ�ĩβ
  for(int t=1; t<=26; t++)
  {
    for(int i=0; i<Len; i++)
    {
      if(s[i]>='a' && s[i]<='z')                //Сд��ĸ
      {
        s[i]++;
        if(s[i]>'z' ||s[i]<'a')
          s[i]-=26;
      }
      if(s[i]>='A' && s[i]<='Z')                //��д��ĸ
      {
        s[i]++;
        if(s[i]>'Z')
          s[i]-=26;
      }
    }
    if(strstr(s,c1) || strstr(s,c2) || strstr(s,c3))
    {
      cout<<s;
      return 0;
    }
  }
}

