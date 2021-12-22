#include <bits/stdc++.h>
using namespace std;

void NGE(int arr[], int n)
{
      stack<int> s;
      s.push(arr[0]);

      for(int i=1; i<n; i++)
      {
          if(s.empty())
          {
              s.push(arr[i]);
              continue;
          }

        while(!s.empty() and arr[i]> s.top())
        {
            cout<<arr[i]<<" ";
            s.pop();
        }

        s.push(arr[i]);
      }
      while(!s.empty())
      {
          cout<<"-1"<<" ";
          s.pop();
      }
}

int main()
{
     int arr[] = {4, 5, 2, 25};
     int n = sizeof(arr)/sizeof(arr[0]);

     NGE(arr, n);
     return 0;
}
