/*
�������ƣ�USACO1.1.4 Broken Necklace
����˵����ֱ��������������ͬ����������������������һ��ɨ�裬�ҳ�����a+b 
�������ߣ�ZXH (2010-7-27)
����ע��ע��ans>n����ĳ���,�����ӵĴ�����a��b�Ľ��� 
*/
#include <fstream>
using namespace std;
 
int main()
{
  ifstream fin("beads.in");
  ofstream fout("beads.out");
  char s[700],color=0;//colorΪǰ��ɫ����ʼ���κ���ɫ 
  int n,i,a=0,b=0;//aΪ��һ��������,bΪ����������
  int w=0,ans=0;//w��¼��ĿǰΪֹ��������(�ɽ�ǰ������),ansΪMax(a+b)
    
  fin>>n>>s;
  memcpy(s+n,s,n);
  for (i=0;i<n<<1;i++) //n<<1�൱��n*2
    if (s[i]=='w')
      b++,w++;
    else if (s[i]==color)//��Ϊ��ͬ��ɫ 
      b++,w=0;
    else  //������ͬ��ɫ������ 
    {
      if (a+b>ans)
        ans=a+b;
      a=b-w;//��ɫ�任ʱ��������¼����
      b=w+1;//���ʣ�Ϊ�β���a=b,b=w 
      w=0;
      color=s[i];
    }
	  
  if (a+b>ans) 
    ans=a+b;
  fout<<(ans>n?n:ans)<<endl;//��ans>n��ʾ�������ӽԿ�ȡ��
  return 0;
}
