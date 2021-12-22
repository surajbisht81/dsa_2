#include <bits/stdc++.h>
using namespace std;
#define ALPHA 26

string getdiffstring(string str)
{
    string resdiff;
    for(int i=1;i<str.length();i++)
    {
        int diff= str[i]-str[i-1];
        if(diff<0)
            diff=ALPHA+diff;

        resdiff+= diff + '|';
    }
    return resdiff;
}
void groupShiftedString(string str[], int n)
{
    unordered_map<string, vector<int>>mp;

    for(int i=0;i<n;i++)
    {
        string diff = getdiffstring(str[i]);
        mp[diff].push_back(i);
    }

    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        vector<int> v = it->second;
        for(int i=0;i<v.size();i++)
        {
            cout<<str[v[i]]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    string str[] = {"acd", "dfg", "wyz", "yab", "mop",
                    "bdfh", "a", "x", "moqs"
                   };
    int n=sizeof(str)/sizeof(str[0]);
    groupShiftedString(str, n);
    return 0;
}
