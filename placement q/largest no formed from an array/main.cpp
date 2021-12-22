#include <bits/stdc++.h>
using namespace std;

/*void largestNo(int arr[], int n)
{
    string str=" ";

    for(int i=0; i<n-1; i++)
    {
      for(int j=i+1; j<n; j++)
      {
         string A = to_string(arr[i]);
         string B = to_string(arr[j]);

         if( A+B >  B+A)
            continue;
         else
            swap(arr[i], arr[j]);
      }
      str = str+to_string(arr[i]);
    }
    str += to_string(arr[n-1]);

    cout<<str;
}
int main()
{
    int arr[] = {3, 30, 34, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    largestNo(arr, n);
    return 0;
}*/

bool comp(string first, string second)
{
    string one = first+second;
    string two = second+first;

    int i=0;
    while(one[i] && two[i])
    {
        if(one[i]>two[i])
            return true;
        else if(one[i]<two[i])
            return false;
        i++;
    }
    return false;
}
void largestNo(string arr[], int n)
{
   sort(arr, arr+n, comp);

   for(int i=0; i<n; i++)
     cout<<arr[i];

}
int main()
{
    string arr[] = {"3", "30", "34", "9"};
    int n = sizeof(arr)/sizeof(arr[0]);

    largestNo(arr, n);
    return 0;
}
