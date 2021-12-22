/*The following graph G is called a Petersen graph and its vertices have been numbered from 0 to 9. Some letters have also been assigned to vertices of G,
 as can be seen from the following picture:
Let’s consider a walk W in graph G, which consists of L vertices W1, W2, …, WL. A string S of L letters 'A' – 'E' is realized by walk W if the sequence of letters 
written along W is equal to S. Vertices can be visited multiple times while walking along W.

For example, S = 'ABBECCD' is realized by W = (0, 1, 6, 9, 7, 2, 3). Determine whether there is a walk W which realizes a given string S in graph G, and if so then
 find the lexicographically least such walk. The only line of input contains one string S. If there is no walk W which realizes S, then output -1 otherwise, 
you should output the least lexicographical walk W which realizes S.*/

#include <iostream>

using namespace std;
bool adj[10][10];
char s[10000];
char result[10000];
bool findthepath(char *s,int v)
{
    result[0]=v+'0';
    for(int i=1;s[i];i++)
    {
        if(adj[v][s[i]-'A'] || adj[s[i]-'A'][v])
            v= s[i]-'A';
        else if(adj[v][s[i]-'A'+5] || adj[s[i]-'A'+5][v])
            v=s[i]-'A'+5;
        else
            return false;
        result[i]=v+'0';
    }
    return true;
}
int main()
{
    adj[0][1]=true;
    adj[0][4]=true;
    adj[0][5]=true;
    adj[4][3]=true;
    adj[3][2]=true;
    adj[2][1]=true;
    adj[5][8]=true;
    adj[5][7]=true;
    adj[9][6]=true;
    adj[9][7]=true;
    adj[6][8]=true;
    adj[3][8]=true;
    adj[2][7]=true;
    adj[1][6]=true;
    adj[4][9]=true;
    char s[]="AADBEA";
    if(findthepath(s,s[0]-'A') || findthepath(s,s[0]-'A'+5))
        cout<<"\n"<<result;
    else
        cout<<"-1";
    return 0;
}
