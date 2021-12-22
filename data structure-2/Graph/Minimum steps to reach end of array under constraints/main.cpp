/*Given an array containing one digit numbers only, assuming we are standing at first index, we need to reach to end of array using minimum number of steps
 where in one step, we can jump to neighbor indices or can jump to a position with same value.

In other words, if we are at index i, then in one step you can reach to, arr[i-1] or arr[i+1] or arr[K] such that arr[K] = arr[i] (value of arr[K] is same as arr[i])*/

#include <bits/stdc++.h>
using namespace std;

int minSteps(int arr[], int N)
{
    queue<int> qu;
    vector<int> digit[10];
    int distance[N];
    bool visited[N];
    memset(visited, false, sizeof(visited));

    distance[0]=0;
    qu.push(0);
    visited[0]=true;

    for(int i=1; i<N; i++)
    {
        digit[arr[i]].push_back(i);
    }

    while(!qu.empty())
    {
        int idx = qu.front();
        qu.pop();

        if(idx==N-1)
            break;
        int d = arr[idx];
        for(int i=0; i<digit[d].size(); i++)
        {
            int nextidx = digit[d][i];
            if(!visited[nextidx])
            {
                visited[nextidx]=true;
                distance[nextidx] = distance[idx]+1;
                qu.push(nextidx);
            }
        }
        digit[idx].clear();

        if(idx>0 and !visited[idx-1])
        {
            visited[idx-1]=true;
            distance[idx-1] = distance[idx]+1;
            qu.push(idx-1);
        }

        if(idx+1<N and !visited[idx+1])
        {
            visited[idx+1]=true;
            distance[idx+1] = distance[idx]+1;
            qu.push(idx+1);
        }
    }
    return distance[N-1];
}
int main()
{
     int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 5,
                 4, 3, 6, 0, 1, 2, 3, 4, 5, 7};
     int N = sizeof(arr)/sizeof(arr[0]);

    cout<<minSteps(arr, N);
    return 0;
}
