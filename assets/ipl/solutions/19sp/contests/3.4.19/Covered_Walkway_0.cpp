#include<bits/stdc++.h>
using namespace std;
const long long int INF = 4e18;//0x7FFFFFFFFFFFFFFF;
long long int dp[1001],pos[1001];

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   long long int n,c;
   cin>>n>>c;
   for(int i=1;i<=n;i++)
      cin>>pos[i];
   for(int i=0;i<=n;i++)
      dp[i]=INF;
   dp[0]=0;
   for(int i=1;i<=n;i++)
      for(int j=0;j<i;j++)
         dp[i]=min(dp[i],dp[j]+c+(pos[i]-pos[j+1])*(pos[i]-pos[j+1]));
   cout<<dp[n]<<endl;
}
