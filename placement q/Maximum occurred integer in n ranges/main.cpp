/*This is the trickiest question when it is said to do it in O(1) extra space;
  There are 1 naieve approach with O(n2) time complaxity and 1 optimised approach with O(n) time and O(n) space
  complaxity( using hashing and counting the freq of each element and printing them).

  This one is the best approach


Algorithm 3: O(n) time and O(1) space
1. Reduce all elements by 1 so that the elements are converted in the range 0 to n-1.
2. Traverse the input array and for i = 0 to n-1, add n to element at index (input[i]%n). After all the elements are completed,
element at index i will be increment by n*k where k is the number of times i occurs in the array.
3. Finally, print counts of elements. Count of i+1 will be input[i]/n.
Reason:
Element at index i will be equal to input[i] + n*k where k is the number of times i occurs in the array.
On dividing by n, we get: (input[i] + n*k)/n = input[i]/n + (n*k)/n = 0 + k = k = the number of times i occurs in the array
As initially, all elements were reduced by 1, so this is count of i+1.
4. Traverse input array once and set input[i] = input[i]%n+1 to get original array.

*/
#include <bits/stdc++.h>
using namespace std;

void CountFreq(int arr[], int n)
{
    for(int i=0; i<n; i++)
        arr[i] = arr[i]-1;

    for(int i=0; i<n; i++)
    {
        arr[arr[i]%n]+=n;
    }

    for(int i=0; i<n; i++)
    {
        cout<<"\nFrequency of "<<i+1<<" is "<<arr[i]/n;
        arr[i] = arr[i]%n +1;
    }
}

int main()
{
   int arr[] = { 2, 3, 3, 2, 5 };
   int n = sizeof(arr)/sizeof(arr[0]);

   CountFreq(arr, n);
   return 0;
}
