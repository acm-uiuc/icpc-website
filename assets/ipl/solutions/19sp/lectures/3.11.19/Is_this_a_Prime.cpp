#include<bits/stdc++.h>
using namespace std;

int main(){
   long long int n;
   cin>>n;
   for(int i=2;i<=sqrt(n);i++)
      if(n%i==0){
         cout<<"Not Prime"<<endl;
         return 0;
      }
   cout<<"Prime"<<endl;
}
