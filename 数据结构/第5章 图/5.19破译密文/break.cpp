//��������
//�����ƺ��ö�����Ǵ�ģ���Ϊ���ܽ��Ƚ����ڵ��ַ���
#include <bits/stdc++.h>
using namespace std;

int n,Map[27][27],ind[27],use[27],cnt,Check[27][27];
string s[30010],str,ans;

int Out(string val)
{
  cout<<val<<endl;
  exit(0);
}

int main()
{
  //freopen("break.in","r",stdin);
  //freopen("break.out","w",stdout);
  scanf("%d",&n);
  for (int i = 1; i <= n; i++)
    cin>>s[i];
  for (int i = 1; i < n; i++)
    for(int j = i+1; j <= n; j++)
      for(int k=0; k<min(s[i].size(),s[j].size()); k++)
        if (s[i][k]!=s[j][k])
        {
          if(Check[s[j][k]-'a'][s[i][k]-'a']==1) //ì��
            Out("0");
          Map[s[i][k]-'a'][s[j][k]-'a']=1;       //��ͼ
          if(Check[s[i][k]-'a'][s[j][k]-'a']==0) //��û�б��
          {
            Check[s[i][k]-'a'][s[j][k]-'a']=1;
            ind[s[j][k]-'a']++;
          }
          use[s[i][k]-'a']=1;
          use[s[j][k]-'a']=1;
          break;
        }
  for (int i = 0; i < 26; i++)
    if (use[i])
      cnt++;                          //ͳ��ʹ�õ���ĸ����
  map<char,char> MAP;                 //�ֵ�ӳ��
  for (int i = 0,j; i < cnt; i++)
  {
    for (j=0; ind[j] || !use[j]; j++) //Ѱ�����Ϊ0�ұ�ǹ�����ĸ
      if (j>=26)                      //�Ҳ������Ϊ0�ұ��ù�����ĸ
        Out("0");
    MAP[j+'a']='a'+i;                 //ӳ��
    ind[j]=-1;
    for (int k = 0; k < 26; k++)
      if (Map[j][k])
        ind[k]--;
  }
  cin>>str;
  for (int i = 0; i < str.size(); i++)
  {
    if (!MAP[str[i]])                  //�Ҳ�����Ӧ����ĸ
      Out("0");
    ans+=MAP[str[i]];
  }
  Out(string(ans));
}
