#include <bits/stdc++.h>
using namespace std;
#define r 4
#define c 4
bool findmatch(char grid[r][c],string ch,int x[],int y[],int i,int j,int pos)
{
    int l=ch.length();
    if(pos==l)
        return true;
    if(i<0 or i>=r or j<0 or j>=c or grid[i][j]=='_')
        return false;

   if(grid[i][j]==ch[pos])
   {
       char temp=grid[i][j];
       grid[i][j]='_';
     for(int m=0;m<4;m++)
     {
         int next_i=i+x[m];
         int next_j=j+y[m];

         if(findmatch(grid,ch,x,y,next_i,next_j,pos+1))
            return true;

     }
     grid[i][j]=temp;
   }
    else
        return false;
    return false;
}
int main()
{
    char grid[r][c] = {'a','x','m','y',
                      'b','g','d','f',
                      'x','e','e','t',
                      'r','a','k','s'};

  string ch="xgeam";
  int x[]={0,1,-1,0};
  int y[]={1,0,0,-1};

  bool flag=0;
  for(int i=0;i<r;i++)
  {
      for(int j=0;j<c;j++)
      {
          if(grid[i][j]==ch[0])
            {
                if(findmatch(grid,ch,x,y,i,j,0))
                  flag=1;
            }
      }
  }
  if(flag==1)
    cout<<"\nis present.";
  else
    cout<<"\nnot present.";
  return 0;
}
