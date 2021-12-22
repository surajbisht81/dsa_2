Maintain a boolean table[n][n] that is filled in bottom up manner.
The value of table[i][j] is true, if the substring is palindrome, otherwise false.
To calculate table[i][j], check the value of table[i+1][j-1], if the value is true and str[i] is same as str[j], then we make table[i][j] true.
Otherwise, the value of table[i][j] is made false.*/


#include <bits/stdc++.h>
using namespace std;

void printsubstr(string str,int start,int end)
{
    for(int i=start;i<=end;i++)
        cout<<str[i];
}
int longestpalindromicstring(string str)
{
    int n=str.size();
    bool table[n][n];

    memset(table,0,sizeof(table));
    int maxlength=0,start=0;
    //for only 1 character;
    for(int i=0;i<n;i++)
    {   table[i][i]=1;
        maxlength=1; }

   //for 2 characters;
   for(int i=0;i<n-1;i++)
   {
       if(str[i]==str[i+1])
        {
          table[i][i+1]=1;
          maxlength=2;
          start=i;
        }
   }

   //for more than 2 character ;
   for(int k=3;k<n;k++)
   {
       for(int i=0;i<n-k+1;i++)
       {
          int j=i+k-1;
           if(str[i]==str[j] && table[i+1][j-1]==1)
            { table[i][j]=1;
               if(k>maxlength)
               {
                   maxlength=k;
                   start=i;
               }
            }
       }
   }
   printsubstr(str,start,start+maxlength-1);
   return maxlength;
}
int main()
{
    string str="forgeeksskeegfor";
    cout<<"\nlength of palindromic substring is:"<<longestpalindromicstring(str);
    return 0;
}
