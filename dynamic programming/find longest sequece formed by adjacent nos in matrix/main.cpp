#include <bits/stdc++.h>
using namespace std;

#define M 5

string find_path(int mat[M][M],int i,int j)
{
    if(i<0 && i>=M && j<0 && j>=M)
        return 0;
    unordered_map<string,string>mp;
    string key=to_string(i)+to_string(j);
    if(mp.find(key)==mp.end())
    {

     string path;
     //top
     if(i>0 && mat[i-1][j]-mat[i][j]==1)
       path=find_path(mat,i-1,j);
     //down
     if(i+1<M && mat[i+1][j]-mat[i][j]==1)
         path=find_path(mat,i+1,j);
     //right;
     if(j+1<M && mat[i][j+1]-mat[i][j]==1)
         path=find_path(mat,i,j+1);
      //left
     if(j>0 && mat[i][j-1]-mat[i][j]==1)
         path=find_path(mat,i,j-1);

     mp[key]= to_string(mat[i][j]) + "-"+ path;
    }
    return mp[key];
}
int main()
{
   int mat[M][M]={{10,13,14,21,23},
                  {11,9,22,2,3},
                  {12,8,1,5,4},
                  {15,24,7,6,25},
                  {16,17,18,19,20}};

  string res;
  string curr_str;
  int re_ze=INT_MIN;

  vector<string>v;
  for(int i=0;i<M;i++)
  {
      for(int j=0;j<M;j++)
      {
          curr_str=find_path(mat,i,j);
          int Size=count(curr_str.begin(),curr_str.end(),'-');
          if(re_ze<=Size)
          {
              re_ze=Size;
              res=curr_str;
              v.push_back(res);
          }
      }
  }
  for(int i=0;i<v.size();i++)
  cout<<"\nlongest sequence is :"<<v[i+1];
  return 0;
}
