#include<bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin>>n;
   int x=n;
   for(int i=2;i<=round(sqrt(n));i++)
      while(x%i==0){
         cout<<i<<" ";
         x/=i;
      }
   if(x!=1)
      cout<<x;
   cout<<endl;
}
