//using recursion method
#include <bits/stdc++.h>
using namespace std;

bool ispresent(string str)
{
    string dictionary[]={"mobile","samsung","sam","sung",
                            "man","mango","icecream","and",
                             "go","i","like","ice","cream"};
   int n=sizeof(dictionary)/sizeof(dictionary[0]);
   for(int i=0;i<n;i++)
   {
       if(dictionary[i].compare(str)==0)
        return true;
   }
   return false;
}
void wordbreak(string str,string out)
{
      int l=str.length();
      if(l==0)    //base case
        {
            cout<<out<<" "<<endl;
            return;
        }

      for(int i=1;i<=l;i++)
      {
          if(ispresent(str.substr(0,i)))
          {
              string prefix=str.substr(0,i);
              wordbreak(str.substr(i,l-i),out+" "+prefix);
          }
      }
}
int main()
{
    cout<<"\n1st string:\n";
   wordbreak("ilikesamsung"," ");

   cout<<"\n2nd string:\n";
   wordbreak("iiiiiiii"," ");

   cout<<"\n3rd string:\n";
   wordbreak(""," ");

   cout<<"\n4th string:\n";
   wordbreak("ilikelikeimangoiii"," ");

   cout<<"\n5th string:\n";
   wordbreak("samsungandmangok"," ");
   return 0;
}
