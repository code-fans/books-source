//最长最短单词
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("word2.in","r",stdin);
  freopen("word2.out","w",stdout);
  char s[20210],word[205][105];
  int minRow, maxRow,minlen,maxlen, i ,j,p;
  while (gets(s))
  {
    minRow = maxRow = 0;
    minlen = 999999999;
    maxlen = -1;
    j=p = -1;
    i = 0;
    while (s[++p] != '\0')
    {
      if ((s[p] >= 'a'&&s[p] <= 'z') || (s[p] >= 'A'&&s[p] <= 'Z'))
        word[i][++j] = s[p];
      else
      {
        word[i][++j] = '\0';
        if (j>0&&j > maxlen)
        {
          maxlen = j;
          maxRow = i;
        }
        if (j>0&&j < minlen)
        {
          minlen = j;
          minRow = i;
        }
        ++i;
        j = -1;
      }
    }

    word[i][++j] = '\0';
    if (j>0&&j> maxlen)
    {
      maxlen = j;
      maxRow = i;
    }
    if (j>0&&j < minlen)
    {
      minlen = j;
      minRow = i;
    }

    for (int i = 0; i < maxlen; i++)
      printf("%c", word[maxRow][i]);
    printf("\n");
    for (int i = 0; i < minlen; i++)
      printf("%c",word[minRow][i]);
    printf("\n");
  }
  return 0;

}

