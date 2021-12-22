/*Last Updated: 26-02-2019
Given preorder of a binary tree, calculate its depth(or height) [starting from depth 0]. The preorder is given as a string with two possible characters.

‘l’ denotes the leaf
‘n’ denotes internal node
The given tree can be seen as a full binary tree where every node has 0 or two children. The two children of a node can ‘n’ or ‘l’ or mix of both.*/

#include <bits/stdc++.h>
using namespace std;

int depthFrom_preorder(string str,int *index,int n)
{
    if(*index>=n or str[*index]=='l')
        return 0;
    (*index)++;
    int left=depthFrom_preorder(str,index,n);

    (*index)++;
    int right=depthFrom_preorder(str,index,n);

    return max(left,right)+1;
}
int main()
{
   char str[]="nlnnlll";
   int n=strlen(str);
   int index=0;
   cout<<"\ndepth from preorder is : "<<depthFrom_preorder(str,&index,n);
   return 0;
}
