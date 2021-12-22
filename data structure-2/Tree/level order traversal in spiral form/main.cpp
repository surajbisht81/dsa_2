#include <bits/stdc++.h>
using namespace std;

// using O(n^2) time complaxity
struct node
{
     int data;
    struct node* left;
    struct node* right;
};
struct node* newNode(int data)
{
    struct node* node = (struct node*)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}
int getheight(node *root)
{
    if(!root)
    return 0;

    int l = getheight(root->left);
    int r = getheight(root->right);
    return max(l, r)+1;
}

void rightToleft(node *root, int level)
{
    if(!root)
    return;
    if(level==1)
    cout<<root->data<<" ";

    if(level>1)
    {
        rightToleft(root->right, level-1);
        rightToleft(root->left, level-1);
    }
}

void leftToright(node *root, int level)
{
    if(!root)
    return;
    if(level==1)
    cout<<root->data<<" ";

    if(level>1)
    {
        leftToright(root->left, level-1);
        leftToright(root->right, level-1);
    }
}
void printSpiral(node *root)
{
    int level=1;
    int i=1;
    int height = getheight(root);

    while(height--)
    {
        if(i==1)
        {
            rightToleft(root, level);
            level++;
            i=0;
        }
        else
        {
            leftToright(root, level);
            level++;
            i=1;
        }
    }
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);

    printSpiral(root);
    return 0;
}

/* second method using stack O(n) space and O(n) time complaxity

void printSpiral(struct node* root)
{
    if (root == NULL)
        return; // NULL check

    // Create two stacks to store alternate levels
    stack<struct node*> s1; // For levels to be printed from right to left
    stack<struct node*> s2; // For levels to be printed from left to right

    // Push first level to first stack 's1'
    s1.push(root);

    // Keep printing while any of the stacks has some nodes
    while (!s1.empty() || !s2.empty()) {
        // Print nodes of current level from s1 and push nodes of
        // next level to s2
        while (!s1.empty()) {
            struct node* temp = s1.top();
            s1.pop();
            cout << temp->data << " ";

            // Note that is right is pushed before left
            if (temp->right)
                s2.push(temp->right);
            if (temp->left)
                s2.push(temp->left);
        }

        // Print nodes of current level from s2 and push nodes of
        // next level to s1
        while (!s2.empty()) {
            struct node* temp = s2.top();
            s2.pop();
            cout << temp->data << " ";

            // Note that is left is pushed before right
            if (temp->left)
                s1.push(temp->left);
            if (temp->right)
                s1.push(temp->right);
        }
    }
}
*/
