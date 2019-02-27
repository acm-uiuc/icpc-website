#include<bits/stdc++.h>
using namespace std;
long long int dp[1000005];
int a[1000005];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    dp[i]=10000000000000LL;
  }
  dp[1]=0;
  for(int i=1;i<=n;i++){
    dp[i+2]=min(dp[i]+abs(a[i+2]-a[i]),dp[i+2]);
    dp[i+1]=min(dp[i]+abs(a[i+1]-a[i]),dp[i+1]);
  }
  cout<<dp[n]<<endl;
}
