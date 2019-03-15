#include<bits/stdc++.h>
using namespace std;
int n,W;
int w[101],v[101];
int dp[10001];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cin>>n>>W;
   for(int i=1;i<=n;i++)
      cin>>w[i]>>v[i];
   for(int i=1;i<=10000;i++)
      dp[i]=1e9+10;
   for(int i=1;i<=n;i++)
      for(int j=10000-v[i];j>=0;j--)
         dp[j+v[i]]=min(dp[j+v[i]],dp[j]+w[i]);
   for(int i=10000;i>=0;i--){
      if(dp[i]<=W){
         cout<<i<<endl;
         return 0;
      }
   }
}
