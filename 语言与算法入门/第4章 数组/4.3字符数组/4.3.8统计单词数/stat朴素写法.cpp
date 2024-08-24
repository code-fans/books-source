//统计单词数
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
  for(int i=0; i<len1; i++) //全转大写字母
    if(str1[i]>='a' && str1[i]<='z')
      str1[i]-=32; //不要用strupr或strlwr大小写转换函数
  for(int i=0; i<len2; i++) //全转大写字母
    if(str2[i]>='a' && str2[i]<='z')
      str2[i]-=32;
  strcat(str2," ");//str2后面加个空格减少配对难度（因为单词后以空格间隔）
  strcat(str1," ");//str1后面加个空格
  int first=-1;//first:第一个匹配位置
  int count=0, p=0,Len=0;//Len统计前面已经删除了多少个字符
  while(strstr(str1,str2))//如果可以匹配
  {
    cout<<strstr(str1,str2)<<endl;
    p=strstr(str1,str2)-str1;//包含str2的地址-数组首地址即为偏移量
    if((p==0 || str1[p-1]==' ') && first==-1)//第一次匹配的处理 p=0表示第一个单词就匹配
      first=p+Len,count++;//first要还原回初始的正确位置
    else if(str1[p-1]==' ')//因为单词前有空格间隔
      count++;
    strcpy(str1,str1+p+1);//将str1后面一段拷贝,即前面一段删除(耗时)
    Len+=p+1;//每次str1前面删除的字符串长度都累计到Len
  }
  if(count==0)
    cout<<"-1\n";
  else
    cout<<count<<' '<<first<<endl;
  return 0;
}


