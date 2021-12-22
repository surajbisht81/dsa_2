#include <bits/stdc++.h>
using namespace std;
#define M 5
#define N 5
unordered_map<string,float>mp;
float finding_probability(int i,int j,int n)
{
    if(i<0 or i>=M or j<0 or j>=N)
        return 0;

    if(n==0)
        return 1;
    float res=0.00;
    string key=to_string(i) + to_string(j) +to_string(n);
    if(mp.find(key)==mp.end())
    {
      res+=finding_probability(i-1,j,n-1);
      res+=finding_probability(i+1,j,n-1);
      res+=finding_probability(i,j-1,n-1);
      res+=finding_probability(i,j+1,n-1);
     mp[key]=res/4;
    }
    return mp[key];
}
int main()
{
    int i=1,j=1;
    int n=2;
    cout<<"\nprobability is :"<<finding_probability(i,j,n);
    return 0;
}
