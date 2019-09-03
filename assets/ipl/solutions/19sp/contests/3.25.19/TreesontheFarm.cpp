#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
  long long int n,m,ans1,ans2;
  cin>>n>>m;
  if(n&1)
     ans1=((n+1)*(n)*(n-1)/24)%mod*(n-2)%mod;
  else
     ans1=((n)*(n-1)*(n-2)/24)%mod*(n+1)%mod;
  if(m&1)
     ans2=((m+1)*(m)*(m-1)/24)%mod*(m-2)%mod;
  else
     ans2=((m)*(m-1)*(m-2)/24)%mod*(m+1)%mod;
  cout<<ans1*ans2%mod<<endl;
}
