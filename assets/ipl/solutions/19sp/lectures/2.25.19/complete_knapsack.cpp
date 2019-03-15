#include<bits/stdc++.h>
using namespace std;
int w[1001],v[1001],W,n;
int dp[1001];
int main(){
   cin>>n>>W;
   for(int i=1;i<=n;i++)
      cin>>w[i]>>v[i];
   for(int i=1;i<=n;i++)
      for(int j=w[i];j<=W;j++)
         dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
   cout<<dp[W]<<endl;
}
