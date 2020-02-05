#include<bits/stdc++.h>
using namespace std;
bool isprime[1000001];
void Sieve_of_E(bool isprime[],int n){
  for(int i=2;i<=n;i++)
    isprime[i]=true;
  for(long long int i=2;i<=n;i++)
    if(isprime[i])
        for(long long int j=i*i;j<=n;j+=i)
          isprime[j]=false;
}

int main(){
   int n;
   cin>>n;
   Sieve_of_E(isprime,n);
   int ans=0;
   for(int i=2;i<=n;i++)
      if(isprime[i])
         ans++;
   cout<<ans<<endl;
}
