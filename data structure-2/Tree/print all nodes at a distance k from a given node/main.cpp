#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *left, *right;
};
Node *newNode(int key)
{
    Node *new_node = new Node;
    new_node->data=key;
    new_node->left=new_node->right=NULL;
    return new_node;
}
    unordered_map<Node*, Node*> mp;
void StoreParent(Node *root)
{
    queue<Node*> qu;
    qu.push(root);

    while(!qu.empty())
    {
        Node *p = qu.front();
        qu.pop();

        if(p==root)
            mp[p]=NULL;

        if(p->left)
        {
            mp[p->left]=p;
            qu.push(p->left);
        }
        if(p->right)
        {
            mp[p->right]=p;
            qu.push(p->right);
        }

    }
}

void PrintNode(Node *root, Node *target, int k)
{
    queue<Node*> qu;
    set<Node*> st;

    int dist=0;
    qu.push(target);
    st.insert(target);

    while(!qu.empty())
    {
        if(dist==k)
        {
            while(!qu.empty())
            {
                cout<<qu.front()->data<<" ";
                qu.pop();
            }
        }

        int size = qu.size();
        for(int i=0; i<size; i++)
        {
            Node *q = qu.front();
            qu.pop();
            if(q->left and st.find(q->left)==st.end())
            {
                 qu.push(q->left);
                 st.insert(q->left);
            }
            if(q->right and st.find(q->right)==st.end())
            {
                 qu.push(q->right);
                 st.insert(q->right);
            }
            if(mp[q] and st.find(mp[q])==st.end())
            {
                qu.push(mp[q]);
                st.insert(mp[q]);
            }
        }
        dist++;
}
}
int main()
{
   Node *root = newNode(20);
   root->left = newNode(8);
   root->right = newNode(22);
   root->left->left = newNode(4);
   root->left->right = newNode(12);
   root->left->right->left = newNode(10);
   root->left->right->right = newNode(14);

   StoreParent(root);
   Node *target = root->left;
   PrintNode(root, target, 2);
   return 0;
}
