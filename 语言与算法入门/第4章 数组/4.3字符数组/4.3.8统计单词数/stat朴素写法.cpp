//ͳ�Ƶ�����
#include <bits/stdc++.h>
using namespace std;
char str1[1000010];
char str2[21];

int main()
{
  //freopen("stat.in","r",stdin);
  //freopen("stat.out","w",stdout);
  cin.getline(str2,20);
  cin.getline(str1,1000000);
  int len1=strlen(str1);
  int len2=strlen(str2);
  for(int i=0; i<len1; i++) //ȫת��д��ĸ
    if(str1[i]>='a' && str1[i]<='z')
      str1[i]-=32; //��Ҫ��strupr��strlwr��Сдת������
  for(int i=0; i<len2; i++) //ȫת��д��ĸ
    if(str2[i]>='a' && str2[i]<='z')
      str2[i]-=32;
  strcat(str2," ");//str2����Ӹ��ո��������Ѷȣ���Ϊ���ʺ��Կո�����
  strcat(str1," ");//str1����Ӹ��ո�
  int first=-1;//first:��һ��ƥ��λ��
  int count=0, p=0,Len=0;//Lenͳ��ǰ���Ѿ�ɾ���˶��ٸ��ַ�
  while(strstr(str1,str2))//�������ƥ��
  {
    cout<<strstr(str1,str2)<<endl;
    p=strstr(str1,str2)-str1;//����str2�ĵ�ַ-�����׵�ַ��Ϊƫ����
    if((p==0 || str1[p-1]==' ') && first==-1)//��һ��ƥ��Ĵ��� p=0��ʾ��һ�����ʾ�ƥ��
      first=p+Len,count++;//firstҪ��ԭ�س�ʼ����ȷλ��
    else if(str1[p-1]==' ')//��Ϊ����ǰ�пո���
      count++;
    strcpy(str1,str1+p+1);//��str1����һ�ο���,��ǰ��һ��ɾ��(��ʱ)
    Len+=p+1;//ÿ��str1ǰ��ɾ�����ַ������ȶ��ۼƵ�Len
  }
  if(count==0)
    cout<<"-1\n";
  else
    cout<<count<<' '<<first<<endl;
  return 0;
}


