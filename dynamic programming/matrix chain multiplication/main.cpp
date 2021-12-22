#include <bits/stdc++.h>
using namespace std;


int matrix_c_multiplication(int p[],int n)
{
    int m[n-1][n-1]={0};
    int s[n-1][n-1]={0};

    for(int d=1;d<n-1;d++)
    {
        for(int i=0;i<n-d-1;i++)
        {
            int j=i+d;
            int min=INT_MAX;
            for(int k=i;k<j;k++)
            {
                int q=m[i][k]+m[k+1][j]+ p[i]*p[k+1]*p[j+1];
                if(q<min)
                {
                    min=q;
                    s[i][j]=k;
                }
                m[i][j]=min;
            }
        }
    }
    return m[0][n-2];
}
int main()
{
    int p[] = {1, 2, 3, 4};
    int n=sizeof(p)/sizeof(p[0]);
    cout<<"\n min cost is: "<<matrix_c_multiplication(p,n);
    return 0;
}
