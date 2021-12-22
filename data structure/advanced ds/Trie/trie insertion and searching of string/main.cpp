#include <bits/stdc++.h>
using namespace std;

/*
// using memory utilization method
struct trie2
{
    bool isend;
    unordered_map<char,trie2*>mp;
    trie2()
    {
        isend=false;
    }
};
struct trie2 *root2;
void insert2(string str)
{
    struct trie2 *cur=root2;
    for(char ch:str)
    {
        if(!cur->mp.count(ch))
            cur->mp[ch]=new trie2;
        cur=cur->mp[ch];
    }
    cur->isend=true;
}
bool search2(string str)
{
    struct trie2 *cur=root2;
    for(char ch:str)
    {
        if(!cur->mp.count(ch))
            return false;
        cur=cur->mp[ch];
    }
    return cur->isend;
}
int main()
{
    root2=new trie2;
    int n;
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        insert2(str);
    }
    cin>>n;
    while(n--)
    {
        string strr;
        cin>>strr;
        if(search2(strr))
            cout<<strr<<"  is present.";
        else
            cout<<strr<<" is not present.";
    }
    return 0;
}
*/

// using 2nd method;
struct trie
{
    struct trie* children[26];
    bool isend;
    trie()
    {
        memset(children,0,sizeof(children));
        isend=false;
    }
};
struct trie *root;
void insert1(string str)
{
    struct trie* cur=root;
    for(char ch:str)
    {
        if(cur->children[ch-'a']==NULL)
            cur->children[ch-'a']=new trie;
        cur=cur->children[ch-'a'];
    }
    cur->isend=true;
}
bool search1(string str)
{
    struct trie *cur=root;
    for(char ch:str)
    {
        if(!cur->children[ch-'a'])
            return false;
        cur=cur->children[ch-'a'];
    }
    return cur->isend;
}
int main()
{
    root=new trie;
    int n;
    cin>>n;
    while(n--)
    {
        string str;
        cin>>str;
        insert1(str);
    }

    cin>>n;
    while(n--)
    {
        string strr;
        cin>>strr;
        if(search1(strr))
            cout<<strr<<" is present.";
        else
            cout<<strr<<"  is not present.";
    }
    return 0;
}
*/
