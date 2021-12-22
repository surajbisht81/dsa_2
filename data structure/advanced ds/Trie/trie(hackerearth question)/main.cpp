#include<bits/stdc++.h>
using namespace std;

struct trie
{
    struct trie *children[26];
    bool isend;
    trie()
    {
        memset(children,0,sizeof(children));
        isend=false;
    }
};
struct trie *root;

int insert1(string str,int total)
{
    struct trie *cur=root;
    for(char ch:str)
    {
        if(!cur->children[ch-'a'])
        {
          cur->children[ch-'a']=new trie;
          total++;
        }
        cur=cur->children[ch-'a'];
    }
    cur->isend=true;
    return total;
}
int main()
{
    root=new trie;
    int n;
    cin>>n;
    int total=0;
    while(n--)
    {
        string str;
        cin>>str;
        total=insert1(str,total);
    }
    cout<<"\ntotal nodes="<<total+1;
    return 0;
}

